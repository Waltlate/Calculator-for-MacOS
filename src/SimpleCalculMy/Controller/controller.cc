#include "controller.h"

std::pair<int, double> calcul::Controller::Equal(const std::string str,
                                                 const char* x) {
  sscanf(x, "%lf", &x_);
  return model_.CalcResult(str, x_);
}

std::pair<QVector<double>, QVector<double>> calcul::Controller::Grath(
    const std::string str, const double x_begin, const double x_end) {
  QVector<double> x, y;
  double step = 0.1;
  for (x_ = x_begin; x_ <= x_end; x_ += step) {
    x.push_back(x_);
    y.push_back(model_.CalcResult(str, x_).second);
  }
  std::pair<QVector<double>, QVector<double>> coordinates;
  coordinates.first = x;
  coordinates.second = y;
  return coordinates;
}