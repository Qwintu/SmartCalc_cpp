#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstring>

#include "plotwindow.h"
#include "../Controllers/deposit_controller.h"
#include "../Controllers/credit_controller.h"
#include "../Controllers/calc_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(DepositController *dep_contr, CreditController *cred_contr, CalcController *calc_contr, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void pushButton_clean();
  void pushButton_del();
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
  void pushButton_pow_2();
  void pushButton_1divX();
  void pushButton_mult_dev();
  void pushButton_plus_minus();
  void pushButton_br_open();
  void pushButton_br_close();
  void pushButton_u_minus();
  void cleanErrors();
  void pushButton_plot();
  void pushButton_calc_loan();
  void pushButton_calc_dep();
  void pushButton_copy();

 private:
  Ui::MainWindow *ui;
  PlotWindow *plot;
  int rad_deg_flag;
  int equals_pressed {0};

  int isDot(const QString string);
  void PrintCredSchdl(CreditOutputData&);
  void CheckRadDeg();
  int tryCalcNumber(QString display_string, QString func_string);
  void writeButtonInfo(int input_length, char btn_char);
  int StringFinalCheck(std::string input_string);
  double ResultCalc(std::string input_string, double x, int rad_deg_flag);
  void ResultShow(double result);
  void cleanStacks();
  int checkMaxDisplStringLength(int but_len);

  QList<int> del_int_list;
  QList<char> prev_char_list;  // 0 - начало, 9 - цифра, d - mod, + - +or-, '.' - dot, x - (x)

  QStringList loan_term_lst;
  QStringList dep_term_lst;

  DepositController *dep_controller_;
  CreditController *cred_controller_;
  CalcController *calc_controller_;
};
#endif  // MAINWINDOW_H
