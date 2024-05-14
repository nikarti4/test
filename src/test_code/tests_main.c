#include "quadratic_equation_test.h"

int main() {
  int fail = 0;

  Suite *s;
  SRunner *runner;

  s = solve_equation_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  fail = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (fail == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}