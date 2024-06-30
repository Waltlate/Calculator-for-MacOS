#include <gtest/gtest.h>

#include <iostream>

#include "../SimpleCalculMy/Model/model.h"

TEST(Calculator, plus_1) {
  std::string argv = "1+1";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 2.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, plus_2) {
  std::string argv = "1.333333+1.333333";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 2.666666;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, plus_3) {
  std::string argv = "+1.333333";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  // ASSERT_EQ(result.first, 0);
  double origin = 1.333333;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, minus_1) {
  std::string argv = "1-1";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, minus_2) {
  std::string argv = "1.333333-1.333333";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, minus_3) {
  std::string argv = "-1.333333";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = -1.333333;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, minus_4) {
  std::string argv = "0.0-1.333333";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = -1.333333;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, mul_1) {
  std::string argv = "1*1";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, mul_2) {
  std::string argv = "1.333333*1.333333";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.777776;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, mul_3) {
  std::string argv = "0.0*1.333333";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, del_1) {
  std::string argv = "0.0/1.333333";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, del_2) {
  std::string argv = "1.0/1.333333";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.750000;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, del_3) {
  std::string argv = "1.546374/1.333333";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.159780;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, del_4) {
  std::string argv = "1.546374/1.0";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.546374;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, pov_1) {
  std::string argv = "1.546374^1.0";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.546374;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, pov_2) {
  std::string argv = "2.0^2.0";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 4.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, pov_3) {
  std::string argv = "2.0^2.566";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 5.921653;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, pov_4) {
  std::string argv = "0.0^2.566";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, mod_1) {
  std::string argv = "1mod3";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, mod_2) {
  std::string argv = "14562mod3.8456";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 2.5584;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, sin_1) {
  std::string argv = "sin(3)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.141120;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, sin_2) {
  std::string argv = "sin(0.0)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, sin_3) {
  std::string argv = "sin(3.14)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.001592;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, cos_1) {
  std::string argv = "cos(3)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = -0.989992;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, cos_2) {
  std::string argv = "cos(0.0)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, cos_3) {
  std::string argv = "cos(3.14)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = -0.9999987;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, tan_1) {
  std::string argv = "tan(3)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = -0.142547;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, tan_2) {
  std::string argv = "tan(0.0)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, tan_3) {
  std::string argv = "tan(3.14)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = -0.001592;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, asin_1) {
  std::string argv = "asin(1)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.57079633;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, asin_2) {
  std::string argv = "asin(0.0)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, asin_3) {
  std::string argv = "asin(0.567)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.602859;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, acos_1) {
  std::string argv = "acos(1)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, acos_2) {
  std::string argv = "acos(0.0)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.570796;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, acos_3) {
  std::string argv = "acos(0.567)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.967937;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, atan_1) {
  std::string argv = "atan(1)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.785398163;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, atan_2) {
  std::string argv = "atan(0.0)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, atan_3) {
  std::string argv = "atan(0.567)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.515801;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, sqrt_1) {
  std::string argv = "sqrt(1.0)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, sqrt_2) {
  std::string argv = "sqrt(6.25)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 2.5;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, sqrt_3) {
  std::string argv = "sqrt(12567.347)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 112.104179;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, ln_1) {
  std::string argv = "ln(1.0)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, ln_2) {
  std::string argv = "ln(2.7)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.993252;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, ln_3) {
  std::string argv = "ln(12567.347)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 9.438857;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, log_1) {
  std::string argv = "log(1.0)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, log_2) {
  std::string argv = "log(10.0)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, log_3) {
  std::string argv = "log(12567.347)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 4.099243;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, complicated_1) {
  std::string argv = "sqrt(4)+5^2*3-12+sin(0)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 65.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

// TEST( Calculator,  complicated_2) {

//   std::string argv = "1/0";
//   double x = 1.0;
//   calcul::Model np;
//   std::pair<int, double> result = np.calcul_calc_result(argv, x);
//   ASSERT_EQ(result.first, 0);
//   double origin = 1 / 0;
//   // ASSERT_LT(abs(result.second - origin), 0.000001);
//   ASSERT_EQ(result, origin);
// }

// TEST( Calculator,  complicated_3) {
//
//   std::string argv = "1/0*0";
//   double x = 1.0;
//   calcul::Model np;
//   std::pair<int, double> result = np.calcul_calc_result(argv, x);
//   ASSERT_EQ(result.first, 0);
//   double origin = 65.0;
//   ASSERT_LT(abs(result.second - origin), 0.000001);
// }

TEST(Calculator, complicated_4) {
  std::string argv = "sin(cos(345))";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.744034;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, complicated_5) {
  std::string argv = "cos(1+2+3*(3^3)*sqrt(9)mod2*sin(3))";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = -1.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, complicated_6) {
  std::string argv = "cos(10)^2+sin(10)^2";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, complicated_7) {
  std::string argv = "cos(x)^2+sin(x)^2";
  double x = 10.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, complicated_8) {
  std::string argv = "x*x";
  double x = 10.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 100.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, complicated_9) {
  std::string argv = "cos(1+2+x*(x^x)*sqrt(9)mod2*sin(x))";
  double x = 3.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = -1.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, complicated_10) {
  std::string argv = "1";
  double x = 3.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1.0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, complicated_11) {
  std::string argv = ".1";
  double x = 3.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 0.1;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, complicated_12) {
  std::string argv = "1e-5";
  double x = 3.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, 0);
  double origin = 1e-5;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_1) {
  std::string argv = "a";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::undef_symbol_or_func);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_2) {
  std::string argv = "!";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::undef_symbol_or_func);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_3) {
  std::string argv = "sinn(3)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::undef_symbol_or_func);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_4) {
  std::string argv = "4..4+";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::multy_num);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

// TEST(Calculator, error_5) {
//   std::string argv = "2+3\0+5";
//   std::cout << argv.length() << std::endl;
//   double x = 1.0;
//   calcul::Model np;
//   std::pair<int, double> result = np.CalcResult(argv, x);
//   ASSERT_EQ(result.first, (int)calcul::Err::no_error);
//   double origin = 5;
//   ASSERT_LT(abs(result.second - origin), 0.000001);
// }

TEST(Calculator, error_5) {
  std::string argv = "(2+3))";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::brackets);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_6) {
  std::string argv = "2++3";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::not_enough_arg);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_7) {
  std::string argv = "(2++3)";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::not_enough_arg);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_8) {
  std::string argv = "sqrt()";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::not_enough_arg);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_9) {
  std::string argv = "67.67.67+3";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::multy_num);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_10) {
  std::string argv = "2-3*";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::not_enough_arg);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_11) {
  std::string argv = "x.x";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::multy_num);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_12) {
  std::string argv = "1+x.x";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::multy_num);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_13) {
  std::string argv = "1+xx";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::multy_num);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_14) {
  std::string argv = "++/";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::not_enough_arg);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_15) {
  std::string argv = "(3)6";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::multy_num);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

TEST(Calculator, error_16) {
  std::string argv = ",";
  double x = 1.0;
  calcul::Model np;
  std::pair<int, double> result = np.CalcResult(argv, x);
  ASSERT_EQ(result.first, (int)calcul::Err::undef_symbol_or_func);
  double origin = 0;
  ASSERT_LT(abs(result.second - origin), 0.000001);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
