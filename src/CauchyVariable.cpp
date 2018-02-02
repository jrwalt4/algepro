#include "CauchyVariable.hpp"
#include "stats.hpp"
#include "quadrature.hpp"

double CauchyVariable::pdf(double x) const {
  return cauchy(x, this->location_, this->scale_);
}

double CauchyVariable::integrate(double lowerBound, double upperBound) const {
  return cauchy_cumulative(upperBound, location_, scale_) - cauchy_cumulative(lowerBound, location_, scale_);
}