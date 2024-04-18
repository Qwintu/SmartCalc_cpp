#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <qcustomplot.h>

#include <QDialog>
#include <QPrinter>
extern "C" {
#include "../calc_lib.h"
}

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QDialog {
  Q_OBJECT

 public:
  explicit PlotWindow(const QString &func_string, QWidget *parent = nullptr);
  ~PlotWindow();

 private slots:
  void replot_pic();

 private:
  Ui::PlotWindow *ui;
  QCustomPlot *myPlot;
  void DrawPlot();
  void setFunc();
  void TakeXYRange();

  QString func_string;
  int x_min;
  int x_max;
  int y_min;
  int y_max;
  int x_range_min;
  int x_range_max;
};

#endif  // PLOTWINDOW_H
