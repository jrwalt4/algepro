#ifndef stats_hpp_
#define stats_hpp_
double gaussian(double x, double mean, double std);
double cauchy(double x, double location, double scale);
double cauchy_cumulative(double x, double location, double scale);
#endif