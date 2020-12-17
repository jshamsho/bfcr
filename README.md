bfcr
================

The `bfcr` package provides functions to perform nonparametric Bayesian
inference for covariate-adjusted covariance operators with functional
response data as described in “Bayesian functional covariance
regression” by Shamshoian et al. (2021). This package contains a C++
implementation of the Markov-Chain Monte-Carlo sampling algorithm in the
Supporting Information document and several convenience functions for
extracting posterior summaries. The online GitHub repository contains
all code used in the analysis of the resting state EEG data from
children with autism spectrum disorder as well as the sleep waveforms
collected on patients’ polysomnography from SHHS visit 1. However, both
of these data sets are not publicly available so we illustrate our
methods with a simulated example.

## Installation

Simply install with GitHub by using the R package `devtools.`

``` r
if (!requireNamespace("devtools", quietly = TRUE)) {
    install.packages("devtools")
  }
# devtools::install_github("jshamsho/bfcr")
```

## Example

### Simulated data set description

We will simulate a data set akin to one generated under case 1
conditions from the main manuscript. This data set will have
![formula](https://latex.codecogs.com/svg.latex?N&space;=&space;100)
response curves with population mean and heteroscedasticity dependending
on a single covariate
![formula](https://latex.codecogs.com/svg.latex?x). Following notation
from the manuscript, the data generating model for the
![formula](https://latex.codecogs.com/svg.latex?i)th response curve at
time ![formula](https://latex.codecogs.com/svg.latex?t) has functional
mean
![formula](https://latex.codecogs.com/svg.latex?\\mu\(t,&space;x_%7Bi%7D\)),
random deviation
![formula](https://latex.codecogs.com/svg.latex?r_%7Bi%7D\(t,&space;x_%7Bi%7D\)),
and measurement source error
![formula](https://latex.codecogs.com/svg.latex?\\epsilon_%7Bi%7D\(t\))).