#include "model.h"

std::pair<int, double> calcul::Model::CalcResult(const std::string argv,
                                                 const double x) {
  ClearList();
  std::pair<int, double> res = {0, 0};
  Err error = Err::no_error;
  if (static_cast<int>(error = CheckBrackets(argv)))
    return res = {static_cast<int>(error), 0};
  if (static_cast<int>(error = Parsing(argv, x)))
    return res = {static_cast<int>(error), 0};
  const double answer = Result(x, (Err &)error);
  if (static_cast<int>(error))
    return res = {static_cast<int>(error), 0};
  else
    return res = {static_cast<int>(error), answer};
}

void calcul::Model::ClearList() {
  while (!op_and_num_.empty()) {
    op_and_num_.pop();
  }
  while (!num_.empty()) {
    num_.pop();
  }
  while (!op_.empty()) {
    op_.pop();
  }
}

const calcul::Err calcul::Model::CheckBrackets(const std::string str) const {
  int pair_brackets = 0;
  Err error = Err::no_error;
  for (auto elem : str) {
    if (elem == '(') ++pair_brackets;
    if (elem == ')') --pair_brackets;
    if (pair_brackets < 0) {
      error = Err::brackets;
      break;
    }
  }
  return error;
}

const calcul::Err calcul::Model::Parsing(const std::string str,
                                         const double x) {
  int loc_pos = 0, count = 0;
  int position = 0;
  Err error = Err::no_error;
  std::string substr = "";
  for (auto it = str.begin(); it != str.end(); ++it) {
    if (loc_pos != position && position != -1) {
      it += position - loc_pos;
      loc_pos = position;
    }
    if ((std::isdigit(*it) || *it == '.') && count == 0) {
      ExtractDoubleWords(str, position);
    } else {
      ExtractOpAndFun(it, str, x, substr, count, error, it == str.begin());
      if (static_cast<int>(error)) return error;
      ++position;
    }
    if (position == -1) break;
    ++loc_pos;
  }
  if (count) return Err::undef_symbol_or_func;
  position = 0;
  return error;
}

void calcul::Model::ExtractDoubleWords(const std::string str, int &position) {
  std::istringstream iss{std::string(str)};
  int alt_position = position;
  Token t_num;
  iss.seekg(position, std::ios_base::beg);
  iss >> t_num.num;
  if (!iss.fail() || iss.eof()) {
    position = iss.tellg();
    op_and_num_.push(t_num);
  }
  if (alt_position == position) {
    ++position;
    t_num.num = 0;
    op_and_num_.push(t_num);
  }
}

void calcul::Model::ExtractOpAndFun(std::string::const_iterator current_elem,
                                    const std::string str, const double x,
                                    std::string &substr, int &count, Err &error,
                                    bool is_begin) {
  if ((*current_elem == '-' || *current_elem == '+') &&
      (is_begin || (!is_begin && *(std::prev(current_elem)) == '('))) {
    Token new_op_or_num;
    new_op_or_num.is_numeric = false;
    if (*current_elem == '-')
      new_op_or_num.function_cod = static_cast<char>(Funcs::unary_minus);
    else
      new_op_or_num.function_cod = static_cast<char>(Funcs::unary_plus);
    op_and_num_.push(new_op_or_num);
  } else if (!IsOperation(*current_elem, x)) {
    substr.push_back(*current_elem);
    ++count;
    if (IsFunc(substr)) {
      count = 0;
      substr.clear();
    }
    if (count > 4) error = Err::undef_symbol_or_func;
  }
}

const bool calcul::Model::IsOperation(const char op, const double x) {
  bool check_op = false;
  if (op == '+' || op == '-' || op == '/' || op == '*' || op == '(' ||
      op == ')' || op == '^' || op == 'x') {
    Token new_op_or_num = {false, op, 0, Prior(op)};
    if (op == 'x') {
      new_op_or_num.num = x;
      new_op_or_num.is_numeric = true;
    }
    op_and_num_.push(new_op_or_num);
    check_op = true;
  }
  return check_op;
}

const bool calcul::Model::IsFunc(const std::string substr) {
  bool check_func = true;
  char func_cod;
  if (substr.length() == 2 && substr == "ln") {
    func_cod = static_cast<char>(Funcs::ln);
  } else if (substr.length() == 3 && substr == "sin") {
    func_cod = static_cast<char>(Funcs::sinus);
  } else if (substr.length() == 3 && substr == "cos") {
    func_cod = static_cast<char>(Funcs::cosinus);
  } else if (substr.length() == 3 && substr == "tan") {
    func_cod = static_cast<char>(Funcs::tangens);
  } else if (substr.length() == 3 && substr == "mod") {
    func_cod = static_cast<char>(Funcs::mod);
  } else if (substr.length() == 3 && substr == "log") {
    func_cod = static_cast<char>(Funcs::logarifm);
  } else if (substr.length() == 4 && substr == "asin") {
    func_cod = static_cast<char>(Funcs::asinus);
  } else if (substr.length() == 4 && substr == "acos") {
    func_cod = static_cast<char>(Funcs::acosinus);
  } else if (substr.length() == 4 && substr == "atan") {
    func_cod = static_cast<char>(Funcs::atangens);
  } else if (substr.length() == 4 && substr == "sqrt") {
    func_cod = static_cast<char>(Funcs::square);
  } else {
    check_func = false;
  }
  if (check_func) {
    Token new_op_or_num = {false, func_cod, 0, Prior(func_cod)};
    op_and_num_.push(new_op_or_num);
  }
  return check_func;
}

const double calcul::Model::Result(const double x, Err &error) {
  Token op_and_num_front;
  int count_num = 0;
  while (!op_and_num_.empty()) {
    op_and_num_front = op_and_num_.front();
    if (op_and_num_front.is_numeric) {
      ++count_num;
      if (count_num == 2) {
        error = Err::multy_num;
        break;
      }
      num_.push(op_and_num_front);
    } else {
      count_num = 0;
      ProcessingOperations(op_and_num_front, error);
    }
    op_and_num_.pop();
  }
  if (!static_cast<int>(error)) FinalCalc(error);
  return result_;
}

void calcul::Model::ProcessingOperations(const Token op_and_num_front,
                                         Err &error) {
  Token op_view;
  if (op_.empty()) {
    op_.push(op_and_num_front);
  } else {
    if (op_and_num_front.function_cod == '(' ||
        op_and_num_front.function_cod == ')') {
      if (op_and_num_front.function_cod == ')') {
        op_view = op_.top();
        MultyAbsorb1(op_view, error);
        op_.pop();
      } else {
        op_.push(op_and_num_front);
      }
    } else {
      op_view = op_.top();
      if (op_view.priory >= op_and_num_front.priory) {
        MultyAbsorb2(op_view, op_and_num_front, error);
      }
      op_.push(op_and_num_front);
    }
  }
}

const int calcul::Model::Prior(const char op) const {
  int priory = 4;
  if (op == '+' || op == '-') {
    priory = 1;
  } else if (op == static_cast<char>(Funcs::mod) || op == '*' || op == '/' ||
             op == static_cast<char>(Funcs::unary_minus) ||
             op == static_cast<char>(Funcs::unary_plus)) {
    priory = 2;
  } else if (op == '^') {
    priory = 3;
  } else if (op == '(' || op == ')') {
    priory = 0;
  }
  return priory;
}

void calcul::Model::MultyAbsorb1(Token op_view, Err &error) {
  while (op_view.function_cod != '(') {
    if (!num_.empty()) {
      if (static_cast<int>(error = Absorb(CheckBinary(op_view.function_cod))))
        break;
    } else {
      error = Err::not_enough_arg;
      break;
    }
    if (!op_.empty()) {
      op_view = op_.top();
    } else {
      break;
    }
  }
}

void calcul::Model::MultyAbsorb2(Token op_view, const Token op_and_num_front,
                                 Err &error) {
  while (op_view.priory >= op_and_num_front.priory) {
    if (!num_.empty()) {
      if (static_cast<int>(error = Absorb(CheckBinary(op_view.function_cod))))
        break;
    } else {
      error = Err::not_enough_arg;
      break;
    }
    if (!op_.empty()) {
      op_view = op_.top();
    } else {
      break;
    }
  }
}

const bool calcul::Model::CheckBinary(const char op) const {
  bool binary = false;
  if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' ||
      op == static_cast<int>(Funcs::mod)) {
    binary = true;
  }
  return binary;
}

const calcul::Err calcul::Model::Absorb(const bool binary) {
  double num_second = num_.top().num;
  if (num_.empty()) return Err::not_enough_arg;
  num_.pop();
  double num_first = 0.0;
  if (!num_.empty()) {
    num_first = num_.top().num;
  }
  if (binary) {
    if (num_.empty()) return Err::not_enough_arg;
    num_.pop();
  }
  result_ = Calculation(num_first, num_second, op_.top().function_cod);
  op_.pop();
  Token new_num;
  new_num.num = result_;
  num_.push(new_num);
  return Err::no_error;
}

const double calcul::Model::Calculation(const double num1, const double num2,
                                        const char op) const {
  if (op == '+') return num1 + num2;
  if (op == '-') return num1 - num2;
  if (op == '*') return num1 * num2;
  if (op == '/') return num1 / num2;
  if (op == '^') return pow(num1, num2);
  if (op == static_cast<char>(Funcs::mod)) return fmod(num1, num2);
  if (op == static_cast<char>(Funcs::square)) return sqrt(num2);
  if (op == static_cast<char>(Funcs::logarifm)) return log10(num2);
  if (op == static_cast<char>(Funcs::ln)) return log(num2);
  if (op == static_cast<char>(Funcs::sinus)) return sin(num2);
  if (op == static_cast<char>(Funcs::cosinus)) return cos(num2);
  if (op == static_cast<char>(Funcs::tangens)) return tan(num2);
  if (op == static_cast<char>(Funcs::asinus)) return asin(num2);
  if (op == static_cast<char>(Funcs::acosinus)) return acos(num2);
  if (op == static_cast<char>(Funcs::atangens)) return atan(num2);
  if (op == static_cast<char>(Funcs::unary_minus)) return -num2;
  if (op == static_cast<char>(Funcs::unary_plus)) return num2;
  return 0.0;
}

void calcul::Model::FinalCalc(Err &error) {
  while (!op_.empty()) {
    if (!num_.empty()) {
      if (static_cast<int>(error = Absorb(CheckBinary(op_.top().function_cod))))
        break;
    } else {
      error = Err::not_enough_arg;
      break;
    }
  }
  if (!num_.empty()) {
    if (num_.size() == 1) {
      result_ = num_.top().num;
    } else {
      error = Err::multy_num;
    }
  }
  while (!num_.empty()) {
    num_.pop();
  }
}
