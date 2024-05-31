#include "plotwindow.h"



PlotWindow::PlotWindow(const QString &func_string, int rad_deg_flag, CalcController *calc_contr, QWidget *parent) : QDialog(parent), ui(new Ui::PlotWindow), calc_controller_(calc_contr)  {
  ui->setupUi(this);
  ui->scrollArea->setWidget(ui->func_label);
  this->func_string = func_string;

  myPlot = new QCustomPlot();
  ui->plot_widget->addWidget(myPlot);

  myPlot->xAxis->setLabel("x");
  myPlot->yAxis->setLabel("y");
  myPlot->setInteraction(QCP::iRangeZoom, true);
  myPlot->setInteraction(QCP::iRangeDrag, true);
  myPlot->setAntialiasedElements(QCP::aeAll);

  rad_deg = rad_deg_flag;
  setRadDeg();
  setFunc();
  TakeXYRange();
  DrawPlot();

  connect(ui->Button_replot, SIGNAL(clicked()), this, SLOT(replot_pic()));
  connect(myPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(rangeChanged(QCPRange)));
//  connect(myPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(rangeChanged(QCPRange)));
}

PlotWindow::~PlotWindow() { delete ui; }

void PlotWindow::setRadDeg() {
    if(rad_deg) {
        ui->radio_rad ->setChecked(true);
    } else {
        ui->radio_deg ->setChecked(true);
    }
}

void PlotWindow::setFunc() {
  QString string;
  string = ui->func_label->text() + func_string;
  ui->func_label->setText(string);
}

void PlotWindow::TakeXYRange() {
  x_min = ui->spinBox_x_min->value();
  x_max = ui->spinBox_x_max->value();
  y_min = ui->spinBox_y_min->value();
  y_max = ui->spinBox_y_max->value();
  if(x_min > x_max) {
      std::swap(x_min, x_max);
      ui->spinBox_x_min->setValue(x_min);
      ui->spinBox_x_max->setValue(x_max);
  };
  if(y_min > y_max) {
      std::swap(y_min, y_max);
      ui->spinBox_y_max->setValue(y_max);
      ui->spinBox_y_min->setValue(y_min);
  }
}

void PlotWindow::DrawPlot() {
  int N_value = 150000;
  if(func_string.indexOf('x') == -1) N_value = 20000;
  QVector<double> x(N_value), y(N_value);
  double step = fabs((x_max - x_min)) / N_value;

  qInfo() << "!step " << step;

  rad_deg = ui->radio_rad->isChecked();
  calc_controller_ ->SetRadDegMode(rad_deg);
  calc_controller_ ->SetStringToModel(func_string.toStdString());

  double x_start = x_min;
  x[0] = x_start;

  for (int i = 0; i < N_value; ++i) {
    if (i != 0) x[i] = x[i - 1] + step;
    calc_controller_ ->SetXtoModel(x[i]);
    y[i] = calc_controller_ ->CalcExpr();
  }

  myPlot->xAxis->setRange(x_min, x_max);
  myPlot->yAxis->setRange(y_min, y_max);

  myPlot->addGraph();
  myPlot->graph(0)->setData(x, y);

  if (ui->radio_dots->isChecked()) {
    myPlot->graph(0)->setPen(QColor(50, 50, 50, 255));  //задаем цвет точки
    myPlot->graph(0)->setLineStyle(QCPGraph::lsNone);  //убираем линии
    myPlot->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssDisc, 1));  //формируем вид точек
  }
}

void PlotWindow::rangeChanged(QCPRange) {
    x_min = myPlot->xAxis->range().lower;
    x_max = myPlot->xAxis->range().upper;
    y_min = myPlot->yAxis->range().lower;
    y_max = myPlot->yAxis->range().upper;

    ui->spinBox_x_min->setValue(x_min);
    ui->spinBox_x_max->setValue(x_max);
    ui->spinBox_y_max->setValue(y_max);
    ui->spinBox_y_min->setValue(y_min);

    myPlot->removeGraph(0);
    DrawPlot();
    myPlot->replot();
}

void PlotWindow::replot_pic() {
  myPlot->removeGraph(0);
  TakeXYRange();
  DrawPlot();
  myPlot->replot();
}
