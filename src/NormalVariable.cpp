#include "NormalVariable.hpp"
#include <cmath>
#include "constants.h"
#include "stats.hpp"
#include "quadrature.hpp"

double NormalVariable::pdf(double x) const {
  return gaussian(x, this->mean_, this->std_);
}

double NormalVariable::integrate(double lowerBound, double upperBound) const {
  return quadrature_Simpsons(static_pdf, this, lowerBound, upperBound, 5);
}
