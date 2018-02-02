#ifndef RandomVariableSum_hpp_
#define RandomVariableSum_hpp_
#include "RandomVariable.hpp"
class RandomVariableSum: public RandomVariable {
  private:
    RandomVariable& left_;
    RandomVariable& right_;
  public:
    RandomVariableSum(RandomVariable& left, RandomVariable& right):
      left_(left),
      right_(right) {};
    virtual double pdf(double) const override;
};
#endif