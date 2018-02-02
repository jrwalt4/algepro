#include "RandomVariable.hpp"
#include "quadrature.hpp"
#include "RandomVariableSum.hpp"
#include <memory>

double RandomVariable::probability(double lowerBound, double upperBound) const {
  return this->integrate(lowerBound, upperBound);
}

double RandomVariable::static_pdf(double x, const void *self) {
  return ((const RandomVariable*) self)->pdf(x);
}

double RandomVariable::integrate(double lowerBound, double upperBound) const {
  return quadrature_Simpsons(static_pdf, this, lowerBound, upperBound, 10);
}

RandomVariable& operator+(RandomVariable& lhs, RandomVariable& rhs) {
  RandomVariableSum sum(lhs, rhs);
  return sum;
}
