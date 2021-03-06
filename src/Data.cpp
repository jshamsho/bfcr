#include "Data.h"

arma::ivec get_rank(arma::field<arma::mat>& penalties);
arma::umat get_seq_along_repeated(int basis_dim,
                                  arma::field<arma::mat>& penalties,
                                  arma::uvec& indices);
arma::uvec get_seq_along_elongated(int basis_dim,
                                   arma::field<arma::mat>& penalties,
                                   arma::uvec& indices,
                                   arma::mat& design_var);
Rcpp::List Data::write_data() {
  return(Rcpp::List::create(Rcpp::Named("response", response),
                            Rcpp::Named("basis", basis),
                            Rcpp::Named("time", time),
                            Rcpp::Named("latent_dimension", kdim),
                            Rcpp::Named("missing_subjects", missing_sub),
                            Rcpp::Named("missing_time", missing_time),
                            Rcpp::Named("design_mean", design_mean),
                            Rcpp::Named("design_var", design_var)));
}

Data::Data(arma::mat& response, arma::mat& design_mean,
           arma::mat& design_var, arma::mat& basis,
           arma::vec& time,
           arma::field<arma::mat>& penalties_mean,
           arma::field<arma::mat>& penalties_var,
           arma::uvec& indices_mean, arma::uvec& indices_var,
           arma::uword kdim, arma::uword iter,
           arma::uword burnin, arma::uword thin) {
  d1 = design_mean.n_cols;
  d2 = design_var.n_cols;
  basis_dim = basis.n_cols;
  n = response.n_rows;
  n_smooths_mean = arma::size(arma::find_unique(indices_mean))(0);
  n_smooths_var = arma::size(arma::find_unique(indices_var))(0);
  this->response = response;
  this->design_mean = design_mean;
  this->design_var = design_var;
  this->basis = basis;
  this->time = time;
  this->penalties_mean = penalties_mean;
  this->penalties_var = penalties_var;
  this->indices_mean = indices_mean;
  this->indices_var = indices_var;
  this->kdim = kdim;
  this->iter = iter;
  this->burnin = burnin;
  this->thin = thin;
  missing = arma::find_nonfinite(response);
  missing_sub = armadillo_modulus(missing, response.n_rows);
  missing_time = arma::floor(missing / response.n_rows);
  this->response.elem(missing).fill(0);
  seq_along_start_delta = arma::uvec(n_smooths_var);
  seq_along_end_delta = arma::uvec(n_smooths_var);
  seq_along_tau1 = get_seq_along_tau(penalties_mean,
                                                indices_mean);
  seq_along_tau2 = get_seq_along_tau(penalties_var,
                                                indices_var);

  seq_along_elongated = get_seq_along_elongated(basis_dim,
                                                penalties_var,
                                                indices_var,
                                                design_var);
  int old_index = -1;
  int start = 0;
  int end = -1;
  arma::uword counter = 0;
  seq_along_start_delta(0) = start;
  seq_along_end_delta(0) = end;
  rank_mean = get_rank(penalties_mean);
  rank_var = get_rank(penalties_var);

  for (arma::uword i = 0; i < penalties_var.n_elem; i++) {
    if (indices_var(i) != old_index) {
      end = end + penalties_var(i).n_rows / basis_dim;
      seq_along_start_delta(counter) = start;
      seq_along_end_delta(counter) = end;
      start = end + 1;
      counter++;
    }
    old_index = indices_var(i);
  }
}


arma::umat Data::get_seq_along_tau(arma::field<arma::mat>& penalties,
                                   arma::uvec& indices) {
  arma::umat seq_along_tau(penalties.n_elem, 2);
  arma::uword start = 0;
  arma::uword end = penalties(0).n_rows / basis_dim - 1;
  arma::uword old_index = 1;
  for (arma::uword i = 0; i < penalties.n_elem; i++) {
    if (old_index != indices(i)) {
      start = end + 1;
      end = end + penalties(i).n_rows / basis_dim;
    }
    old_index = indices(i);
    seq_along_tau(i, 0) = start;
    seq_along_tau(i, 1) = end;
  }
  return seq_along_tau;
}
arma::uvec get_seq_along_elongated(int basis_dim,
                               arma::field<arma::mat>& penalties,
                               arma::uvec& indices,
                               arma::mat& design_var) {
  arma::uvec elongated(design_var.n_cols);
  int start = 0;
  int old_index = 0;
  int end = -1;
  arma::uword counter = 0;
  for (arma::uword i = 0; i < penalties.n_elem; i++) {
    if (old_index != indices(i)) {
      end = end + penalties(i).n_rows / basis_dim;
      elongated.rows(start, end) = counter *
        arma::ones<arma::uvec>(end - start + 1);
      start = end + 1;
      counter++;
    }
    old_index = indices(i);
  }
  return(elongated);
}
arma::ivec get_rank(arma::field<arma::mat>& penalties) {
  arma::ivec rank_vec(penalties.n_elem);
  for (arma::uword i = 0; i < penalties.n_elem; i++) {
    rank_vec(i) = arma::rank(penalties(i));
  }
  return(rank_vec);
}
