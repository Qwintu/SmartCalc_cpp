#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <qcustomplot.h>
#include "ui_plotwindow.h"

#include <QDebug>
//#include <QInfo>
#include <iostream>

#include "../Controllers/calc_controller.h"

#include <QDialog>
#include <QPrinter>

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QDialog {
  Q_OBJECT

 public:
  explicit PlotWindow(const QString &func_string, int rad_deg_flag, CalcController *calc_contr, QWidget *parent = nullptr);
  ~PlotWindow();

 private slots:
  void replot_pic();
  void rangeChanged(QCPRange);

 private:
  Ui::PlotWindow *ui;
  QCustomPlot *myPlot;
  void DrawPlot();
  void setFunc();
  void TakeXYRange();
  void setRadDeg();

  QString func_string;
  int rad_deg;
  double x_min;
  double x_max;
  double y_min;
  double y_max;

  CalcController *calc_controller_;

};

#endif  // PLOTWINDOW_H
