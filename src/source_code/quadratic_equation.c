#include "../quadratic_equation.h"

#define QE_EPS 1e-8

// check if double is zero
// 0 - is zero
// 1 - non-zero
int is_zero(double n) { return !(fabs(n) < QE_EPS); }
// case 0b000
// 0 = 0, x - any number
void any_number(answ_t* out);
// case 0b001
// c = 0, no solutions
void no_solutions(answ_t* out);
// case 0b010 or
// case 0b100
// bx = 0 or ax^2 = 0
void x_is_zero(answ_t* out);
// case 0b011
// bx + c = 0
void linear(answ_t* out, double b, double c);
// case 0b101
// ax^2 + c = 0
void without_b(answ_t* out, double a, double c);
// case 0b110
// ax^2 + bx = 0
void without_c(answ_t* out, double a, double b);
// case 0b111
// ax^2 + bx + c = 0
void discriminant(answ_t* out, double a, double b, double c);

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
answ_t solve_equation(double a, double b, double c) {
  answ_t out = {0};

  unsigned char r = 0;
  // check quadratic equation terms
  r = (is_zero(c) + (is_zero(b) << 1) + (is_zero(a) << 2));

  switch (r) {
    case 0b000:  // 0 = 0, x - any number
      any_number(&out);
      break;

    case 0b001:  // c = 0, no solutions
      no_solutions(&out);
      break;

    case 0b010:  // bx = 0
      x_is_zero(&out);
      break;

    case 0b011:  // bx + c = 0
      linear(&out, b, c);
      break;

    case 0b100:  // ax^2 = 0
      x_is_zero(&out);
      break;

    case 0b101:  // ax^2 + c = 0
      without_b(&out, a, c);
      break;

    case 0b110:  // ax^2 + bx = 0
      without_c(&out, a, b);
      break;

    case 0b111:  // ax^2 + bx + c = 0
      discriminant(&out, a, b, c);
      break;

    default:
      printf("UNKNOWN STATE\n");
      break;
  }

  return out;
}

// case 0b000
// 0 = 0, x - any number
void any_number(answ_t* out) { out->flag = QE_MANY_SLN; }

// case 0b001
// c = 0, no solutions
void no_solutions(answ_t* out) { out->flag = QE_NO_SLN; }

// case 0b010 or
// case 0b100
// bx = 0 or ax^2 = 0
void x_is_zero(answ_t* out) {
  out->flag = QE_ONE_SLN;
  out->x1.Re = 0.0;
  out->x1.Im = 0.0;
}

// case 0b011
// bx + c = 0
void linear(answ_t* out, double b, double c) {
  out->flag = QE_ONE_SLN;
  out->x1.Re = -c / b;
  out->x1.Im = 0.0;
}

// case 0b101
// ax^2 + c = 0
void without_b(answ_t* out, double a, double c) {
  out->flag = QE_TWO_SLN;

  if (-c / a < 0.0f) {
    // complex
    out->x1.Re = 0.0;
    out->x1.Im = sqrt(c / a);
    out->x2.Re = 0.0;
    out->x2.Im = -sqrt(c / a);
  } else {
    out->x1.Re = sqrt(-c / a);
    out->x1.Im = 0.0;
    out->x2.Re = -sqrt(-c / a);
    out->x2.Im = 0.0;
  }
}

// case 0b110
// ax^2 + bx = 0
void without_c(answ_t* out, double a, double b) {
  out->flag = QE_TWO_SLN;
  out->x1.Re = 0.0;
  out->x1.Im = 0.0;
  out->x2.Re = -b / a;
  out->x2.Im = 0.0;
}

// case 0b111
// ax^2 + bx + c = 0
void discriminant(answ_t* out, double a, double b, double c) {
  double D = b * b - 4 * a * c;

  if (is_zero(D) == 0) {
    // one x
    out->flag = QE_ONE_SLN;
    out->x1.Re = (-b) / (2 * a);
    out->x1.Im = 0;
  } else if (D < 0) {
    // two x, complex
    out->flag = QE_TWO_SLN;
    out->x1.Re = (-b) / (2 * a);
    out->x1.Im = (sqrt(-D)) / (2 * a);
    out->x2.Re = (-b) / (2 * a);
    out->x2.Im = -(sqrt(-D)) / (2 * a);
  } else {
    // two x
    out->flag = QE_TWO_SLN;
    out->x1.Re = (-b + sqrt(D)) / (2 * a);
    out->x1.Im = 0;
    out->x2.Re = (-b - sqrt(D)) / (2 * a);
    out->x2.Im = 0;
  }
}