#include <RcppArmadillo.h>
#include "Utility.h"
#ifdef _OPENMP
 #include <omp.h>
#endif
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(openmp)]]
using namespace Rcpp;
arma::mat fitEM;
// [[Rcpp::export]]
void cppgetX(arma::mat &EtaM, arma::cube &EtaV, arma::mat &X, arma::mat &newX, int cores = 1){
  arma::uword K = EtaV.n_rows;
  arma::uword D = X.n_cols;
  arma::uword n = X.n_rows;
  for(arma::uword i = 0; i < n; i++){
    for(arma::uword k = 0; k < K; k++){
      if(k == 0){
        newX.row(i).cols(0, D - 1) = X.row(i);
      }
      newX.row(i).cols(k * D + D, (k + 1) * D + D - 1) = EtaM(k, i) * X.row(i);
    }
  }
  arma::uvec myseq = arma::linspace<arma::uvec>(n, n * (1 + K), n + 1);
  // arma::vec eigval;
  // arma::mat eigmat;
  // arma::mat E;
  // arma::mat V;
  // for(arma::uword i = 0; i < n; i++){
  //   arma::eig_sym(eigval, eigmat, EtaV.slice(i));
  //   //E = arma::diagmat(arma::norm(X.row(i)) * arma::sqrt(eigval));
  //   eigval = arma::reverse(eigval);
  //   eigmat = arma::reverse(eigmat, 1);
  //   
  //   E = ::pow(arma::as_scalar(X.row(i) * arma::trans(X.row(i))),.5) * arma::diagmat(arma::sqrt(eigval));
  //   V = arma::kron(eigmat, ::pow(arma::as_scalar(X.row(i) * arma::trans(X.row(i))),-.5) * X.row(i));
  //   newX.submat(myseq(i), D, myseq(i+1)-1, (K+1) * D - 1) =  E * V;
  // 
  // }
  for(arma::uword i = 0; i < n; i++){
    newX.submat(myseq(i), D, myseq(i+1)-1, (K+1) * D - 1) = arma::kron(arma::chol(EtaV.slice(i), "upper"), X.row(i));
  }
}
// [[Rcpp::export]]
void cppupdateall(arma::mat &Theta, arma::mat &Lambda, arma::vec &precision,
                  arma::mat &newX, arma::mat &B, arma::mat &newY, arma::uword K){
  arma::uword n = newX.n_rows / (K + 1);
  arma::uword D = newX.n_cols / (K + 1);
  arma::uword tmax = B.n_rows;
  arma::mat C = arma::solve(arma::trans(B) * B, arma::trans(B) * arma::trans(arma::solve(arma::trans(newX) * newX, arma::trans(newX) * newY, arma::solve_opts::likely_sympd)), arma::solve_opts::likely_sympd);
  precision(0) = (double(n) * double(tmax)) / arma::trace(arma::trans(newY - newX * arma::trans(C) * arma::trans(B)) * ((newY - newX * arma::trans(C) * arma::trans(B))));
  Theta = C.cols(0, D - 1); 
  Lambda = C.cols(D, C.n_cols - 1);
}

// [[Rcpp::export]]
void cppupdateall_Proj(arma::mat &Theta, arma::mat &Lambda, arma::vec &Phi,
                  arma::mat &newX, arma::mat &newY, arma::uword K){
  arma::uword n = newX.n_rows / (K + 1);
  arma::uword D = newX.n_cols / (K + 1);
  arma::mat C = arma::solve(arma::trans(newX) * newX, arma::trans(newX) * newY, arma::solve_opts::likely_sympd).t();
  arma::mat Temp = 1.0 / double(n)  * (arma::trans(newY - newX * C.t()) * ((newY - newX * C.t())));
  Phi =  Temp.diag();
  Theta = C.cols(0, D - 1); 
  Lambda = C.cols(D, C.n_cols - 1);
}

// [[Rcpp::export]]
void cppupdateeta(arma::mat &Theta, arma::mat &Lambda, arma::vec &precision, arma::mat &EtaM, arma::cube &EtaV, arma::mat &X, arma::mat &B, arma::mat &Y, double K){
  arma::uword n = Y.n_rows;
  arma::uword D = X.n_cols;
  arma::mat Ltilde(Lambda.n_rows, K);
  for(arma::uword i = 0; i < n; i++){
    Ltilde.zeros();
    for(arma::uword k = 0; k < K; k++){
      Ltilde.col(k) = Lambda.cols(D * k, D * (k + 1) - 1) * arma::trans(X.row(i));
    }
    
    EtaV.slice(i) = arma::inv_sympd(arma::eye<arma::mat>(K, K) + precision(0) * arma::trans(Ltilde) * arma::trans(B) * B * Ltilde);
    EtaM.col(i) = arma::as_scalar(precision(0)) * EtaV.slice(i) * arma::trans(Ltilde) * arma::trans(B) * (arma::trans(Y.row(i)) - B * Theta * arma::trans(X.row(i)));
  }
}

// [[Rcpp::export]]
void cppupdateeta_Proj(arma::mat &Theta, arma::mat &Lambda, arma::vec &Phi, arma::mat &EtaM, arma::cube &EtaV, arma::mat &X, arma::mat &Y, double K){
  arma::uword n = Y.n_rows;
  arma::uword D = X.n_cols;
  arma::mat Ltilde(Lambda.n_rows, K);
  for(arma::uword i = 0; i < n; i++){
    Ltilde.zeros();
    for(arma::uword k = 0; k < K; k++){
      Ltilde.col(k) = Lambda.cols(D * k, D * (k + 1) - 1) * arma::trans(X.row(i));
    }
    
    EtaV.slice(i) = arma::inv_sympd(arma::eye<arma::mat>(K, K) +  arma::trans(Ltilde) * arma::inv(arma::diagmat(Phi)) * Ltilde);
    EtaM.col(i) = EtaV.slice(i) * arma::trans(Ltilde) * arma::inv_sympd(arma::diagmat(Phi)) * (arma::trans(Y.row(i)) - Theta * arma::trans(X.row(i)));
  }
}
// [[Rcpp::export]]
double cpploglik(arma::mat &Theta, arma::mat &Lambda, arma::vec &precision,
                 arma::mat &X, arma::mat &B, arma::mat &Y, arma::uword K, int cores = 1){
  
  arma::uword n = Y.n_rows;
  arma::uword D = X.n_cols;
  arma::uword tmax = Y.n_cols;
  arma::uword p = Lambda.n_rows;
  
  double loglik = 0;
  double constants = -double(tmax) / 2 * log(2 * PI);
#ifdef _OPENMP
  omp_set_num_threads(cores);
#pragma omp parallel for reduction(+:loglik)
#endif
  for(arma::uword i = 0; i < n; i++){
    arma::vec mean(tmax);
    arma::mat cov(tmax, tmax);
    arma::mat LambdaCov = arma::zeros<arma::mat>(p, p);
    arma::mat precisionmat = 1/precision(0) * arma::eye<arma::mat>(tmax, tmax);
    arma::mat rooti;
    double rootisum;
    arma::mat rootsum;
    arma::vec z;
    for(arma::uword k = 0; k < K; k++){
      LambdaCov = Lambda.cols(D * k, D * (k + 1) - 1) * arma::trans(X.row(i)) * X.row(i) *
        arma::trans(Lambda.cols(D * k, D * (k + 1) - 1)) + LambdaCov;
    }
    mean = B * Theta * arma::trans(X.row(i));
    cov = B * LambdaCov * arma::trans(B) + precisionmat;
    LambdaCov.zeros();
    rooti = arma::trans(arma::inv(trimatu(arma::chol(cov))));
    rootisum = arma::sum(log(rooti.diag()));
    z = rooti * arma::trans(Y.row(i) - arma::trans(mean));
    loglik = constants - 0.5 * arma::sum(z % z) + rootisum + loglik;
  }
  
  return(loglik);
}

// [[Rcpp::export]]
double cpploglik_Proj(arma::mat &Theta, arma::mat &Lambda, arma::vec &Phi,
                 arma::mat &X, arma::mat &Y, arma::uword K, int cores = 1){
  
  arma::uword n = Y.n_rows;
  arma::uword D = X.n_cols;
  arma::uword p = Y.n_cols;
  
  double loglik = 0;
  double constants = -double(p) / 2 * log(2 * PI);
#ifdef _OPENMP
  omp_set_num_threads(cores);
#pragma omp parallel for reduction(+:loglik)
#endif
  for(arma::uword i = 0; i < n; i++){
    
    arma::vec mean(p);
    arma::mat cov(p, p);
    arma::mat LambdaCov = arma::zeros<arma::mat>(p, p);
    arma::mat rooti;
    double rootisum;
    arma::mat rootsum;
    arma::vec z;
    for(arma::uword k = 0; k < K; k++){
      LambdaCov = Lambda.cols(D * k, D * (k + 1) - 1) * arma::trans(X.row(i)) * X.row(i) *
        arma::trans(Lambda.cols(D * k, D * (k + 1) - 1)) + LambdaCov;
    }
    mean = Theta * arma::trans(X.row(i));
    

    cov = LambdaCov + arma::diagmat(Phi);
    
    LambdaCov.zeros();
    rooti = arma::trans(arma::inv(trimatu(arma::chol(cov))));
    rootisum = arma::sum(log(rooti.diag()));
    z = rooti * arma::trans(Y.row(i) - arma::trans(mean));
    loglik = constants - 0.5 * arma::sum(z % z) + rootisum + loglik;
  }
  return(loglik);
}

// [[Rcpp::export]]
void completeY2Means(arma::mat& Y, arma::uvec missing_sub, arma::uvec missing_time){
  for(arma::uword i = 0; i < missing_sub.n_elem; i++){
    Y(missing_sub(i), missing_time(i)) = fitEM(missing_sub(i), missing_time(i));
  }
}

// [[Rcpp::export]]
Rcpp::List cpp_EM2(arma::mat X, arma::mat B, arma::mat Y, arma::uword K,
                   double tol, arma::uword max_iter){
  double conv = tol + 1;
  arma::uword p = B.n_cols;
  arma::uword D = X.n_cols;
  arma::uword n = Y.n_rows;
  arma::uword tmax = B.n_rows;
  arma::uvec missing = arma::find_nonfinite(Y);
  arma::uvec missing_sub = armadillo_modulus3(missing, Y.n_rows);
  arma::uvec missing_time = arma::floor(missing / Y.n_rows);
  arma::mat Ypred = Y;
  Ypred.elem(missing).fill(0);
  arma::mat newy = arma::zeros<arma::mat>((K + 1) * n, tmax);
  arma::mat newx = arma::zeros<arma::mat>((K + 1) * n, (K + 1) * D);
  arma::mat fit2;
  arma::mat pTheta = arma::randn<arma::mat>(p, D);
  arma::mat pLambda = arma::randn<arma::mat>(p, D * K);
  arma::mat pLambda_old = arma::randn<arma::mat>(p, D * K);
  arma::mat pEtaM = arma::randn<arma::mat>(K, n);
  arma::cube pEtaV = arma::cube(K, K, n);
  pEtaV.each_slice() = arma::eye<arma::mat>(K, K);
  arma::vec precision(1);
  precision(0) = 1;
  //cppgetX(pEtaM, pEtaV, X, newx);
  
  newy.rows(0, n - 1) = Ypred;
  for(arma::uword i = 0; i < max_iter; i++){
    if(missing.n_elem > 0){
      fitEM = X * pTheta.t() * B.t();
      for(arma::uword k = 0; k < K; k++){
        fitEM = fitEM + arma::diagmat(pEtaM.row(k)) * X * pLambda.cols(X.n_cols * k,
                                      X.n_cols * k + X.n_cols - 1).t() * B.t();
      }
      completeY2Means(Ypred, missing_sub, missing_time);
    }
    if(i == max_iter - 1){
      Rcout << "maximum number of iterations reached!" << std::endl;
    }
    cppupdateeta(pTheta, pLambda, precision, pEtaM, pEtaV, X, B, Ypred, K);
    cppgetX(pEtaM, pEtaV, X, newx);
    cppupdateall(pTheta, pLambda, precision, newx, B, newy, K);
    // if((i+1) % 100 == 0){
    //   Rcout << cpploglik(pTheta, pLambda, precision, X, B, Ypred, K) << std::endl;
    // }
    conv = arma::accu(arma::square(pLambda - pLambda_old)) /
      arma::accu(arma::square((pLambda_old)));
    Rcout << conv << std::endl;
    if(conv < tol){
      break;
    } else{
      pLambda_old = pLambda;
    }
  }
  arma::cube Lambda(pLambda.n_rows, X.n_cols, K);
  for(arma::uword k = 0; k < K; k++){
    Lambda.slice(k) = pLambda.cols(X.n_cols * k, X.n_cols * k + X.n_cols - 1);
  }
  return(Rcpp::List::create(Rcpp::Named("Lambda", Lambda),
                            Rcpp::Named("Theta", pTheta),
                            Rcpp::Named("precision", precision),
                            Rcpp::Named("Eta", pEtaM)));
}
// [[Rcpp::export]]
List cpp_EM(arma::mat X, arma::mat B, arma::mat Y, arma::uword K, arma::mat Theta_init, int cores = 1){
  arma::uword D = X.n_cols;
  arma::uword p = B.n_cols;
  arma::uword n = Y.n_rows;
  arma::uword tmax = B.n_rows;
  arma::mat pTheta = Theta_init;
  arma::mat pLambda = arma::randn<arma::mat>(p, D * K);
  arma::mat pEtaM = arma::randn<arma::mat>(K, n);
  arma::cube pEtaV = arma::cube(K, K, n);
  pEtaV.each_slice() = arma::eye<arma::mat>(K, K);
  arma::mat newx = arma::zeros<arma::mat>((K + 1) * n, (K + 1) * D);
  double inflation = 10;
  arma::vec precision(1);
  precision(0) = 1/std::pow(inflation, 2);
  //precision(0) = 1;
  arma::mat Yt = Y + inflation * arma::randn<arma::mat>(n, tmax);
  arma::mat Et;
  arma::mat newy = arma::zeros<arma::mat>((K + 1) * n, tmax);
  newy.rows(0, n - 1) = Yt;
  arma::uword i = 0;
  double loglik = cpploglik(pTheta, pLambda, precision, X, B, Yt, K);
  double logliknew;
  double delta;
  bool taco = true;
  bool myswitch = false;
  /*
  for(arma::uword i = 0; i < 100; i++){
  cppupdateeta(pTheta, pLambda, precision, pEtaM, pEtaV, X, B, Yt, K);
  cppgetX(pEtaM, pEtaV, X, newx, cores);
  cppupdateall(pTheta, pLambda, precision, newx, B, newy, K);
  if((i+1) % 10 == 0){
  loglik = cpploglik(pTheta, pLambda, precision, X, B, Yt, K, cores);
  
  }
  }
  */
  while(taco == true){
    cppupdateeta(pTheta, pLambda, precision, pEtaM, pEtaV, X, B, Yt, K);
    cppgetX(pEtaM, pEtaV, X, newx, cores);
    cppupdateall(pTheta, pLambda, precision, newx, B, newy, K);
    if((i+1) % 100 == 0){
      logliknew = cpploglik(pTheta, pLambda, precision, X, B, Yt, K, cores);
      delta = (logliknew - loglik)/std::abs(loglik);
      Rcpp::Rcout << "loglik: " << loglik << std::endl << "logliknew: " << logliknew << std::endl << "delta: " << delta << std::endl; 
      if(delta < 0){
        break;
      }
      Rcout << "Delta: " << delta << std::endl;
      Rcout << "Log-likelihood " << logliknew << std::endl;
      if(delta < 1e-8){
        if(myswitch == true){
          taco = false;
        }
        if(myswitch == false){
          inflation = .1 * inflation;
          Et = inflation * arma::randn<arma::mat>(n, tmax);
          Yt = Y + Et;
          newy.rows(0, n - 1) = Yt;
          myswitch = true;
        }
      }
      else {
        myswitch = false;
      }
      loglik = logliknew;
    }
    i = i + 1;
  }
  return(List::create(Named("Theta", pTheta), Named("Lambda", pLambda), Named("Precision", precision), Named("EtaM", pEtaM), Named("EtaV", pEtaV)));
}


// [[Rcpp::export]]
List cpp_EM_Proj(arma::mat X, arma::mat Y, arma::uword K, arma::mat Theta_init, int cores = 1){
  arma::uword D = X.n_cols;
  arma::uword n = Y.n_rows;
  arma::uword p = Y.n_cols;
  arma::mat pTheta = Theta_init;
  arma::mat pLambda = arma::randn<arma::mat>(p, D * K);
  arma::mat pEtaM = arma::randn<arma::mat>(K, n);
  arma::cube pEtaV = arma::cube(K, K, n);
  pEtaV.each_slice() = arma::eye<arma::mat>(K, K);
  arma::mat newx = arma::zeros<arma::mat>((K + 1) * n, (K + 1) * D);
  double inflation = 10;
  arma::vec Phi(p);
  Phi.ones();
  arma::mat Yt = Y + inflation * arma::randn<arma::mat>(n, p);
  arma::mat Et;
  arma::mat newy = arma::zeros<arma::mat>((K + 1) * n, p);
  newy.rows(0, n - 1) = Yt;
  arma::uword i = 0;
  
  double loglik = cpploglik_Proj(pTheta, pLambda, Phi, X, Yt, K, cores);
  
  double logliknew;
  double delta;
  bool taco = true;
  bool myswitch = false;
  /*
  for(arma::uword i = 0; i < 100; i++){
  cppupdateeta(pTheta, pLambda, precision, pEtaM, pEtaV, X, B, Yt, K);
  cppgetX(pEtaM, pEtaV, X, newx, cores);
  cppupdateall(pTheta, pLambda, precision, newx, B, newy, K);
  if((i+1) % 10 == 0){
  loglik = cpploglik(pTheta, pLambda, precision, X, B, Yt, K, cores);
  
  }
  }
  */
  
  while(taco == true){

    cppupdateeta_Proj(pTheta, pLambda, Phi, pEtaM, pEtaV, X, Yt, K);

    cppgetX(pEtaM, pEtaV, X, newx, cores);
    cppupdateall_Proj(pTheta, pLambda, Phi, newx, newy, K);

    if((i+1) % 100 == 0){
      logliknew = cpploglik_Proj(pTheta, pLambda, Phi, X, Yt, K, cores);
      delta = (logliknew - loglik)/std::abs(loglik);
      Rcpp::Rcout << "loglik: " << loglik << std::endl << "logliknew: " << logliknew << std::endl << "delta: " << delta << std::endl; 
      if(delta < 0){
        break;
      }
      Rcout << "Delta: " << delta << std::endl;
      Rcout << "Log-likelihood " << logliknew << std::endl;
      if(delta < 1e-8){
        if(myswitch == true){
          taco = false;
        }
        if(myswitch == false){
          inflation = .1 * inflation;
          Et = inflation * arma::randn<arma::mat>(n, p);
          Yt = Y + Et;
          newy.rows(0, n - 1) = Yt;
          myswitch = true;
        }
      }
      else {
        myswitch = false;
      }
      loglik = logliknew;
    }
    i = i + 1;
  }
  return(List::create(Named("Theta", pTheta), Named("Lambda", pLambda), Named("Phi", Phi), Named("EtaM", pEtaM), Named("EtaV", pEtaV)));
}

// [[Rcpp::export]]
List cpp_EM_new(arma::mat X, arma::mat B, arma::mat Y, arma::uword K, arma::mat Theta_init, arma::mat Lambda_init, int cores = 1){
  arma::uword D = X.n_cols;
  arma::uword p = B.n_cols;
  arma::uword n = Y.n_rows;
  arma::uword tmax = B.n_rows;
  arma::mat pTheta = Theta_init;
  arma::mat pLambda = arma::randn<arma::mat>(p, D * K);
  arma::mat pEtaM = arma::randn<arma::mat>(K, n);
  arma::cube pEtaV = arma::cube(K, K, n);
  pEtaV.each_slice() = arma::eye<arma::mat>(K, K);
  arma::mat newx = arma::zeros<arma::mat>((K + 1) * n, (K + 1) * D);
  arma::vec precision(1);
  precision(0) = 1;
  arma::mat newy = arma::zeros<arma::mat>((K + 1) * n, tmax);
  newy.rows(0, n - 1) = Y;
  arma::uword i = 0;
  double loglik = cpploglik(pTheta, pLambda, precision, X, B, Y, K);
  double logliknew;
  double delta;
  bool taco = true;

  while(taco == true){
    cppupdateeta(pTheta, pLambda, precision, pEtaM, pEtaV, X, B, Y, K);
    cppgetX(pEtaM, pEtaV, X, newx, cores);
    cppupdateall(pTheta, pLambda, precision, newx, B, newy, K);
    if(i % 1000 == 0){
      Rcpp::Rcout << "Theta(1,1) = " << pTheta(0,0) << std::endl;
      logliknew = cpploglik(pTheta, pLambda, precision, X, B, Y, K);
      Rcpp::Rcout << "Log-likelihood " << logliknew << std::endl;
      delta = (logliknew - loglik)/std::abs(loglik);
      Rcpp::Rcout << "Delta " << delta << std::endl;
    }
    if(delta < 1e-6){
      taco = false;
    } else{
      loglik = logliknew;
    }
    i = i + 1;
  }

  
  
  return(List::create(Named("Theta", pTheta), Named("Lambda", pLambda), Named("Precision", precision), Named("EtaM", pEtaM), Named("EtaV", pEtaV)));
}