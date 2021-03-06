# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

get_posterior_subject_bands_cpp <- function(mcmc_output, alpha, mode) {
    .Call('_bfcr_get_posterior_subject_bands_cpp', PACKAGE = 'bfcr', mcmc_output, alpha, mode)
}

get_posterior_means_cpp <- function(mcmc_results, xi, alpha, mode) {
    .Call('_bfcr_get_posterior_means_cpp', PACKAGE = 'bfcr', mcmc_results, xi, alpha, mode)
}

get_posterior_eigen_cpp <- function(mcmc_results, eigenvals, zi, alpha, mode) {
    .Call('_bfcr_get_posterior_eigen_cpp', PACKAGE = 'bfcr', mcmc_results, eigenvals, zi, alpha, mode)
}

get_posterior_covariance_cpp <- function(mcmc_results, zi) {
    .Call('_bfcr_get_posterior_covariance_cpp', PACKAGE = 'bfcr', mcmc_results, zi)
}

#' Run Markov-Chain Monte-Carlo
#'
#' Generate samples from the posterior distribution. This
#' algorithm pre-dominantly uses Gibbs sampling
#' @param response N x T response matrix, where N is number of subjects and T is number
#' of time points. Values can be NA if there's missing data
#' @param design_mean N x d_{1} design matrix for mean structure
#' @param design_var N x d_{2} design matrix for the covariance structure
#' @param basis User generated basis matrix
#' @param time vector of time points
#' @param penalties_mean List of smoothing penalties for mean structure
#' @param penalties_var List of smoothin penalties for covariance structure
#' @param indices_mean Maps penalties in the mean structure to beta coefficients
#' @param indices_var Maps penalties in the covariance structure to lambda
#' coefficients
#' @param kdim Dimension of latent subspace
#' @param iter Number of iterations to run
#' @param burnin Number of iterations to use as burn-in. This is only relevant when
#' passing the returned object into post-processing functions
#' @param thin Thinning defaulting to 1
#' @param var Can be set to "unequal" to estimate subject-specific measurement
#' errors or "pooled" to estimate a pooled measurement error variance
#' @export run_mcmc
#' @return A List containing 3 lists including data, control, and samples.
run_mcmc <- function(response, design_mean, design_var, basis, time, penalties_mean, penalties_var, indices_mean, indices_var, kdim, iter, burnin, thin = 1L, var = "unequal") {
    .Call('_bfcr_run_mcmc', PACKAGE = 'bfcr', response, design_mean, design_var, basis, time, penalties_mean, penalties_var, indices_mean, indices_var, kdim, iter, burnin, thin, var)
}

get_proposal <- function(old) {
    .Call('_bfcr_get_proposal', PACKAGE = 'bfcr', old)
}

armadillo_modulus <- function(indicies, n) {
    .Call('_bfcr_armadillo_modulus', PACKAGE = 'bfcr', indicies, n)
}

