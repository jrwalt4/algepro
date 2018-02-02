#ifndef quadrature_hpp_
#define quadrature_hpp_

typedef double (*t_pdf)(double, const void*);

double quadrature_Trapezoidal(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound, int count);
double quadrature_Trapezoidal(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound);

double quadrature_Simpsons(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound, int count);
double quadrature_Simpsons(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound);

double quadrature_Gaussian(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound, int count);
double quadrature_Gaussian(t_pdf pdf, const void *this_ptr, double lowerBound, double upperBound);

#endif