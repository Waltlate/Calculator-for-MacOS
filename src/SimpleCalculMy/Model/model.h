#ifndef S21_SMARTCALC_V2_0_MODEL_MODEL_H_
#define S21_SMARTCALC_V2_0_MODEL_MODEL_H_

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>

namespace calcul {

enum class Funcs : char {
  sinus = 1,
  cosinus,
  tangens,
  asinus,
  acosinus,
  atangens,
  square,
  ln,
  mod,
  logarifm,
  unary_minus,
  unary_plus
};

enum class Err {
  no_error = 0,
  undef_symbol_or_func = 1,
  brackets = 2,
  not_enough_arg = 3,
  multy_num = 4
};

struct Token {
  bool is_numeric = true;
  char function_cod = 0;
  double num = 0;
  int priory = 0;
};

class Model {
 public:
  std::pair<int, double> CalcResult(const std::string argv, const double x);
  void ClearList();
  const Err CheckBrackets(const std::string str) const;
  void ExtractDoubleWords(const std::string str, int &position);
  void ExtractOpAndFun(std::string::const_iterator current_elem,
                       const std::string str, const double x,
                       std::string &substr, int &count, Err &error,
                       bool is_begin);
  const bool IsOperation(const char op, const double x);
  const bool IsFunc(const std::string substr);
  const Err Parsing(const std::string str, const double x);
  const double Result(const double x, Err &error);
  void ProcessingOperations(const Token op_and_num_front, Err &error);
  const int Prior(const char op) const;
  void MultyAbsorb1(Token op_view, Err &error);
  void MultyAbsorb2(Token op_view, const Token op_and_num_front, Err &error);
  const bool CheckBinary(const char op) const;
  const Err Absorb(const bool binary);
  const double Calculation(const double num1, const double num2,
                           const char op) const;
  void FinalCalc(Err &error);

 private:
  std::queue<Token> op_and_num_;
  std::stack<Token> num_;
  std::stack<Token> op_;
  double result_ = 0;
};

}  // namespace calcul

#endif  // S21_SMARTCALC_V2_0_MODEL_MODEL_H_
