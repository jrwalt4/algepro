#include "stats.hpp"
#include <cmath>
#include "constants.h"

double gaussian(double x, double mean, double std) {
  return exp(-1 * pow(x - mean, 2) / (2 * pow(std, 2))) / sqrt(2 * PI * pow(std, 2));
}

double cauchy(double x, double location, double scale) {
  return scale / PI / (pow(x - location, 2) + pow(scale, 2));
}

double cauchy_cumulative(double x, double location, double scale) {
  return atan((x - location)/scale) / PI + 0.5;
}