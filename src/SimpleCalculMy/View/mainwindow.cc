#include "mainwindow.h"

View::View(QWidget *parent) : QMainWindow(parent), ui(new Ui::View) {
  ui->setupUi(this);
  ui->lineEdit->setText("");
  auto list_buttons = findChildren<QPushButton *>();
  for (QPushButton *button : list_buttons) {
    if (button != ui->Button_Equel && button != ui->Button_Reset &&
        button != ui->Button_Grath) {
      connect(button, SIGNAL(clicked()), this, SLOT(ButtonsDigitAndFuncs()));
    } else if (button == ui->Button_Equel) {
      connect(button, SIGNAL(clicked()), this, SLOT(ButtonEquel()));
    } else if (button == ui->Button_Reset) {
      connect(button, SIGNAL(clicked()), this, SLOT(ButtonReset()));
    } else if (button == ui->Button_Grath) {
      connect(button, SIGNAL(clicked()), this, SLOT(ButtonGrath()));
    }
  }
}

View::~View() { delete ui; }

void View::ButtonsDigitAndFuncs() {
  QPushButton *button = (QPushButton *)sender();
  ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

void View::ButtonReset() { ui->lineEdit->backspace(); }

void View::ButtonEquel() {
  res_ = controller_.Equal(ui->lineEdit->text().toStdString().c_str(),
                           ui->doubleSpinBox_X->text().toStdString().c_str());
  ui->lcdNumber->display(res_.second);
  ui->lineEdit->setText("");
  ui->textBrowser_errorlog->setText("");
  ErrorLog(res_.first);
}

void View::ErrorLog(const int error) {
  switch (error) {
    case 1:
      ui->textBrowser_errorlog->setText("нераспознаный символ или функция");
      break;
    case 2:
      ui->textBrowser_errorlog->setText("неправильное количество скобок");
      break;
    case 3:
      ui->textBrowser_errorlog->setText("недостаточное количество аргументов");
      break;
    case 4:
      ui->textBrowser_errorlog->setText(
          "остались числа для которых неопределены операции");
      break;
  }
}

void View::ButtonGrath() {
  ui->widget->xAxis->setRange(ui->doubleSpinBox_xmin->value(),
                              ui->doubleSpinBox_xmax->value());
  ui->widget->yAxis->setRange(ui->doubleSpinBox_ymin->value(),
                              ui->doubleSpinBox_ymax->value());
  std::pair<QVector<double>, QVector<double>> mas = controller_.Grath(
      ui->lineEdit->text().toStdString().c_str(),
      ui->doubleSpinBox_xmin->value(), ui->doubleSpinBox_xmax->value());
  ui->widget->clearGraphs();
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(mas.first, mas.second);
  ui->widget->replot();
}
