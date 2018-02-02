#include "RandomVariableSum.hpp"
#include "quadrature.hpp"

struct t_convolution {
  double rotation;
  RandomVariable& left;
  RandomVariable& right;
};

double convolution(double x, const void* convolution_data) {
  t_convolution* c = (t_convolution*) convolution_data;
  return c->left.pdf(c->rotation - x) * c->right.pdf(x);
}

double RandomVariableSum::pdf(double z) const {
  t_convolution data = {z, left_, right_};
  return quadrature_Simpsons(convolution, &data, -10, 10, 20);
}