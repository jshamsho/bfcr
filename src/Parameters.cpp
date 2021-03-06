#include "Parameters.h"

Parameters::Parameters(Data& dat) {
  lambda = arma::cube(dat.basis_dim, dat.d2, dat.kdim, arma::fill::randn);
  beta = arma::mat(dat.basis_dim, dat.d1, arma::fill::randn);
  eta = arma::mat(dat.n, dat.kdim, arma::fill::randn);
  varphi = 100 * arma::vec(dat.n, arma::fill::ones);
  psi = arma::vec(dat.n, arma::fill::ones);
  tau_a = -.5;
  tau_b = 0;
  varphi_a = .0001;
  varphi_b = .0001;
  alpha = 1;
  tausq = 1;
  tau1 = arma::vec(dat.penalties_mean.n_elem, arma::fill::ones);
  tau2 = arma::mat(dat.penalties_var.n_elem, dat.kdim, arma::fill::ones);
  tau1.fill(1000);
  tau2.fill(1000);
  phi = arma::cube(dat.basis_dim, dat.d2, dat.kdim, arma::fill::ones);
  delta = arma::mat(dat.n_smooths_var, dat.kdim, arma::fill::ones);
  a1 = arma::vec(dat.n_smooths_var, arma::fill::ones);
  a2 = arma::vec(dat.n_smooths_var, arma::fill::ones);
  beta_container = arma::cube(dat.basis_dim, dat.d1, dat.iter);
  lambda_container = arma::field<arma::cube>(dat.iter);
  eta_container = arma::cube(dat.n, dat.kdim, dat.iter);
  varphi_container = arma::mat(dat.n, dat.iter);
  tau1_container = arma::mat(dat.indices_mean.n_elem, dat.iter);
  tau2_container = arma::cube(dat.indices_var.n_elem, dat.kdim, dat.iter);
  phi_container = arma::field<arma::cube>(dat.iter);
  delta_container = arma::cube(dat.n_smooths_var, dat.kdim, dat.iter);
  tausq_container = arma::vec(dat.iter);
  a1_container = arma::mat(dat.n_smooths_var, dat.iter);
  a2_container = arma::mat(dat.n_smooths_var, dat.iter);
  tau1_delta_container = arma::mat(dat.indices_mean.n_elem, dat.iter);
  tau1_nu_container = arma::mat(dat.indices_mean.n_elem, dat.iter);
  tau2_delta_container = arma::cube(dat.indices_var.n_elem, dat.kdim, dat.iter);
  tau2_nu_container = arma::cube(dat.indices_var.n_elem, dat.kdim, dat.iter);
}

void Parameters::update_beta(Data& dat, Transformations& transf) {
  transf.beta_g = 
    arma::vectorise((transf.bty - transf.btb * transf.fit_lambda) *
    arma::diagmat(varphi) * dat.design_mean);
  transf.beta_precision = arma::kron(dat.design_mean.t() *
    arma::diagmat(varphi) * dat.design_mean, transf.btb) +
    transf.blk_diag_mean_penalties;
  if(!transf.beta_precision.is_symmetric()) {
    transf.beta_precision = arma::symmatu(transf.beta_precision);
  }
  transf.beta_result = 
    transf.beta_gauss.bayes_reg(transf.beta_precision, transf.beta_g);
  beta = arma::reshape(transf.beta_result, dat.basis_dim, dat.d1);
  transf.fit_beta = beta * dat.design_mean.t();
}

void Parameters::update_lambda(Data& dat, Transformations& transf) {
  arma::vec unif_vec = arma::randu(dat.kdim);
  arma::uvec sort_indices = arma::sort_index(unif_vec);
  arma::uword k;
  for (arma::uword kp = 0; kp < dat.kdim; kp++) {
    k = sort_indices(kp);
    transf.fit_lambda_removed = transf.fit_beta + 
      transf.fit_lambda - (lambda.slice(k) *
      dat.design_var.t() * arma::diagmat(eta.col(k)));
    
    
    transf.lambda_precision = 
      arma::kron(dat.design_var.t() * arma::diagmat(eta.col(k)) * 
      arma::diagmat(varphi) * 
      (dat.design_var.t() * arma::diagmat(eta.col(k))).t(),
      transf.btb) + transf.blk_diag_var_penalties.slice(k) +
        transf.blk_diag_phi_delta.slice(k);
    transf.lambda_g = arma::vectorise((transf.bty - 
      transf.btb * transf.fit_lambda_removed) * arma::diagmat(varphi) *
      arma::diagmat(eta.col(k)) * dat.design_var);
    if(!transf.lambda_precision.is_symmetric()){
      transf.lambda_precision = arma::symmatu(transf.lambda_precision);
    }
    transf.lambda_result = 
      transf.lambda_gauss.bayes_reg(transf.lambda_precision, transf.lambda_g);

    transf.lambda_old = lambda.slice(k);
    lambda.slice(k) = arma::reshape(transf.lambda_result, dat.basis_dim, dat.d2);
    transf.fit_lambda = transf.fit_lambda + 
      (lambda.slice(k) - transf.lambda_old) * dat.design_var.t() *
      arma::diagmat(eta.col(k));
  }
}

void Parameters::update_eta(Data& dat, Transformations& transf) {
  
  for (arma::uword subject = 0; subject < dat.n; subject++) {
    for (arma::uword k = 0; k < dat.kdim; k++) {
      transf.eta_transf.col(k) = lambda.slice(k) * dat.design_var.row(subject).t();
    }
    transf.eta_g = varphi(subject) * transf.eta_transf.t() * 
      (transf.bty.col(subject) - transf.btb * transf.fit_beta.col(subject));
    
    transf.eta_precision = varphi(subject) * transf.eta_transf.t() * 
      transf.btb * transf.eta_transf + 
      arma::eye<arma::mat>(dat.kdim, dat.kdim);
    
    if(!transf.eta_precision.is_symmetric()){
      transf.eta_precision = arma::symmatu(transf.eta_precision);
    }
    transf.eta_result = 
      transf.eta_gauss.bayes_reg(transf.eta_precision, transf.eta_g);
    eta.row(subject) = (transf.eta_result).t();
    
  }
  transf.fit_lambda.zeros();
  for (arma::uword k = 0; k < dat.kdim; k++) {
    transf.fit_lambda = transf.fit_lambda +
      lambda.slice(k) * 
      dat.design_var.t() * 
      arma::diagmat(eta.col(k));
  }
}

void Parameters::update_tau1(Data& dat, Transformations& transf) {
  double update_a = 0, update_b = 0;
  for(arma::uword i = 0; i < dat.penalties_mean.n_elem; i++){
    update_a = .5 * dat.rank_mean(i);
    update_b = .5 *
      arma::as_scalar(arma::vectorise(beta.cols(dat.seq_along_tau1(i, 0),
                                                dat.seq_along_tau1(i, 1))).t() *
      dat.penalties_mean(i) *
      arma::vectorise(beta.cols(dat.seq_along_tau1(i, 0),
                                dat.seq_along_tau1(i, 1))));
    tau1(i) = R::rgamma(tau_a + update_a, 1.0 / (tau_b + update_b));
  }
  transf.build_blk_diag_mean(dat, *this);
}

void Parameters::update_tau2(Data& dat, Transformations& transf) {
  double update_a = 0, update_b = 0;
  for(arma::uword i = 0; i < dat.penalties_var.n_elem; i++){
    for (arma::uword k = 0; k < dat.kdim; k++) {
      update_a = .5 * dat.rank_var(i);
      update_b = .5 *
        arma::as_scalar(arma::vectorise(lambda.slice(k).cols(
            dat.seq_along_tau2(i, 0), dat.seq_along_tau2(i, 1))).t() *
        dat.penalties_var(i) * arma::vectorise(lambda.slice(k).cols(
            dat.seq_along_tau2(i, 0), dat.seq_along_tau2(i, 1))));
      tau2(i, k) = R::rgamma(tau_a + update_a, 1.0 / (tau_b + update_b));
    }
  }
  transf.build_blk_diag_var(dat, *this);
}

void Parameters::update_varphi(Data& dat, Transformations& transf) {
  transf.fit = transf.fit_beta + transf.fit_lambda;
  double my_sum = arma::accu(arma::square(dat.response - 
                             arma::trans(dat.basis * (transf.fit))));
  double p = R::rgamma(varphi_a + dat.response.n_elem/2, 1.0 / 
                       (varphi_b + 1.0/2.0 * my_sum));
  varphi.fill(p);
}

void Parameters::update_phi(Data& dat, Transformations& transf) {
  for (arma::uword i = 0; i < dat.basis_dim; i++) {
    for (arma::uword j = 0; j < dat.d2; j++) {
      for (arma::uword k = 0; k < dat.kdim; k++) {
        phi(i, j, k) = 
          R::rgamma(phi_a + .5, 1.0 / (phi_b + 
          .5 * transf.delta_cumprod(dat.seq_along_elongated(j), k) * 
          ::pow(lambda(i, j, k), 2)));
      }
    }
  }
}

void Parameters::update_delta(Data& dat, Transformations& transf) {
  double update_a = 0, update_b = 0;
   for (arma::uword k = 0; k < dat.kdim; k++) {
    for(arma::uword i = 0; i < dat.n_smooths_var; i++){
      transf.phi_lambda_sum(i, k) = arma::as_scalar(
        arma::accu(arma::square(lambda.slice(k).cols(
            dat.seq_along_start_delta(i), dat.seq_along_end_delta(i))) %
          phi.slice(k).cols(
              dat.seq_along_start_delta(i), dat.seq_along_end_delta(i))));
    }
  }
  for (arma::uword i = 0; i < dat.n_smooths_var; i++) {
    for (arma::uword k = 0; k < dat.kdim; k++) {
      
      transf.delta_cumprod.row(i)(k) = 1;
      for (arma::uword kp = 0; kp < k; kp++) {
        transf.delta_cumprod.row(i)(kp) = 0;
      }
      update_b = delta_b + .5 * arma::as_scalar(arma::accu(
        transf.delta_cumprod.row(i).t() % transf.phi_lambda_sum.row(i).t()));
      update_a = a2(i);
      if (k == 0) update_a = a1(i);
      update_a = update_a + dat.basis_dim * 
        (dat.seq_along_end_delta(i) - dat.seq_along_start_delta(i) + 1) * 
        (dat.kdim - k) / 2;
      delta(i, k) = R::rgamma(update_a, 1.0 / update_b);
      transf.delta_cumprod.row(i) = arma::cumprod(delta.row(i));
    }
  }
  transf.build_blk_diag_phi_delta(dat, *this);
}

void Parameters::update_psi(Data& dat, Transformations& transf){
  transf.fit = transf.fit_beta + transf.fit_lambda;
  transf.squared_diff = arma::sum(arma::square(dat.response - 
    arma::trans(dat.basis * (transf.fit))), 1);
  double update_a = 0;
  double update_b = 0;
  double psi_a = nu / 2;
  double psi_b = nu * tausq / 2;
  update_a = dat.basis.n_rows / 2;
  for (arma::uword i = 0; i < dat.n; i++) {
    update_b = alpha * transf.squared_diff(i) / 2;
    psi(i) = R::rgamma(update_a + psi_a, 1 / update_b + psi_b);
  }
}

void Parameters::update_tausq(Data& dat, Transformations& transf) {
  tausq = R::rgamma(dat.n * nu / 2, 1.0 / (nu / 2 * arma::accu(psi)));
}

void Parameters::update_alpha(Data& dat, Transformations& transf) {
  double update_a = dat.response.n_elem / 2;
  double update_b = arma::accu(transf.squared_diff % psi) / 2;
  alpha = R::rgamma(update_a, 1 / update_b);
}

void Parameters::update_a1(Data& dat) {
  for (arma::uword i = 0; i < dat.n_smooths_var; i++) {
    double proposal = get_proposal(a1(i));
    double log_ratio = 
      R::dgamma(delta.row(i)(0), proposal, 1, 1) +
      R::dgamma(proposal, a1_a, 1, 1) +
      R::pnorm(a1(i), 0, 1, 1, 1) -
      R::dgamma(delta.row(i)(0), a1(i), 1, 1) -
      R::dgamma(a1(i), a1_a, 1, 1) -
      R::pnorm(proposal, 0, 1, 1, 1);
    if (R::runif(0.0, 1.0) < exp(log_ratio)) a1(i) = proposal;
  }
}


void Parameters::update_a2(Data& dat) {
  for (arma::uword i = 0; i < dat.n_smooths_var; i++) {
    double proposal = get_proposal(a2(i));
    Rcpp::NumericVector delta_tail = 
      Rcpp::wrap(delta.row(i).tail(dat.kdim - 1));
    double log_ratio = 
      Rcpp::sum(Rcpp::dgamma(delta_tail, proposal, 1, 1)) +
      R::dgamma(proposal, a2_a, 1, 1) +
      R::pnorm(a2(i), 0.0, 1.0, 1, 1) - 
      Rcpp::sum(Rcpp::dgamma(delta_tail, a2(i), 1, 1)) - 
      R::dgamma(a2(i), a2_a, 1, 1) +
      R::pnorm(proposal, 0.0, 1.0, 1, 1);
    if (R::runif(0, 1) < exp(log_ratio)) a2(i) = proposal;
  }
}


