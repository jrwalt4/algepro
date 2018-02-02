#include <iostream>
#include <string>
#include <cmath>
#include "NormalVariable.hpp"
#include "CauchyVariable.hpp"
#include "stats.hpp"

using namespace std;

void stdlog(string msg) {
  cout << msg << "\n";
}

void stdlog(double val) {
  stdlog(to_string(val));
}

int main() {
  NormalVariable nv(2,1);
  stdlog(nv.pdf(1));
  stdlog(nv.probability(1,3));

  NormalVariable norm;
  stdlog(0.5*erf(3/sqrt(2)));
  stdlog(norm.probability(0,3));

  CauchyVariable c(0,1);
  stdlog(c.probability(-5,5));

  RandomVariable& rv = nv + nv;
  stdlog(rv.pdf(1));

  return 0;
}
