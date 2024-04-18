#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "plotwindow.h"
#include "../deposit_controller.h"
#include "../credit_controller.h"

extern "C" {
#include "../calc_lib.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(DepositController *dep_contr, CreditController *cred_contr, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void pushButton_clean();
  void pushButton_dig();
  void pushButton_x();
  void pushButton_to_x();
  void pushButton_from_x();
  void pushButton_clean_x();
  void pushButton_dot();
  void pushButton_equals();
  void pushButton_trig_func();
  void pushButton_ln();
  void pushButton_log10();
  void pushButton_sqrt();
  void pushButton_mod();
  void pushButton_pow();
  void pushButton_mult_dev();
  void pushButton_plus_minus();
  void pushButton_br_open();
  void pushButton_br_close();
  void pushButton_u_minus();
  void clean_errors();
  void pushButton_plot();
  void pushButton_calc_loan();
  void pushButton_calc_dep();

 private:
  Ui::MainWindow *ui;
  PlotWindow *plot;
  char prev_char = '0';  // 0 - пустая строка, 9 - цифра, d - mod, + - +or-, '.'
                         // - dot, x - (x)

  QStringList loan_term_lst;
  QStringList dep_term_lst;

  DepositController *dep_controller_;
  CreditController *cred_controller_;
};
#endif  // MAINWINDOW_H
