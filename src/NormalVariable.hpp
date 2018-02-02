#ifndef NormalVariable_hpp__
#define NormalVariable_hpp__
#include "RandomVariable.hpp"
class NormalVariable: public RandomVariable {
  private:
    double mean_;
    double std_;
  public:
    NormalVariable():NormalVariable(0,1){};
    NormalVariable(double mean, double std): mean_(mean), std_(std){};
    double pdf(double) const override;
    double integrate(double, double) const override;
};
#endif