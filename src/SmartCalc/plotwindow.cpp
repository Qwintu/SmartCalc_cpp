#include "plotwindow.h"

#include <QDebug>
//#include <QInfo>
#include <iostream>

#include "ui_plotwindow.h"

PlotWindow::PlotWindow(const QString &func_string, QWidget *parent)
    : QDialog(parent), ui(new Ui::PlotWindow) {
  ui->setupUi(this);
  ui->scrollArea->setWidget(ui->func_label);
  this->func_string = func_string;

  myPlot = new QCustomPlot();
  ui->plot_widget->addWidget(myPlot);
  setFunc();
  TakeXYRange();
  DrawPlot();
  connect(ui->Button_replot, SIGNAL(clicked()), this, SLOT(replot_pic()));
}

PlotWindow::~PlotWindow() { delete ui; }

void PlotWindow::setFunc() {
  QString string;
  string = ui->func_label->text() + func_string;
  ui->func_label->setText(string);
}

void PlotWindow::DrawPlot() {
  int N_value = 250000;
  QVector<double> x(N_value), y(N_value);
  double x_start = x_range_min;
  double z = 0;
  //    if(x_range_min >= x_range_max) x_range_min = x_range_max;
  double step = fabs((x_range_max - x_range_min)) / N_value;
  x[0] = x_start;

  for (int i = 0; i < N_value; ++i) {
    if (i != 0) x[i] = x[i - 1] + step;
    z = x[i];
    if (ui->radio_rad->isChecked()) z = (x[i] * 180) / PI;
    y[i] = calc_input_string(func_string.toStdString().c_str(), z);
  }

  myPlot->addGraph();
  myPlot->graph(0)->setData(x, y);

  if (ui->radio_dots->isChecked()) {
    myPlot->graph(0)->setPen(QColor(50, 50, 50, 255));  //задаем цвет точки
    myPlot->graph(0)->setLineStyle(QCPGraph::lsNone);  //убираем линии
    //формируем вид точек
    myPlot->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
  }

  myPlot->xAxis->setLabel("x");
  myPlot->yAxis->setLabel("y");

  myPlot->xAxis->setRange(x_min, x_max);
  myPlot->yAxis->setRange(y_min, y_max);

  // qDebug() << "a " << myPlot->xAxis->range().lower;
  qInfo() << "a " << myPlot->xAxis->range().lower;
  double sss = myPlot->xAxis->range().lower;
  std::cout << "bb " << sss;
  //    ise slot/event -  rangeChanged
  //            double 	lower
  //            double 	upper

  myPlot->setInteraction(QCP::iRangeZoom, true);
  myPlot->setInteraction(QCP::iRangeDrag, true);
}

void PlotWindow::TakeXYRange() {
  x_min = ui->spinBox_x_min->value();
  x_max = ui->spinBox_x_max->value();
  y_min = ui->spinBox_y_min->value();
  y_max = ui->spinBox_y_max->value();
  x_range_min = ui->spinBox_x_range_min->value();
  x_range_max = ui->spinBox_x_range_max->value();
}
void PlotWindow::replot_pic() {
  myPlot->removeGraph(0);
  TakeXYRange();
  DrawPlot();
  myPlot->replot();
  std::cout << "aa ";
}
