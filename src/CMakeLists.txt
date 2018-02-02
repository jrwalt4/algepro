cmake_minimum_required(VERSION 2.6)

project(algeprop)

add_executable(
  algepro
  main.cpp
  RandomVariable.cpp
  RandomVariableSum.cpp
  NormalVariable.cpp
  CauchyVariable stats.cpp
  quadrature.cpp
)