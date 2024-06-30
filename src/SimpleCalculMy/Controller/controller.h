#ifndef S21_SMARTCALC_V2_0_CONTROLLER_CONTROLLER_H_
#define S21_SMARTCALC_V2_0_CONTROLLER_CONTROLLER_H_

#include <QMainWindow>
#include <cstring>

#include "Model/model.h"

namespace calcul {

class Controller {
 public:
  std::pair<int, double> Equal(const std::string str, const char* x);
  std::pair<QVector<double>, QVector<double>> Grath(const std::string str,
                                                    const double x_begin,
                                                    const double x_end);

 private:
  calcul::Model model_;
  double x_ = 0;
};

}  // namespace calcul

#endif  // S21_SMARTCALC_V2_0_CONTROLLER_CONTROLLER_H_
