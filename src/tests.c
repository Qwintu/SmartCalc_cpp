#include <check.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "calc_lib.h"

START_TEST(simple_func) {
  char *string = "2+3-7*8+5/2";
  double result = calc_input_string(string, 0);
  double control = -48.5;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //
  string = "sin(90)";
  result = calc_input_string(string, 0);
  control = 1;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "cos(45)";
  result = calc_input_string(string, 0);
  control = 0.70710678118;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "tan(30)";
  result = calc_input_string(string, 0);
  control = 0.57735026;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "asin(0.36)";
  result = calc_input_string(string, 0);
  control = 21.10019602;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "acos(-0.56)";
  result = calc_input_string(string, 0);
  control = 124.0557977;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "atan(25.6)";
  result = calc_input_string(string, 0);
  control = 87.76302093;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "3.5^6.12";
  result = calc_input_string(string, 0);
  control = 2136.46819225;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "ln(25)";
  result = calc_input_string(string, 0);
  control = 3.21887582;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "log(15)";
  result = calc_input_string(string, 0);
  control = 1.17609125;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "sqrt(14.6)";
  result = calc_input_string(string, 0);
  control = 3.8209946;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "32mod21";
  result = calc_input_string(string, 0);
  control = 11;
  ck_assert_double_eq_tol(result, control, 1e-7);
}
END_TEST

//  --------------------------

START_TEST(long_func) {
  char *string = "-3+2*2/5-2/3^2+2.3^2/7*6-5+3^2";
  double result = calc_input_string(string, 0);
  double control = 6.1120634920;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "-(+53*sin(45)^2.1+147.62-0)";
  result = calc_input_string(string, 0);
  control = -173.217312717;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "2*((3+1*5)/4)";
  result = calc_input_string(string, 0);
  control = 4;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "+13+12.2*(-5+9^2*(3+5))-12.5/5+2.1*((+4.5+2^2)/4)";
  result = calc_input_string(string, 0);
  control = 7859.5625;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "sin(5+3)*sqrt(4*2)*2^tan(3)+sin(30)+cos(6^2)*ln(3+1)";
  result = calc_input_string(string, 0);
  control = 2.029739091;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "-sin((-30)-1)";
  result = calc_input_string(string, 0);
  control = 0.515038074;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "((2))";
  result = calc_input_string(string, 0);
  control = 2;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "-((2))";
  result = calc_input_string(string, 0);
  control = -2;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "-(-(2))";
  result = calc_input_string(string, 0);
  control = 2;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //
}
END_TEST

//  --------------------------

START_TEST(errors) {
  char *string = "log(-2)";
  double result = calc_input_string(string, 0);
  ck_assert_double_nan(result);

  //

  string = "sqrt(-2)";
  result = calc_input_string(string, 0);
  ck_assert_double_nan(result);

  //

  string = "asin(-20)";
  result = calc_input_string(string, 0);
  ck_assert_double_nan(result);

  //

  string = "1/0";
  result = calc_input_string(string, 0);
  ck_assert_double_infinite(result);
}
END_TEST

//  --------------------------

START_TEST(check_errors) {
  char *string = "sin((-30)-1)";
  int result = is_brackets_correct(string);
  ck_assert_int_eq(result, 1);

  //

  string = "sin)((-30)-1))";
  result = is_brackets_correct(string);
  ck_assert_int_eq(result, 0);

  //

  string = "((-30-1)";
  result = is_brackets_correct(string);
  ck_assert_int_eq(result, 0);

  //

  string = "(-3))+((-30)-1))";
  result = is_brackets_correct(string);
  ck_assert_int_eq(result, 0);

  //

  string = "3+3+36";
  result = is_brackets_correct(string);
  ck_assert_int_eq(result, 1);

  //

  string = "(/3+3)+36";
  result = check_errors_in_sterng(string);
  ck_assert_int_eq(result, 0);

  //

  string = "-";
  result = check_errors_in_sterng(string);
  ck_assert_int_eq(result, 0);

  //

  string = "3+3d+36";
  result = check_errors_in_sterng(string);
  ck_assert_int_eq(result, 0);

  //

  string = "*3+3)+36";
  result = check_errors_in_sterng(string);
  ck_assert_int_eq(result, 0);

  //

  string = "-";
  result = check_errors_in_sterng(string);
  ck_assert_int_eq(result, 0);

  //

  string = "12365";
  result = is_dot(string);
  ck_assert_int_eq(result, 0);

  //

  string = "(12.365";
  result = is_dot(string);
  ck_assert_int_eq(result, 1);

  //

  string = "0.";
  result = is_dot(string);
  ck_assert_int_eq(result, 1);

  //

  string = "(6))0.12365";
  result = is_dot(string);
  ck_assert_int_eq(result, 1);

  //

  string = "15+12365.";
  result = is_dot(string);
  ck_assert_int_eq(result, 1);

  //
}

//  --------------------------

START_TEST(set_x) {
  char *string = "sin(x)+sqrt(x)";
  double x = 90;
  double result = calc_input_string(string, x);
  double control = 10.486832980;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //

  string = "-x+(x)";
  x = 5.0;
  result = calc_input_string(string, x);
  control = 0;
  ck_assert_double_eq_tol(result, control, 1e-7);

  //
}

START_TEST(dep_calc) {
  double balance_after_payment = 100000;
  double interest_rate = 10;
  int months = 12;
  double result = ann_payment(balance_after_payment, interest_rate, months);
  double control = 8791.588723;
  ck_assert_double_eq_tol(result, control, 1e-5);

  //

  result = diff_payment_percents(balance_after_payment, interest_rate);
  control = 833.333333;
  ck_assert_double_eq_tol(result, control, 1e-5);

  //
}

START_TEST(credit_calc_calc) {
  double dep_amount = 100000;
  double dep_interest_rate = 10;
  int dep_days = 365;
  int months = 12;
  int calculation_type = 1;
  double result = calc_deposit_persents(dep_amount, dep_interest_rate, dep_days,
                                        months, calculation_type);
  double control = 10465.303698;
  ck_assert_double_eq_tol(result, control, 1e-5);

  //
}
// END_TEST

////////////////////////////////////////////////////////////////

Suite *smartcalc_suite(void) {
  Suite *s = suite_create("SmartCalc_testcase");
  TCase *tc_matrix = tcase_create("Core");

  suite_add_tcase(s, tc_matrix);
  tcase_add_test(tc_matrix, simple_func);
  tcase_add_test(tc_matrix, long_func);
  tcase_add_test(tc_matrix, errors);
  tcase_add_test(tc_matrix, check_errors);
  tcase_add_test(tc_matrix, set_x);
  tcase_add_test(tc_matrix, dep_calc);
  tcase_add_test(tc_matrix, credit_calc_calc);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = smartcalc_suite();
  sr = srunner_create(s);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}