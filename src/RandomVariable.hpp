#ifndef RandomVariable_hpp__
#define RandomVariable_hpp__
class RandomVariable {
  protected:
    virtual double integrate(double, double) const;
  public:
    virtual double pdf(double) const = 0;
    static double static_pdf(double, const void*);
    virtual double probability(double, double) const;
};

RandomVariable& operator+(RandomVariable& lhs, RandomVariable& rhs);
#endif