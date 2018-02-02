#include "quadrature.hpp"

double quadrature_Trapezoidal(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound, int count) {
  double dx = (upperBound - lowerBound) / ((double) count);
  double sum = 0;
  double x;
  int i;
  for (x = lowerBound, i = 0; i <= count; x += dx, i++) {
    if (i == 0 || i == count) {
      sum += pdf(x, this_ptr) / 2.0;
    } else {
      sum += pdf(x, this_ptr);
    }
  }
  return sum * dx;
}

double quadrature_Trapezoidal(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound) {
  return quadrature_Trapezoidal(pdf, this_ptr, lowerBound, upperBound, 1);
}

double quadrature_Simpsons(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound, int count) {
  double h = (upperBound - lowerBound) / ((double) count);
  double sum = 0.0;
  double x;
  int i;
  for (i = 0, x = lowerBound; i < count; i++, x += h) {
    sum += pdf(x, this_ptr) + 4.0*pdf(x + h/2.0, this_ptr) + pdf(x + h, this_ptr);
  }
  return sum*h/6.0;
}

double quadrature_Simpsons(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound) {
  return quadrature_Simpsons(pdf, this_ptr, lowerBound, upperBound, 1);
}

double quadrature_Gaussian(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound, int count) {
  double xa = -0.774597;
  double wa = 0.555556;
  double xc = 0.0;
  double wc = 0.888889;
  double xb = 0.774597;
  double wb = 0.555556;

  double scaleFactor = (upperBound - lowerBound) / 2.0;
  double shiftFactor = (lowerBound + upperBound) / 2.0;

  double fa = wa * pdf(scaleFactor * xa + shiftFactor, this_ptr);
  double fc = wc * pdf(scaleFactor * xc + shiftFactor, this_ptr);
  double fb = wb * pdf(scaleFactor * xb + shiftFactor, this_ptr);

  return scaleFactor * (fa + fc + fb);
}

double quadrature_Gaussian(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound) {
  return quadrature_Gaussian(pdf, this_ptr, lowerBound, upperBound, 1);
}
