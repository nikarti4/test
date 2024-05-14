#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// flag values
#define QE_NO_SLN -1
#define QE_MANY_SLN 0
#define QE_ONE_SLN 1
#define QE_TWO_SLN 2

// Complex number struct
typedef struct {
  double Re;  // Real part
  double Im;  // Imaginary part
} complex_t;

// Answer structur
typedef struct {
  // All numbers are complex
  complex_t x1;
  complex_t x2;
  // Flag to know what type of solve it is
  // -1 - no solution
  // 0 - many solutions
  // 1 - one solution
  // 2 - two solutions
  int flag;
} answ_t;

// function solve the quadratic equation
// ax^2 + bx + c = 0
// return: answ_t
// x1 - complex number (Re, Im)
// x2 - complex number (Re, Im)
// flag:
// ---| -1 No solutions
// ---|  0 Many solutions
// ---|  1 One solutions
// ---|  2 Two solutions
answ_t solve_equation(double a, double b, double c);

#endif