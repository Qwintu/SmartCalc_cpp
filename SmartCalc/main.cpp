#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  CalcModel calc_model;
  CalcController calc_contr(&calc_model);

  DepositModel dep_model;
  DepositController dep_contr(&dep_model);

  CreditModel cred_model;
  CreditController cred_contr(&cred_model);

  MainWindow w(&dep_contr, &cred_contr, &calc_contr);

  w.setFixedSize(541, 592);
  w.show();
  return a.exec();
}
