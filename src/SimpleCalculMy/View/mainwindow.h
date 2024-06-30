#ifndef S21_SMARTCALC_V2_0_VIEW_MAINWINDOW_H_
#define S21_SMARTCALC_V2_0_VIEW_MAINWINDOW_H_

#include <QKeyEvent>
#include <QMainWindow>

#include "./ui_mainwindow.h"
#include "Controller/controller.h"
#include "View/qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace calcul {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow {
  Q_OBJECT

 public:
  View(QWidget *parent = nullptr);
  ~View();

 private slots:
  void ButtonsDigitAndFuncs();
  void ButtonEquel();
  void ButtonReset();
  void ButtonGrath();
  void ErrorLog(const int error);

 private:
  Ui::View *ui;
  calcul::Controller controller_;
  std::pair<int, double> res_;
};

#endif  // S21_SMARTCALC_V2_0_VIEW_MAINWINDOW_H_
