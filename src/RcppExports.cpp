// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// cppgetX
void cppgetX(arma::mat& EtaM, arma::cube& EtaV, arma::mat& X, arma::mat& newX, int cores);
RcppExport SEXP _BayesianConditionalFPCA_cppgetX(SEXP EtaMSEXP, SEXP EtaVSEXP, SEXP XSEXP, SEXP newXSEXP, SEXP coresSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type EtaM(EtaMSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type EtaV(EtaVSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type newX(newXSEXP);
    Rcpp::traits::input_parameter< int >::type cores(coresSEXP);
    cppgetX(EtaM, EtaV, X, newX, cores);
    return R_NilValue;
END_RCPP
}
// cppupdateall
void cppupdateall(arma::mat& Theta, arma::mat& Lambda, arma::vec& precision, arma::mat& newX, arma::mat& B, arma::mat& newY, arma::uword K);
RcppExport SEXP _BayesianConditionalFPCA_cppupdateall(SEXP ThetaSEXP, SEXP LambdaSEXP, SEXP precisionSEXP, SEXP newXSEXP, SEXP BSEXP, SEXP newYSEXP, SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type precision(precisionSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type newX(newXSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type newY(newYSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type K(KSEXP);
    cppupdateall(Theta, Lambda, precision, newX, B, newY, K);
    return R_NilValue;
END_RCPP
}
// cppupdateeta
void cppupdateeta(arma::mat& Theta, arma::mat& Lambda, arma::vec& precision, arma::mat& EtaM, arma::cube& EtaV, arma::mat& X, arma::mat& B, arma::mat& Y, double K);
RcppExport SEXP _BayesianConditionalFPCA_cppupdateeta(SEXP ThetaSEXP, SEXP LambdaSEXP, SEXP precisionSEXP, SEXP EtaMSEXP, SEXP EtaVSEXP, SEXP XSEXP, SEXP BSEXP, SEXP YSEXP, SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type precision(precisionSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type EtaM(EtaMSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type EtaV(EtaVSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< double >::type K(KSEXP);
    cppupdateeta(Theta, Lambda, precision, EtaM, EtaV, X, B, Y, K);
    return R_NilValue;
END_RCPP
}
// cpploglik
double cpploglik(arma::mat& Theta, arma::mat& Lambda, arma::vec& precision, arma::mat& X, arma::mat& B, arma::mat& Y, arma::uword K, int cores);
RcppExport SEXP _BayesianConditionalFPCA_cpploglik(SEXP ThetaSEXP, SEXP LambdaSEXP, SEXP precisionSEXP, SEXP XSEXP, SEXP BSEXP, SEXP YSEXP, SEXP KSEXP, SEXP coresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type precision(precisionSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type K(KSEXP);
    Rcpp::traits::input_parameter< int >::type cores(coresSEXP);
    rcpp_result_gen = Rcpp::wrap(cpploglik(Theta, Lambda, precision, X, B, Y, K, cores));
    return rcpp_result_gen;
END_RCPP
}
// cpp_EM2
void cpp_EM2(arma::mat X, arma::mat B, arma::mat Y, arma::uword K);
RcppExport SEXP _BayesianConditionalFPCA_cpp_EM2(SEXP XSEXP, SEXP BSEXP, SEXP YSEXP, SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type K(KSEXP);
    cpp_EM2(X, B, Y, K);
    return R_NilValue;
END_RCPP
}
// cpp_EM
List cpp_EM(arma::mat X, arma::mat B, arma::mat Y, arma::uword K, arma::mat Theta_init, int cores);
RcppExport SEXP _BayesianConditionalFPCA_cpp_EM(SEXP XSEXP, SEXP BSEXP, SEXP YSEXP, SEXP KSEXP, SEXP Theta_initSEXP, SEXP coresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type K(KSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Theta_init(Theta_initSEXP);
    Rcpp::traits::input_parameter< int >::type cores(coresSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_EM(X, B, Y, K, Theta_init, cores));
    return rcpp_result_gen;
END_RCPP
}
// cpp_EM_new
List cpp_EM_new(arma::mat X, arma::mat B, arma::mat Y, arma::uword K, arma::mat Theta_init, arma::mat Lambda_init, int cores);
RcppExport SEXP _BayesianConditionalFPCA_cpp_EM_new(SEXP XSEXP, SEXP BSEXP, SEXP YSEXP, SEXP KSEXP, SEXP Theta_initSEXP, SEXP Lambda_initSEXP, SEXP coresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type K(KSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Theta_init(Theta_initSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Lambda_init(Lambda_initSEXP);
    Rcpp::traits::input_parameter< int >::type cores(coresSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_EM_new(X, B, Y, K, Theta_init, Lambda_init, cores));
    return rcpp_result_gen;
END_RCPP
}
// MCMC
List MCMC(arma::mat Y, arma::mat X, arma::mat B, int K, arma::uword iter, arma::uword nchains, arma::uword thin, arma::mat Theta_init, arma::cube Lambda_init, arma::mat Eta_init, double Prec_init);
RcppExport SEXP _BayesianConditionalFPCA_MCMC(SEXP YSEXP, SEXP XSEXP, SEXP BSEXP, SEXP KSEXP, SEXP iterSEXP, SEXP nchainsSEXP, SEXP thinSEXP, SEXP Theta_initSEXP, SEXP Lambda_initSEXP, SEXP Eta_initSEXP, SEXP Prec_initSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type B(BSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type iter(iterSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type nchains(nchainsSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type thin(thinSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Theta_init(Theta_initSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type Lambda_init(Lambda_initSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Eta_init(Eta_initSEXP);
    Rcpp::traits::input_parameter< double >::type Prec_init(Prec_initSEXP);
    rcpp_result_gen = Rcpp::wrap(MCMC(Y, X, B, K, iter, nchains, thin, Theta_init, Lambda_init, Eta_init, Prec_init));
    return rcpp_result_gen;
END_RCPP
}
// MCMC_Impute
List MCMC_Impute(arma::field<arma::vec> y, arma::field<arma::vec> observedTimes, arma::vec fullTimes, arma::mat X, arma::mat B, int K, int iter, int nchains, int thin);
RcppExport SEXP _BayesianConditionalFPCA_MCMC_Impute(SEXP ySEXP, SEXP observedTimesSEXP, SEXP fullTimesSEXP, SEXP XSEXP, SEXP BSEXP, SEXP KSEXP, SEXP iterSEXP, SEXP nchainsSEXP, SEXP thinSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::field<arma::vec> >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::field<arma::vec> >::type observedTimes(observedTimesSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type fullTimes(fullTimesSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type B(BSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    Rcpp::traits::input_parameter< int >::type nchains(nchainsSEXP);
    Rcpp::traits::input_parameter< int >::type thin(thinSEXP);
    rcpp_result_gen = Rcpp::wrap(MCMC_Impute(y, observedTimes, fullTimes, X, B, K, iter, nchains, thin));
    return rcpp_result_gen;
END_RCPP
}
// MCMC_Sparse
List MCMC_Sparse(arma::field<arma::vec> Y, arma::mat X, arma::field<arma::mat> B, int K, int iter, int nchains, int thin);
RcppExport SEXP _BayesianConditionalFPCA_MCMC_Sparse(SEXP YSEXP, SEXP XSEXP, SEXP BSEXP, SEXP KSEXP, SEXP iterSEXP, SEXP nchainsSEXP, SEXP thinSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::field<arma::vec> >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::field<arma::mat> >::type B(BSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    Rcpp::traits::input_parameter< int >::type nchains(nchainsSEXP);
    Rcpp::traits::input_parameter< int >::type thin(thinSEXP);
    rcpp_result_gen = Rcpp::wrap(MCMC_Sparse(Y, X, B, K, iter, nchains, thin));
    return rcpp_result_gen;
END_RCPP
}
// MCMC_Wrapper
List MCMC_Wrapper(arma::mat Y, arma::mat X, arma::mat B, arma::uword K, arma::uword iter, arma::uword nchains, arma::uword thin, arma::mat Theta_init, arma::cube Lambda_init, arma::mat Eta_init);
RcppExport SEXP _BayesianConditionalFPCA_MCMC_Wrapper(SEXP YSEXP, SEXP XSEXP, SEXP BSEXP, SEXP KSEXP, SEXP iterSEXP, SEXP nchainsSEXP, SEXP thinSEXP, SEXP Theta_initSEXP, SEXP Lambda_initSEXP, SEXP Eta_initSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type K(KSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type iter(iterSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type nchains(nchainsSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type thin(thinSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Theta_init(Theta_initSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type Lambda_init(Lambda_initSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Eta_init(Eta_initSEXP);
    rcpp_result_gen = Rcpp::wrap(MCMC_Wrapper(Y, X, B, K, iter, nchains, thin, Theta_init, Lambda_init, Eta_init));
    return rcpp_result_gen;
END_RCPP
}
// DiffOp
arma::mat DiffOp(arma::uword n);
RcppExport SEXP _BayesianConditionalFPCA_DiffOp(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::uword >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(DiffOp(n));
    return rcpp_result_gen;
END_RCPP
}
// getPenalty2
arma::mat getPenalty2(arma::uword n, arma::uword D);
RcppExport SEXP _BayesianConditionalFPCA_getPenalty2(SEXP nSEXP, SEXP DSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::uword >::type n(nSEXP);
    Rcpp::traits::input_parameter< arma::uword >::type D(DSEXP);
    rcpp_result_gen = Rcpp::wrap(getPenalty2(n, D));
    return rcpp_result_gen;
END_RCPP
}
// getPenalty
arma::mat getPenalty(arma::uword n);
RcppExport SEXP _BayesianConditionalFPCA_getPenalty(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::uword >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(getPenalty(n));
    return rcpp_result_gen;
END_RCPP
}
// initializeY
arma::rowvec initializeY(arma::vec y, arma::vec observedTimes, arma::vec fullTimes);
RcppExport SEXP _BayesianConditionalFPCA_initializeY(SEXP ySEXP, SEXP observedTimesSEXP, SEXP fullTimesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::vec >::type observedTimes(observedTimesSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type fullTimes(fullTimesSEXP);
    rcpp_result_gen = Rcpp::wrap(initializeY(y, observedTimes, fullTimes));
    return rcpp_result_gen;
END_RCPP
}
// getObservedOrder
arma::uvec getObservedOrder(arma::vec observedTimes, arma::vec fullTimes);
RcppExport SEXP _BayesianConditionalFPCA_getObservedOrder(SEXP observedTimesSEXP, SEXP fullTimesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type observedTimes(observedTimesSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type fullTimes(fullTimesSEXP);
    rcpp_result_gen = Rcpp::wrap(getObservedOrder(observedTimes, fullTimes));
    return rcpp_result_gen;
END_RCPP
}
// PredictY
void PredictY(arma::mat& ImputedY, arma::mat X, arma::mat B, arma::mat Theta, arma::mat Eta, arma::cube Lambda, double Prec);
RcppExport SEXP _BayesianConditionalFPCA_PredictY(SEXP ImputedYSEXP, SEXP XSEXP, SEXP BSEXP, SEXP ThetaSEXP, SEXP EtaSEXP, SEXP LambdaSEXP, SEXP PrecSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type ImputedY(ImputedYSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Theta(ThetaSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Eta(EtaSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< double >::type Prec(PrecSEXP);
    PredictY(ImputedY, X, B, Theta, Eta, Lambda, Prec);
    return R_NilValue;
END_RCPP
}
// PredictY2
void PredictY2(arma::mat& ImputedY, arma::field<arma::uvec> observedOrder, arma::mat X, arma::mat B, arma::mat Theta, arma::cube Lambda, arma::mat Eta, double Prec);
RcppExport SEXP _BayesianConditionalFPCA_PredictY2(SEXP ImputedYSEXP, SEXP observedOrderSEXP, SEXP XSEXP, SEXP BSEXP, SEXP ThetaSEXP, SEXP LambdaSEXP, SEXP EtaSEXP, SEXP PrecSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type ImputedY(ImputedYSEXP);
    Rcpp::traits::input_parameter< arma::field<arma::uvec> >::type observedOrder(observedOrderSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Theta(ThetaSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Eta(EtaSEXP);
    Rcpp::traits::input_parameter< double >::type Prec(PrecSEXP);
    PredictY2(ImputedY, observedOrder, X, B, Theta, Lambda, Eta, Prec);
    return R_NilValue;
END_RCPP
}
// rcpparma_hello_world
arma::mat rcpparma_hello_world();
RcppExport SEXP _BayesianConditionalFPCA_rcpparma_hello_world() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(rcpparma_hello_world());
    return rcpp_result_gen;
END_RCPP
}
// rcpparma_outerproduct
arma::mat rcpparma_outerproduct(const arma::colvec& x);
RcppExport SEXP _BayesianConditionalFPCA_rcpparma_outerproduct(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpparma_outerproduct(x));
    return rcpp_result_gen;
END_RCPP
}
// rcpparma_innerproduct
double rcpparma_innerproduct(const arma::colvec& x);
RcppExport SEXP _BayesianConditionalFPCA_rcpparma_innerproduct(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpparma_innerproduct(x));
    return rcpp_result_gen;
END_RCPP
}
// rcpparma_bothproducts
Rcpp::List rcpparma_bothproducts(const arma::colvec& x);
RcppExport SEXP _BayesianConditionalFPCA_rcpparma_bothproducts(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpparma_bothproducts(x));
    return rcpp_result_gen;
END_RCPP
}
// timesTwo
NumericVector timesTwo(NumericVector x);
RcppExport SEXP _BayesianConditionalFPCA_timesTwo(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(timesTwo(x));
    return rcpp_result_gen;
END_RCPP
}
// updateLambda
void updateLambda(arma::mat& Y, arma::cube& Lambda, arma::vec& r, arma::mat& Gamma, arma::mat& X, arma::mat& B, double prec);
RcppExport SEXP _BayesianConditionalFPCA_updateLambda(SEXP YSEXP, SEXP LambdaSEXP, SEXP rSEXP, SEXP GammaSEXP, SEXP XSEXP, SEXP BSEXP, SEXP precSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type r(rSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Gamma(GammaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< double >::type prec(precSEXP);
    updateLambda(Y, Lambda, r, Gamma, X, B, prec);
    return R_NilValue;
END_RCPP
}
// updateLambda2
void updateLambda2(arma::mat& Y, arma::cube& Lambda, arma::mat& Tau, arma::mat& Gamma, arma::mat& X, arma::mat& B, double prec, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updateLambda2(SEXP YSEXP, SEXP LambdaSEXP, SEXP TauSEXP, SEXP GammaSEXP, SEXP XSEXP, SEXP BSEXP, SEXP precSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Tau(TauSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Gamma(GammaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< double >::type prec(precSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    updateLambda2(Y, Lambda, Tau, Gamma, X, B, prec, Theta);
    return R_NilValue;
END_RCPP
}
// updateTheta
void updateTheta(arma::mat& Y, arma::cube& Lambda, arma::mat& Tau, arma::mat& Gamma, arma::mat& X, arma::mat& B, double prec, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updateTheta(SEXP YSEXP, SEXP LambdaSEXP, SEXP TauSEXP, SEXP GammaSEXP, SEXP XSEXP, SEXP BSEXP, SEXP precSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Tau(TauSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Gamma(GammaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< double >::type prec(precSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    updateTheta(Y, Lambda, Tau, Gamma, X, B, prec, Theta);
    return R_NilValue;
END_RCPP
}
// updateTheta2
void updateTheta2(arma::mat& Y, arma::cube& Lambda, arma::mat& Tau, arma::mat& X, arma::mat& B, double prec, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updateTheta2(SEXP YSEXP, SEXP LambdaSEXP, SEXP TauSEXP, SEXP XSEXP, SEXP BSEXP, SEXP precSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Tau(TauSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< double >::type prec(precSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    updateTheta2(Y, Lambda, Tau, X, B, prec, Theta);
    return R_NilValue;
END_RCPP
}
// updateThetaLambda
void updateThetaLambda(arma::mat& Y, arma::cube& Lambda, arma::mat& Eta, arma::mat& Tau, arma::mat& X, arma::mat& B, double prec, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updateThetaLambda(SEXP YSEXP, SEXP LambdaSEXP, SEXP EtaSEXP, SEXP TauSEXP, SEXP XSEXP, SEXP BSEXP, SEXP precSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Eta(EtaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Tau(TauSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< double >::type prec(precSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    updateThetaLambda(Y, Lambda, Eta, Tau, X, B, prec, Theta);
    return R_NilValue;
END_RCPP
}
// updateEta
void updateEta(arma::mat& Y, arma::cube& Lambda, arma::vec& Sigma, arma::mat& Eta, arma::mat& X, arma::mat& B, double prec, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updateEta(SEXP YSEXP, SEXP LambdaSEXP, SEXP SigmaSEXP, SEXP EtaSEXP, SEXP XSEXP, SEXP BSEXP, SEXP precSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type Sigma(SigmaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Eta(EtaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< double >::type prec(precSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    updateEta(Y, Lambda, Sigma, Eta, X, B, prec, Theta);
    return R_NilValue;
END_RCPP
}
// updateEta2
void updateEta2(arma::mat& Y, arma::cube& Lambda, arma::vec& Sigma, arma::mat& Eta, arma::mat& X, arma::mat& B, double prec, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updateEta2(SEXP YSEXP, SEXP LambdaSEXP, SEXP SigmaSEXP, SEXP EtaSEXP, SEXP XSEXP, SEXP BSEXP, SEXP precSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type Sigma(SigmaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Eta(EtaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< double >::type prec(precSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    updateEta2(Y, Lambda, Sigma, Eta, X, B, prec, Theta);
    return R_NilValue;
END_RCPP
}
// updateEta3
void updateEta3(arma::mat& Y, arma::cube& Lambda, arma::mat& Eta, arma::mat& X, arma::mat& B, double prec, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updateEta3(SEXP YSEXP, SEXP LambdaSEXP, SEXP EtaSEXP, SEXP XSEXP, SEXP BSEXP, SEXP precSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Eta(EtaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< double >::type prec(precSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    updateEta3(Y, Lambda, Eta, X, B, prec, Theta);
    return R_NilValue;
END_RCPP
}
// updatePrec
double updatePrec(arma::mat& Y, arma::cube& Lambda, arma::mat Gamma, arma::mat& X, arma::mat& B, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updatePrec(SEXP YSEXP, SEXP LambdaSEXP, SEXP GammaSEXP, SEXP XSEXP, SEXP BSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Gamma(GammaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    rcpp_result_gen = Rcpp::wrap(updatePrec(Y, Lambda, Gamma, X, B, Theta));
    return rcpp_result_gen;
END_RCPP
}
// updateTau
void updateTau(arma::mat& Theta, arma::cube& Lambda, arma::mat& Tau);
RcppExport SEXP _BayesianConditionalFPCA_updateTau(SEXP ThetaSEXP, SEXP LambdaSEXP, SEXP TauSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Tau(TauSEXP);
    updateTau(Theta, Lambda, Tau);
    return R_NilValue;
END_RCPP
}
// updateSigma
void updateSigma(arma::mat& Eta, arma::vec& Sigma);
RcppExport SEXP _BayesianConditionalFPCA_updateSigma(SEXP EtaSEXP, SEXP SigmaSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type Eta(EtaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type Sigma(SigmaSEXP);
    updateSigma(Eta, Sigma);
    return R_NilValue;
END_RCPP
}
// updateLambdaS
void updateLambdaS(arma::field<arma::vec>& Y, arma::cube& Lambda, arma::mat& Tau, arma::mat& c, arma::mat& Gamma, arma::mat& X, arma::field<arma::mat>& B, double prec, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updateLambdaS(SEXP YSEXP, SEXP LambdaSEXP, SEXP TauSEXP, SEXP cSEXP, SEXP GammaSEXP, SEXP XSEXP, SEXP BSEXP, SEXP precSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::field<arma::vec>& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Tau(TauSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type c(cSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Gamma(GammaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::field<arma::mat>& >::type B(BSEXP);
    Rcpp::traits::input_parameter< double >::type prec(precSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    updateLambdaS(Y, Lambda, Tau, c, Gamma, X, B, prec, Theta);
    return R_NilValue;
END_RCPP
}
// updateThetaS
void updateThetaS(arma::field<arma::vec>& Y, arma::cube& Lambda, arma::mat& Tau, arma::mat& Gamma, arma::mat& X, arma::field<arma::mat> B, double prec, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updateThetaS(SEXP YSEXP, SEXP LambdaSEXP, SEXP TauSEXP, SEXP GammaSEXP, SEXP XSEXP, SEXP BSEXP, SEXP precSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::field<arma::vec>& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Tau(TauSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Gamma(GammaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::field<arma::mat> >::type B(BSEXP);
    Rcpp::traits::input_parameter< double >::type prec(precSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    updateThetaS(Y, Lambda, Tau, Gamma, X, B, prec, Theta);
    return R_NilValue;
END_RCPP
}
// updateEtaS
void updateEtaS(arma::field<arma::vec>& Y, arma::cube& Lambda, arma::vec& Sigma, arma::mat& Eta, arma::mat& X, arma::field<arma::mat>& B, double prec, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updateEtaS(SEXP YSEXP, SEXP LambdaSEXP, SEXP SigmaSEXP, SEXP EtaSEXP, SEXP XSEXP, SEXP BSEXP, SEXP precSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::field<arma::vec>& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type Sigma(SigmaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Eta(EtaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::field<arma::mat>& >::type B(BSEXP);
    Rcpp::traits::input_parameter< double >::type prec(precSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    updateEtaS(Y, Lambda, Sigma, Eta, X, B, prec, Theta);
    return R_NilValue;
END_RCPP
}
// updatePrecS
double updatePrecS(arma::field<arma::vec>& Y, arma::cube& Lambda, arma::mat Gamma, arma::mat& X, arma::field<arma::mat>& B, arma::mat& Theta);
RcppExport SEXP _BayesianConditionalFPCA_updatePrecS(SEXP YSEXP, SEXP LambdaSEXP, SEXP GammaSEXP, SEXP XSEXP, SEXP BSEXP, SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::field<arma::vec>& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type Lambda(LambdaSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Gamma(GammaSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::field<arma::mat>& >::type B(BSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type Theta(ThetaSEXP);
    rcpp_result_gen = Rcpp::wrap(updatePrecS(Y, Lambda, Gamma, X, B, Theta));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_BayesianConditionalFPCA_cppgetX", (DL_FUNC) &_BayesianConditionalFPCA_cppgetX, 5},
    {"_BayesianConditionalFPCA_cppupdateall", (DL_FUNC) &_BayesianConditionalFPCA_cppupdateall, 7},
    {"_BayesianConditionalFPCA_cppupdateeta", (DL_FUNC) &_BayesianConditionalFPCA_cppupdateeta, 9},
    {"_BayesianConditionalFPCA_cpploglik", (DL_FUNC) &_BayesianConditionalFPCA_cpploglik, 8},
    {"_BayesianConditionalFPCA_cpp_EM2", (DL_FUNC) &_BayesianConditionalFPCA_cpp_EM2, 4},
    {"_BayesianConditionalFPCA_cpp_EM", (DL_FUNC) &_BayesianConditionalFPCA_cpp_EM, 6},
    {"_BayesianConditionalFPCA_cpp_EM_new", (DL_FUNC) &_BayesianConditionalFPCA_cpp_EM_new, 7},
    {"_BayesianConditionalFPCA_MCMC", (DL_FUNC) &_BayesianConditionalFPCA_MCMC, 11},
    {"_BayesianConditionalFPCA_MCMC_Impute", (DL_FUNC) &_BayesianConditionalFPCA_MCMC_Impute, 9},
    {"_BayesianConditionalFPCA_MCMC_Sparse", (DL_FUNC) &_BayesianConditionalFPCA_MCMC_Sparse, 7},
    {"_BayesianConditionalFPCA_MCMC_Wrapper", (DL_FUNC) &_BayesianConditionalFPCA_MCMC_Wrapper, 10},
    {"_BayesianConditionalFPCA_DiffOp", (DL_FUNC) &_BayesianConditionalFPCA_DiffOp, 1},
    {"_BayesianConditionalFPCA_getPenalty2", (DL_FUNC) &_BayesianConditionalFPCA_getPenalty2, 2},
    {"_BayesianConditionalFPCA_getPenalty", (DL_FUNC) &_BayesianConditionalFPCA_getPenalty, 1},
    {"_BayesianConditionalFPCA_initializeY", (DL_FUNC) &_BayesianConditionalFPCA_initializeY, 3},
    {"_BayesianConditionalFPCA_getObservedOrder", (DL_FUNC) &_BayesianConditionalFPCA_getObservedOrder, 2},
    {"_BayesianConditionalFPCA_PredictY", (DL_FUNC) &_BayesianConditionalFPCA_PredictY, 7},
    {"_BayesianConditionalFPCA_PredictY2", (DL_FUNC) &_BayesianConditionalFPCA_PredictY2, 8},
    {"_BayesianConditionalFPCA_rcpparma_hello_world", (DL_FUNC) &_BayesianConditionalFPCA_rcpparma_hello_world, 0},
    {"_BayesianConditionalFPCA_rcpparma_outerproduct", (DL_FUNC) &_BayesianConditionalFPCA_rcpparma_outerproduct, 1},
    {"_BayesianConditionalFPCA_rcpparma_innerproduct", (DL_FUNC) &_BayesianConditionalFPCA_rcpparma_innerproduct, 1},
    {"_BayesianConditionalFPCA_rcpparma_bothproducts", (DL_FUNC) &_BayesianConditionalFPCA_rcpparma_bothproducts, 1},
    {"_BayesianConditionalFPCA_timesTwo", (DL_FUNC) &_BayesianConditionalFPCA_timesTwo, 1},
    {"_BayesianConditionalFPCA_updateLambda", (DL_FUNC) &_BayesianConditionalFPCA_updateLambda, 7},
    {"_BayesianConditionalFPCA_updateLambda2", (DL_FUNC) &_BayesianConditionalFPCA_updateLambda2, 8},
    {"_BayesianConditionalFPCA_updateTheta", (DL_FUNC) &_BayesianConditionalFPCA_updateTheta, 8},
    {"_BayesianConditionalFPCA_updateTheta2", (DL_FUNC) &_BayesianConditionalFPCA_updateTheta2, 7},
    {"_BayesianConditionalFPCA_updateThetaLambda", (DL_FUNC) &_BayesianConditionalFPCA_updateThetaLambda, 8},
    {"_BayesianConditionalFPCA_updateEta", (DL_FUNC) &_BayesianConditionalFPCA_updateEta, 8},
    {"_BayesianConditionalFPCA_updateEta2", (DL_FUNC) &_BayesianConditionalFPCA_updateEta2, 8},
    {"_BayesianConditionalFPCA_updateEta3", (DL_FUNC) &_BayesianConditionalFPCA_updateEta3, 7},
    {"_BayesianConditionalFPCA_updatePrec", (DL_FUNC) &_BayesianConditionalFPCA_updatePrec, 6},
    {"_BayesianConditionalFPCA_updateTau", (DL_FUNC) &_BayesianConditionalFPCA_updateTau, 3},
    {"_BayesianConditionalFPCA_updateSigma", (DL_FUNC) &_BayesianConditionalFPCA_updateSigma, 2},
    {"_BayesianConditionalFPCA_updateLambdaS", (DL_FUNC) &_BayesianConditionalFPCA_updateLambdaS, 9},
    {"_BayesianConditionalFPCA_updateThetaS", (DL_FUNC) &_BayesianConditionalFPCA_updateThetaS, 8},
    {"_BayesianConditionalFPCA_updateEtaS", (DL_FUNC) &_BayesianConditionalFPCA_updateEtaS, 8},
    {"_BayesianConditionalFPCA_updatePrecS", (DL_FUNC) &_BayesianConditionalFPCA_updatePrecS, 6},
    {NULL, NULL, 0}
};

RcppExport void R_init_BayesianConditionalFPCA(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
