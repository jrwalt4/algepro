#ifndef CauchyVariable_hpp_
#define CauchyVariable_hpp_
#include "RandomVariable.hpp"
class CauchyVariable: public RandomVariable {
  private:
    double location_;
    double scale_;
  public:
    CauchyVariable(double location, double scale): location_(location), scale_(scale){};
    virtual double pdf(double) const override;
    virtual double integrate(double, double) const override;
};
#endif