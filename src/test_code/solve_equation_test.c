#include "quadratic_equation_test.h"

// print answ_t struct
void print_answ(answ_t a) {
  printf("X1 = %lf%+lfi,\t X2 = %lf%+lfi,\t flag = %d\n", a.x1.Re, a.x1.Im,
         a.x2.Re, a.x2.Im, a.flag);
}

// compare solve_equation output structure and desired values
void answ_compare(answ_t current, answ_t desired) {
  ck_assert_int_eq(current.flag, desired.flag);
  ck_assert_double_eq_tol(current.x1.Re, desired.x1.Re, QE_TEST_EPS);
  ck_assert_double_eq_tol(current.x1.Im, desired.x1.Im, QE_TEST_EPS);
  ck_assert_double_eq_tol(current.x2.Re, desired.x2.Re, QE_TEST_EPS);
  ck_assert_double_eq_tol(current.x2.Im, desired.x2.Im, QE_TEST_EPS);
}

START_TEST(a0b0c0) {
  double a = 0.0, b = 0.0, c = 0.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_MANY_SLN;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a0b0c1) {
  double a = 0.0, b = 0.0, c = 1.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_NO_SLN;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a0b0cn1) {
  double a = 0.0, b = 0.0, c = -1.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_NO_SLN;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a0b1c0) {
  double a = 0.0, b = 1.0, c = 0.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_ONE_SLN;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a0bn1c0) {
  double a = 0.0, b = -1.0, c = 0.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_ONE_SLN;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a0b123c0) {
  double a = 0.0, b = 12.3, c = 0.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_ONE_SLN;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a0bn123c0) {
  double a = 0.0, b = -12.3, c = 0.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_ONE_SLN;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a0b1c1) {
  double a = 0.0, b = 1.0, c = 1.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_ONE_SLN;
  des.x1.Re = -1;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a0bn1c1) {
  double a = 0.0, b = -1.0, c = 1.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_ONE_SLN;
  des.x1.Re = 1;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a0bn1c123) {
  double a = 0.0, b = -1.0, c = 12.3;
  answ_t des = {0}, out = {0};

  des.flag = QE_ONE_SLN;
  des.x1.Re = 12.3;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a1b0c0) {
  double a = 1.0, b = 0.0, c = 0.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_ONE_SLN;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(an123b0c0) {
  double a = -12.3, b = 0.0, c = 0.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_ONE_SLN;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a1b0c1) {
  double a = 1.0, b = 0.0, c = 1.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_TWO_SLN;
  des.x1.Im = 1;
  des.x2.Im = -1;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a1b0cn1) {
  double a = 1.0, b = 0.0, c = -1.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_TWO_SLN;
  des.x1.Re = 1;
  des.x2.Re = -1;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a10b0c11) {
  double a = 10.0, b = 0.0, c = 11.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_TWO_SLN;
  des.x1.Im = 1.048809;
  des.x2.Im = -1.048809;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a10b0cn11) {
  double a = 10.0, b = 0.0, c = -11.0;
  answ_t des = {0}, out = {0};

  des.flag = QE_TWO_SLN;
  des.x1.Re = 1.048809;
  des.x2.Re = -1.048809;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(an12b0cn34) {
  double a = -1.2, b = 0.0, c = -3.4;
  answ_t des = {0}, out = {0};

  des.flag = QE_TWO_SLN;
  des.x1.Im = 1.683251;
  des.x2.Im = -1.683251;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a12b0cn34) {
  double a = 1.2, b = 0.0, c = -3.4;
  answ_t des = {0}, out = {0};

  des.flag = QE_TWO_SLN;
  des.x1.Re = 1.683251;
  des.x2.Re = -1.683251;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a1b1c0) {
  double a = 1.0, b = 1.0, c = 0.0;

  answ_t des = {0}, out = {0};

  des.flag = QE_TWO_SLN;
  des.x1.Re = 0;
  des.x2.Re = -1;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(an1b1c0) {
  double a = -1.0, b = 1.0, c = 0.0;

  answ_t des = {0}, out = {0};

  des.flag = QE_TWO_SLN;
  des.x1.Re = 0;
  des.x2.Re = 1;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a1b1c1) {
  double a = 1.0, b = 1.0, c = 1.0;

  answ_t des = {0}, out = {0};

  des.flag = QE_TWO_SLN;
  des.x1.Re = -0.5;
  des.x1.Im = 0.866025;
  des.x2.Re = -0.5;
  des.x2.Im = -0.866025;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a1b2c1) {
  double a = 1.0, b = 2.0, c = 1.0;

  answ_t des = {0}, out = {0};

  des.flag = QE_ONE_SLN;
  des.x1.Re = -1;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

START_TEST(a12b34c12) {
  double a = 1.2, b = 3.4, c = 1.2;

  answ_t des = {0}, out = {0};

  des.flag = QE_TWO_SLN;
  des.x1.Re = -0.413200;
  des.x2.Re = -2.420133;

  out = solve_equation(a, b, c);

  answ_compare(out, des);
}
END_TEST;

Suite *solve_equation_suite(void) {
  Suite *s = suite_create(" === SOLVE_EQUATION TESTS ===");

  TCase *tc;

  tc = tcase_create("Solve equation tcase");
  tcase_add_test(tc, a0b0c0);
  tcase_add_test(tc, a0b0c1);
  tcase_add_test(tc, a0b0cn1);
  tcase_add_test(tc, a0b1c0);
  tcase_add_test(tc, a0bn1c0);
  tcase_add_test(tc, a0b123c0);
  tcase_add_test(tc, a0bn123c0);
  tcase_add_test(tc, a0b1c1);
  tcase_add_test(tc, a0bn1c1);
  tcase_add_test(tc, a0bn1c123);
  tcase_add_test(tc, a1b0c0);
  tcase_add_test(tc, an123b0c0);
  tcase_add_test(tc, a1b0c1);
  tcase_add_test(tc, a1b0cn1);
  tcase_add_test(tc, a10b0c11);
  tcase_add_test(tc, a10b0cn11);
  tcase_add_test(tc, an12b0cn34);
  tcase_add_test(tc, a12b0cn34);
  tcase_add_test(tc, a1b1c0);
  tcase_add_test(tc, an1b1c0);
  tcase_add_test(tc, a1b1c1);
  tcase_add_test(tc, a1b2c1);
  tcase_add_test(tc, a12b34c12);
  suite_add_tcase(s, tc);

  return s;
}