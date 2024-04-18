#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(DepositController *dep_contr, CreditController *cred_contr, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), dep_controller_(dep_contr), cred_controller_(cred_contr) {
  ui->setupUi(this);

  ui->scrollArea->setWidget(ui->display);
  
  loan_term_lst << "1 month"
                << "3 months"
                << "6 months"
                << "9 months"
                << "1 year"
                << "2 years"
                << "3 years"
                << "5 years"
                << "10 years"
                << "15 years";
  ui->loan_term_comboBox->addItems(loan_term_lst);
  ui->loan_term_comboBox->setCurrentIndex(4);

  dep_term_lst << "1 month"
               << "3 months"
               << "6 months"
               << "9 months"
               << "1 year"
               << "2 years"
               << "3 years";
  ui->dep_term_comboBox->addItems(dep_term_lst);
  ui->dep_term_comboBox->setCurrentIndex(4);

  ui->dep_Periodicity_comboBox->addItems({"choose", "monthly", "at the end" /*, "yearly" */});
  ui->dep_capitalization_comboBox->addItems(QStringList() << "choose"
                                                          << "yes"
                                                          << "no");

  connect(ui->Button_0, SIGNAL(clicked()), this, SLOT(pushButton_dig()));
  connect(ui->Button_1, SIGNAL(clicked()), this, SLOT(pushButton_dig()));
  connect(ui->Button_2, SIGNAL(clicked()), this, SLOT(pushButton_dig()));
  connect(ui->Button_3, SIGNAL(clicked()), this, SLOT(pushButton_dig()));
  connect(ui->Button_4, SIGNAL(clicked()), this, SLOT(pushButton_dig()));
  connect(ui->Button_5, SIGNAL(clicked()), this, SLOT(pushButton_dig()));
  connect(ui->Button_6, SIGNAL(clicked()), this, SLOT(pushButton_dig()));
  connect(ui->Button_7, SIGNAL(clicked()), this, SLOT(pushButton_dig()));
  connect(ui->Button_8, SIGNAL(clicked()), this, SLOT(pushButton_dig()));
  connect(ui->Button_9, SIGNAL(clicked()), this, SLOT(pushButton_dig()));

  connect(ui->Button_x, SIGNAL(clicked()), this, SLOT(pushButton_x()));
  connect(ui->Button_to_x, SIGNAL(clicked()), this, SLOT(pushButton_to_x()));
  connect(ui->Button_from_x, SIGNAL(clicked()), this,
          SLOT(pushButton_from_x()));
  connect(ui->Button_clean_x, SIGNAL(clicked()), this,
          SLOT(pushButton_clean_x()));

  connect(ui->Button_dot, SIGNAL(clicked()), this, SLOT(pushButton_dot()));
  connect(ui->Button_equals, SIGNAL(clicked()), this,
          SLOT(pushButton_equals()));

  connect(ui->Button_sin, SIGNAL(clicked()), this,
          SLOT(pushButton_trig_func()));
  connect(ui->Button_cos, SIGNAL(clicked()), this,
          SLOT(pushButton_trig_func()));
  connect(ui->Button_tan, SIGNAL(clicked()), this,
          SLOT(pushButton_trig_func()));
  connect(ui->Button_asin, SIGNAL(clicked()), this,
          SLOT(pushButton_trig_func()));
  connect(ui->Button_acos, SIGNAL(clicked()), this,
          SLOT(pushButton_trig_func()));
  connect(ui->Button_atan, SIGNAL(clicked()), this,
          SLOT(pushButton_trig_func()));

  connect(ui->Button_ln, SIGNAL(clicked()), this, SLOT(pushButton_ln()));
  connect(ui->Button_log10, SIGNAL(clicked()), this, SLOT(pushButton_log10()));
  connect(ui->Button_mod, SIGNAL(clicked()), this, SLOT(pushButton_mod()));
  connect(ui->Button_pow, SIGNAL(clicked()), this, SLOT(pushButton_pow()));
  connect(ui->Button_sqrt, SIGNAL(clicked()), this, SLOT(pushButton_sqrt()));

  connect(ui->Button_clean, SIGNAL(clicked()), this, SLOT(pushButton_clean()));

  connect(ui->Button_plus, SIGNAL(clicked()), this,
          SLOT(pushButton_plus_minus()));
  connect(ui->Button_minus, SIGNAL(clicked()), this,
          SLOT(pushButton_plus_minus()));
  connect(ui->Button_dev, SIGNAL(clicked()), this, SLOT(pushButton_mult_dev()));
  connect(ui->Button_mult, SIGNAL(clicked()), this,
          SLOT(pushButton_mult_dev()));

  connect(ui->Button_br_open, SIGNAL(clicked()), this,
          SLOT(pushButton_br_open()));
  connect(ui->Button_br_close, SIGNAL(clicked()), this,
          SLOT(pushButton_br_close()));

  connect(ui->Button_u_minus, SIGNAL(clicked()), this,
          SLOT(pushButton_u_minus()));

  connect(ui->Button_plot, SIGNAL(clicked()), this, SLOT(pushButton_plot()));

  connect(ui->calculate_credit_Button, SIGNAL(clicked()), this,
          SLOT(pushButton_calc_loan()));
  connect(ui->dep_calc_pushButton, SIGNAL(clicked()), this,
          SLOT(pushButton_calc_dep()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::pushButton_clean() {
  prev_char = '0';
  ui->display->setText("0");
  ui->error_field->setText("");
}

void MainWindow::pushButton_dig() {
  if (ui->display->text().length() + 1 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  ui->error_field->setText("");
  if (ui->display->text() == "0" || prev_char == '0') {
    ui->display->setText("");
  };
  QPushButton *button = (QPushButton *)sender();
  QString string;
  if (!strchr("x)", prev_char)) {
    string = ui->display->text() + button->text();
    prev_char = '9';
    ui->display->setText(string);
  } else {
    return;
  }
}

void MainWindow::pushButton_x() {
  if (ui->display->text().length() + 1 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  if (ui->display->text() == "0" || prev_char == '0') {
    ui->display->setText("");
    prev_char = '+';
  };
  QString string;
  if (!strchr("9.x)", prev_char)) {
    string = ui->display->text() + 'x';
    prev_char = 'x';
    ui->display->setText(string);
  } else {
    return;
  }
}

void MainWindow::pushButton_to_x() {
  bool ok;
  double dbl;
  dbl = QString(ui->display->text()).toDouble(&ok);
  if (ok) {
    QString num;
    num.setNum(dbl, 'g', 15);
    ui->x_field->setText(num);
  } else {
    ui->error_field->setText("(х) может быть только числом");
    return;
  }
}

void MainWindow::pushButton_from_x() {
  bool ok;
  QString(ui->display->text()).toDouble(&ok);
  if (ok) {
    ui->display->setText("");
    prev_char = '+';
  }
  //    if(ui->display->text() == "0") {ui -> display -> setText("");};
  QString x_value = ui->x_field->text();
  if (!strchr("x)9", prev_char)) {
    QString string;
    string = ui->display->text() + x_value;
    prev_char = '9';
    ui->display->setText(string);
  } else {
    return;
  }
}

void MainWindow::pushButton_clean_x() { ui->x_field->setText("0"); }

void MainWindow::pushButton_dot() {
  if (ui->display->text().length() + 1 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  if (ui->display->text() == "0" || prev_char == '0') ui->display->setText("");
  if (ui->display->text() == "" && prev_char == '9') ui->display->setText("0");
  //    if(strchr("+-*/d(", prev_char)) ui -> display -> setText("0");
  QString string;
  std::string input_string = ui->display->text().toStdString();
  if (is_dot(input_string.c_str())) {
    return;
  } else {
    if (prev_char == ')' || prev_char == 'x') {
      return;
    } else if (prev_char != '9') {
      string = ui->display->text() + "0.";
    } else {
      string = ui->display->text() + '.';
    }
  };
  prev_char = '.';
  ui->display->setText(string);
}

void MainWindow::pushButton_equals() {
  if (strchr("+*^d(", prev_char)) return;
  QString string;
  double x = 0;
  x = QString(ui->x_field->text()).toDouble();
  std::string input_string = ui->display->text().toStdString();

  int error_code = 0;

  if (!is_brackets_correct(input_string.c_str())) {
    error_code++;
    printf("Неправильно стоят скобки\n");
  }

  if (!check_errors_in_sterng(input_string.c_str())) {
    error_code += 10;
    printf("Errors in expression");
  };

  if (error_code == 0) {
    double result = calc_input_string(input_string.c_str(), x);
    ui->error_field->setText("");
    //        if(qIsNaN(result) || result == INFINITY || result == -INFINITY){
    if (!isfinite(result)) {
      //            ui->display->setText("ERROR");
      ui->error_field->setText("ERROR");
      prev_char = '0';
    } else {
      string = QString::number(result, 'g', 15);
      prev_char = '0';
      ui->display->setText(string);
    }
  } else if (error_code == 1) {
    ui->error_field->setText("Неправильно стоят скобки");
  } else if (error_code == 10) {
    ui->error_field->setText("Ошибка в выражении");
  } else if (error_code == 11) {
    ui->error_field->setText("Неправильно стоят скобки \nОшибка в выражении");
  }
}

void MainWindow::pushButton_trig_func() {
  if (ui->display->text().length() + 5 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  if (strchr("9x.)", prev_char)) return;
  if (ui->display->text() == "0" || prev_char == '0') {
    ui->display->setText("");
  };
  QPushButton *button = (QPushButton *)sender();
  QString string;
  string = ui->display->text() + button->text() + "(";
  prev_char = '(';
  ui->display->setText(string);
}

void MainWindow::pushButton_ln() {
  if (ui->display->text().length() + 3 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  if (strchr("9x.)", prev_char)) return;
  if (ui->display->text() == "0" || prev_char == '0') {
    ui->display->setText("");
  };
  QString string;
  string = ui->display->text() + "ln(";
  prev_char = '(';
  ui->display->setText(string);
}

void MainWindow::pushButton_log10() {
  if (ui->display->text().length() + 4 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  if (strchr("9x.)", prev_char)) return;
  if (ui->display->text() == "0" || prev_char == '0') {
    ui->display->setText("");
  };
  QString string;
  string = ui->display->text() + "log(";
  prev_char = '(';
  ui->display->setText(string);
}

void MainWindow::pushButton_sqrt() {
  if (ui->display->text().length() + 5 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  if (strchr("9x.)", prev_char)) return;
  if (ui->display->text() == "0" || prev_char == '0') {
    ui->display->setText("");
  };
  QString string;
  string = ui->display->text() + "sqrt(";
  prev_char = '(';
  ui->display->setText(string);
}

void MainWindow::pushButton_mod() {
  if (ui->display->text().length() + 4 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  if (prev_char != '9' && prev_char != 'x') return;
  if (prev_char == '0') {
    ui->display->setText("");
  };
  QString string;
  string = ui->display->text() + "mod";
  prev_char = 'd';
  ui->display->setText(string);
}

void MainWindow::pushButton_pow() {
  if (ui->display->text().length() + 2 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  if (prev_char != '9' && prev_char != 'x' && prev_char != '0') return;
  //    if(ui->display->text() == "0") {ui -> display -> setText("");};
  QString string;
  string = ui->display->text() + "^";
  prev_char = '^';
  ui->display->setText(string);
}

void MainWindow::pushButton_mult_dev() {
  if (ui->display->text().length() + 2 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  QString string;
  string = ui->display->text();
  if (strchr("d^(", prev_char)) return;
  if (string.size() >= 2 && (prev_char == '+' && *(string.end() - 2) == '(')) return;
  if (prev_char == '+' || prev_char == '*')
    ui->display->setText(ui->display->text().remove(-1, 1));
  QPushButton *button = (QPushButton *)sender();
//  QString string;
  string = ui->display->text() + button->text();
  prev_char = '*';
  ui->display->setText(string);
}

void MainWindow::pushButton_plus_minus() {
  if (ui->display->text().length() + 2 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  if (prev_char == 'd' || prev_char == '^') return;
  if (ui->display->text() == "0") {
    ui->display->setText("");
  };
  if (prev_char == '+' || prev_char == '*')
    ui->display->setText(ui->display->text().remove(-1, 1));
  QPushButton *button = (QPushButton *)sender();
  QString string;
  string = ui->display->text() + button->text();
  prev_char = '+';
  ui->display->setText(string);
}

void MainWindow::pushButton_br_open() {
  if (ui->display->text().length() + 1 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  };
  if (strchr("9x)", prev_char)) return;
  if (ui->display->text() == "0" || prev_char == '0') {
    ui->display->setText("");
  };
  QPushButton *button = (QPushButton *)sender();
  QString string;
  string = ui->display->text() + button->text();
  prev_char = '(';
  ui->display->setText(string);
}

void MainWindow::pushButton_br_close() {
  if (ui->display->text().length() + 1 > 255) {
    ui->error_field->setText("Слишком длинное выражение");
    return;
  }
  if (strchr("+*(d^", prev_char)) return;
  if (ui->display->text() == "0") {
    ui->display->setText("");
  };
  QPushButton *button = (QPushButton *)sender();
  QString string;
  string = ui->display->text() + button->text();
  prev_char = ')';
  ui->display->setText(string);
}

void MainWindow::pushButton_u_minus() {
  bool ok;
  double dbl;
  dbl = QString(ui->display->text()).toDouble(&ok);
  if (ok) {
    dbl = -dbl;
    QString num;
    num.setNum(dbl, 'g', 15);
    ui->display->setText(num);
  } else {
    return;
  }
}
void MainWindow::clean_errors() { ui->error_field->setText(""); }

void MainWindow::pushButton_plot() {
  if (strchr("+*^d(", prev_char)) return;

  std::string input_string = ui->display->text().toStdString();

  int error_code = 0;

  if (!is_brackets_correct(input_string.c_str())) {  // Неправильно стоят скобки
    error_code++;
  }

  if (!check_errors_in_sterng(input_string.c_str())) {  // Errors in expression
    error_code += 10;
  };

  if (error_code == 0) {
    plot = new PlotWindow(ui->display->text());
    plot->setFixedSize(811, 811);
    prev_char = '0';
    plot->show();
  } else if (error_code == 1) {
    ui->error_field->setText("Неправильно стоят скобки");
  } else if (error_code == 10) {
    ui->error_field->setText("Ошибка в выражении");
  } else if (error_code == 11) {
    ui->error_field->setText("Неправильно стоят скобки \nОшибка в выражении");
  }
}

// __________Credit calc________

void MainWindow::pushButton_calc_loan() {
  int error_code = 0;

  double loan_amount = ui->loan_amount_SpinBox->value();
  double interest_rate = ui->interest_rate_SpinBox->value();
  int cred_type = ui->diff_radioButton->isChecked();

  int month_indx = ui->loan_term_comboBox->currentIndex();
  int months_list[] = {1, 3, 6, 9, 12, 24, 36, 60, 120, 180};
  int total_months = months_list[month_indx];
//      ui->schedule_plainTextEdit->appendPlainText(QString::number(months));




  double balance_after_payment = loan_amount;
  double payment_monthly = 0;
  double overpayment = 0;
  double total_payment = 0;

  ui->schedule_plainTextEdit->setPlainText("");
  ui->result_label->setText("");

  if (qFuzzyCompare(loan_amount, 0.0)) {
    error_code++;
    ui->schedule_plainTextEdit->appendPlainText("Loan amoun can't be zero\n");
  }
  if (qFuzzyCompare(interest_rate, 0.0)) {
    error_code++;
    ui->schedule_plainTextEdit->appendPlainText("Interest rate can't be zero\n");
  }
  if (!ui->ann_radioButton->isChecked() && !ui->diff_radioButton->isChecked()) {
    error_code++;
    ui->schedule_plainTextEdit->appendPlainText("Select type of payment\n");
  }
  if (error_code > 0) return;


  // right version
  // cred_controller_->CreateInputDataObj();
  // cred_controller_->CreateOutputDataObj();
  // cred_controller_->SetLoanAmount(loan_amount);
  // cred_controller_->SetInterestRate(interest_rate);
  // cred_controller_->SetTotalMonths(total_months);
  // cred_controller_->SetCredType(cred_type);
  // CreditOutputData output_data = cred_controller_->CalcCredit();

  CreditOutputData output_data = cred_controller_->CalcCredit(loan_amount, interest_rate, total_months, cred_type);


  if (ui->ann_radioButton->isChecked()) {
    //         Заготовка для графика платежей
//            ui->schedule_plainTextEdit->appendPlainText("Month\tPayment\tBalance after payment");
//            for(size_t i = 0; i < total_months; i++){
//                payment_monthly = ann_payment(balance_after_payment, interest_rate, total_months - i);
//                balance_after_payment -= payment_monthly;
//                ui->schedule_plainTextEdit->appendPlainText(QString::number(i+ 1) + "\t" + QString::number(payment_monthly)+ "\t" + QString::number(balance_after_payment));
//            }


    //  Вызываем метод из контроллера
    // cred_ann_payment(balance_after_payment, interest_rate, total_months);

    payment_monthly = ann_payment(balance_after_payment, interest_rate, total_months);
    total_payment = total_months * payment_monthly;
    overpayment = total_payment - loan_amount;

    ui->result_label->setText(
        QString("Monthly payment: " + QString::number(payment_monthly, 'f', 2) +
                ", Overpayment: " + QString::number(overpayment, 'f', 2) +
                ", Total payment: " + QString::number(total_payment, 'f', 2)));
    ui->schedule_plainTextEdit->appendPlainText(
        QString("Monthly payment: " + QString::number(payment_monthly, 'f', 2) +
                "\nOverpayment: " + QString::number(overpayment, 'f', 2) +
                "\nTotal payment: " + QString::number(total_payment, 'f', 2)));
  }

  if (ui->diff_radioButton->isChecked()) {
    double percents_monthly = 0;
    double main_part_payment = loan_amount / total_months;

    total_payment = total_months * payment_monthly;
    ui->schedule_plainTextEdit->appendPlainText(
        "Month\tPayment\tPercents\tbalance_after_payment");

    for (int i = 0; i < total_months; i++) {
      percents_monthly = diff_payment_percents(balance_after_payment, interest_rate);
      balance_after_payment -= main_part_payment;
      payment_monthly = percents_monthly + main_part_payment;
      total_payment += payment_monthly;
      ui->schedule_plainTextEdit->appendPlainText(
          QString(QString::number(i + 1) + "\t" +
                  QString::number(payment_monthly, 'f', 2) + "\t" +
                  QString::number(percents_monthly, 'f', 2) + "\t" +
                  QString::number(balance_after_payment, 'f', 2)));
    }

ui->schedule_plainTextEdit->appendPlainText("\n\n");

    for (int i = 0; i < total_months; i++) {
        ui->schedule_plainTextEdit->appendPlainText(
            QString(QString::number(output_data.GetCredPaymentSchdlMonth(i)) + "\t" +
                    QString::number(output_data.GetCredPaymentSchdlPayment(i), 'f', 2) + "\t" +
                    QString::number(output_data.GetCredPaymentSchdlPercents(i), 'f', 2) + "\t" +
                    QString::number(output_data.GetCredPaymentSchdlBalance(i), 'f', 2))
                    );
    }



    overpayment = total_payment - loan_amount;
    ui->result_label->setText(
            "Total payment: " + QString::number(total_payment, 'f', 2) +
            ", Overpayment: " + QString::number(overpayment, 'f', 2) +
            "   g " + QString::number(output_data.GetCredPaymentSchdlBalance(1)) + "\n" +

        "Total payment: " + QString::number(output_data.GetTotalPayment(), 'f', 2) +
        ", Overpayment: " + QString::number(output_data.GetOverpayment(), 'f', 2)
        );

  }
}



// __________Deposit calc________

void MainWindow::pushButton_calc_dep() {
  // clean errors
  ui->dep_am_label->setStyleSheet("");
  ui->dep_ir_label->setStyleSheet("");
  ui->dep_tax_label->setStyleSheet("");
  ui->dep_period_label->setStyleSheet("");
  ui->dep_capitalization_label->setStyleSheet("");
  ui->dep_error_label->setText("");

  // clean results
  ui->dep_last_day_label->setText("");
  ui->dep_res_interest->setText("");
  ui->dep_res_total->setText("");
  ui->dep_res_tax->setText("");


  int dep_month_indx = ui->dep_term_comboBox->currentIndex();
  int months_list[] = {1, 3, 6, 9, 12, 24, 36};
  int total_months = months_list[dep_month_indx];

  double dep_amount = ui->dep_amount_SpinBox->value();
  double dep_interest_rate = ui->dep_Interest_rate_SpinBox->value();
  double dep_tax_rate = ui->dep_tax_rate_SpinBox->value();

  int periodicity_indx = ui->dep_Periodicity_comboBox->currentIndex();
  int capitalization_indx = ui->dep_capitalization_comboBox->currentIndex();


  int error_code = 0;
  if (qFuzzyCompare(dep_amount, 0.0)) {
    error_code++;
    ui->dep_am_label->setStyleSheet("QLabel { color : red; }");
  }
  if (qFuzzyCompare(dep_interest_rate, 0.0)) {
    error_code++;
    ui->dep_ir_label->setStyleSheet("QLabel { color : red; }");
  }
  if (qFuzzyCompare(dep_tax_rate, 0.0)) {
    error_code++;
    ui->dep_tax_label->setStyleSheet("QLabel { color : red; }");
  }
  if (periodicity_indx == 0) {
    error_code++;
    ui->dep_period_label->setStyleSheet("QLabel { color : red; }");
  }
  if (capitalization_indx == 0) {
    error_code++;
    ui->dep_capitalization_label->setStyleSheet("QLabel { color : red; }");
  }
  if (error_code > 0) {
    ui->dep_error_label->setStyleSheet("QLabel { color : red; }");
    ui->dep_error_label->setText("Fill all fields correctly");
    return;
  }


  int calculation_type = 0;
  if (periodicity_indx == 1 && capitalization_indx == 1) {
    calculation_type = 1;
  } else if (periodicity_indx == 1 && capitalization_indx == 2) {
    calculation_type = 2;
  } else if (periodicity_indx == 2 && capitalization_indx == 1) {
    calculation_type = 1;
  } else if (periodicity_indx == 2 && capitalization_indx == 2) {
    calculation_type = 2;
  }

  QDateTime today_date;
  QDateTime last_date;
  today_date = QDateTime::currentDateTime();

  last_date = today_date.addMonths(total_months).addDays(-1);
//  last_date = last_date.addDays(-1);
  ui->dep_last_day_label->setText(last_date.toString("dd.MM.yyyy"));

  int dep_days = 0;
  dep_days = today_date.daysTo(last_date);


  dep_controller_->SetAmountToModel(dep_amount);
  dep_controller_->SetInterestRateToModel(dep_interest_rate);
  dep_controller_->SetTaxRateToModel(dep_tax_rate);

  dep_controller_->SetTotMonthsToModel(total_months);
  dep_controller_->SetDepDaysToModel(dep_days);
  dep_controller_->SetCalculationTypeToModel(calculation_type);

  qDebug() << "days " << dep_days;
  qDebug() << "months " << total_months;
  qDebug() << "calc t " << calculation_type;
  qDebug() << today_date.toString("dd.MM.yyyy  HH:MM:ss");
  qDebug() << last_date.toString("dd.MM.yyyy  HH:MM:ss");


  dep_controller_->CalcDeposit();

  double dep_total_amount = dep_controller_->GetTotalAmountFromModel();
  double dep_total_percents = dep_controller_->GetPercentsFromModel();
  double taxes = dep_controller_->GetTotalTaxesFromModel();

  ui->dep_res_interest->setText(QString::number(dep_total_percents, 'f', 2));
  ui->dep_res_total->setText(QString::number(dep_total_amount, 'f', 2));
  ui->dep_res_tax->setText(QString::number(taxes, 'f', 2));
}





