#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(DepositController *dep_contr, CreditController *cred_contr, CalcController *calc_contr, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), dep_controller_(dep_contr), cred_controller_(cred_contr), calc_controller_(calc_contr) {
  ui->setupUi(this);

  ui->scrollArea->setWidget(ui->display);
  qApp->setStyleSheet("QPushButton { border: 1px solid rgb(150, 150, 150); border-radius: 4px }" "QPushButton:pressed {background-color: #336699}");
  ui->Button_equals->setStyleSheet("QPushButton:pressed {background-color: #FF708A}");
  //  ui->Button_equals->setStyleSheet("border: 1px solid #F5DFD1;");
//  #3393FF   #FF708A

  del_int_list.push_back(0);
  prev_char_list.push_back('0');
//  equals_pressed = 0;
  
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
  connect(ui->Button_from_x, SIGNAL(clicked()), this, SLOT(pushButton_from_x()));
  connect(ui->Button_clean_x, SIGNAL(clicked()), this, SLOT(pushButton_clean_x()));

  connect(ui->Button_dot, SIGNAL(clicked()), this, SLOT(pushButton_dot()));
  connect(ui->Button_equals, SIGNAL(clicked()), this, SLOT(pushButton_equals()));

  connect(ui->Button_sin, SIGNAL(clicked()), this, SLOT(pushButton_trig_func()));
  connect(ui->Button_cos, SIGNAL(clicked()), this, SLOT(pushButton_trig_func()));
  connect(ui->Button_tan, SIGNAL(clicked()), this, SLOT(pushButton_trig_func()));
  connect(ui->Button_asin, SIGNAL(clicked()), this, SLOT(pushButton_trig_func()));
  connect(ui->Button_acos, SIGNAL(clicked()), this, SLOT(pushButton_trig_func()));
  connect(ui->Button_atan, SIGNAL(clicked()), this, SLOT(pushButton_trig_func()));

  connect(ui->Button_ln, SIGNAL(clicked()), this, SLOT(pushButton_ln()));
  connect(ui->Button_log10, SIGNAL(clicked()), this, SLOT(pushButton_log10()));
  connect(ui->Button_mod, SIGNAL(clicked()), this, SLOT(pushButton_mod()));
  connect(ui->Button_pow, SIGNAL(clicked()), this, SLOT(pushButton_pow()));
  connect(ui->Button_sqrt, SIGNAL(clicked()), this, SLOT(pushButton_sqrt()));
  connect(ui->Button_pow_2, SIGNAL(clicked()), this, SLOT(pushButton_pow_2()));
  connect(ui->Button_1divX, SIGNAL(clicked()), this, SLOT(pushButton_1divX()));

  connect(ui->Button_clean, SIGNAL(clicked()), this, SLOT(pushButton_clean()));
  connect(ui->Button_del, SIGNAL(clicked()), this, SLOT(pushButton_del()));

  connect(ui->Button_plus, SIGNAL(clicked()), this, SLOT(pushButton_plus_minus()));
  connect(ui->Button_minus, SIGNAL(clicked()), this, SLOT(pushButton_plus_minus()));
  connect(ui->Button_dev, SIGNAL(clicked()), this, SLOT(pushButton_mult_dev()));
  connect(ui->Button_mult, SIGNAL(clicked()), this, SLOT(pushButton_mult_dev()));

  connect(ui->Button_br_open, SIGNAL(clicked()), this, SLOT(pushButton_br_open()));
  connect(ui->Button_br_close, SIGNAL(clicked()), this, SLOT(pushButton_br_close()));

  connect(ui->Button_u_minus, SIGNAL(clicked()), this, SLOT(pushButton_u_minus()));

  connect(ui->Button_plot, SIGNAL(clicked()), this, SLOT(pushButton_plot()));

  connect(ui->calculate_credit_Button, SIGNAL(clicked()), this, SLOT(pushButton_calc_loan()));
  connect(ui->dep_calc_pushButton, SIGNAL(clicked()), this, SLOT(pushButton_calc_dep()));

  connect(ui->Button_copy, SIGNAL(clicked()), this, SLOT(pushButton_copy()));
//  connect(ui->display, SIGNAL(textChanged()), this, SLOT(pushButton_copy()));

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::pushButton_clean() {
  ui->display->setText("0");
  ui->error_field->setText("");
  cleanStacks();
}

void MainWindow::pushButton_del() {
    if(del_int_list.back() == 0) {
//        ui->display->setText("0");
        return;
    }

  int del = del_int_list.back();

  // удаление "e+15" в случае научной нотации за одно нажатие
  if(ui->display->text().lastIndexOf('e', -1) != -1) {
      int e_pos = ui->display->text().lastIndexOf('e');
      e_pos = ui->display->text().length() - e_pos;
      ui->display->setText(ui->display->text().remove(-e_pos, e_pos));
      for(int i = 0; i < e_pos; i++) {
          del_int_list.pop_back();
          prev_char_list.pop_back();
      }
      equals_pressed = 0;
      return;
  }

  ui->display->setText(ui->display->text().remove(-del, del));   // (positoin, n char)

  del_int_list.pop_back();
  prev_char_list.pop_back();
  ui->error_field->setText("");

  qDebug() << del_int_list.back() << prev_char_list.back();

  if(del_int_list.back() == 0) {
      ui->display->setText("0");
  }

  if(ui->display->text() == "0") {
      cleanStacks();
      qDebug() << "cls " << prev_char_list.back();
  }
  equals_pressed = 0;
}

void MainWindow::pushButton_dig() {
  if (checkMaxDisplStringLength(1)) return;
  ui->error_field->setText("");
  if (ui->display->text() == "0" || prev_char_list.back() == '0') {
    ui->display->setText("");
  };
  if(equals_pressed) {
      ui->display->setText("");
      cleanStacks();
  }
  QPushButton *button = (QPushButton *)sender();
  QString string;
  if (!strchr("x)", prev_char_list.back())) {
    string = ui->display->text() + button->text();
    writeButtonInfo(1,'9');
    ui->display->setText(string);
  } else {
    return;
  }
}

void MainWindow::pushButton_x() {
  if (checkMaxDisplStringLength(1)) return;
  if (ui->display->text() == "0" || prev_char_list.back() == '0' || equals_pressed == 1) {
    ui->display->setText("");
    cleanStacks();
  };
  QString string;
  if (!strchr("9.x)0", prev_char_list.back()) || ui->display->text() == "") {
    string = ui->display->text() + 'x';
    writeButtonInfo(1,'x');
    ui->display->setText(string);
    equals_pressed = 0;
  } else {
    return;
  }
}

void MainWindow::pushButton_to_x() {
  bool ok;
  double dbl;
  dbl = QString(ui->display->text()).toDouble(&ok);
  qDebug() << "xx: " << dbl;
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
  double x = QString(ui->x_field->text()).toDouble();
  qDebug() << "xx: " << x;
  int br_flag = 0;
  if (ok) {
    ui->display->setText("");
    cleanStacks();
    prev_char_list.push_back('+');
  }
  QString x_value = ui->x_field->text();
  if (!strchr("x)90", prev_char_list.back())) {
    equals_pressed = 0;
    if (ok) prev_char_list.pop_back();
    QString string;
    if (strchr("+*", prev_char_list.back()) && x < 0){
        x_value = "(" + x_value + ")";
        br_flag = 1;
    };
    string = ui->display->text() + x_value;
    ui->display->setText(string);

    int res_len = x_value.length();
    if (br_flag) {
        res_len -= 2;
        del_int_list.push_back(1);
        prev_char_list.push_back('(');
    }
    if(x < 0) {
        res_len--;
        del_int_list.push_back(1);
        prev_char_list.push_back('+');
    }
    for(int i = 0; i < res_len; i++){
        del_int_list.push_back(1);
        prev_char_list.push_back('9');
    }
    if (br_flag) {
        del_int_list.push_back(1);
        prev_char_list.push_back(')');
    }
  } else {
    return;
  }
}

void MainWindow::pushButton_clean_x() { ui->x_field->setText("0"); }

void MainWindow::pushButton_dot() {
  QString display_string;
  display_string = ui->display->text();

  if (checkMaxDisplStringLength(1)) return;

  if (/*display_string == "0" ||*/ prev_char_list.back() == '0' || equals_pressed == 1) {
      ui->display->setText("");
      display_string = ui->display->text();
      cleanStacks();
  }

  QString output_string;
qDebug() << "prev_char " << prev_char_list.back() << " " << isDot(display_string);
  if (isDot(display_string)) {
    return;
  } else {
    if (prev_char_list.back() == ')' || prev_char_list.back() == 'x') {
      return;
    } else if ((prev_char_list.back() != '9' && prev_char_list.back() != '.') ||  equals_pressed == 1) {
      output_string = display_string + "0.";
      writeButtonInfo(1,'9');
      writeButtonInfo(1,'.');
    } else {
      output_string = display_string + '.';
      writeButtonInfo(1,'.');
    }
  };
  ui->display->setText(output_string);
}

int MainWindow::isDot(const QString string) {
  int error_code = 0;
  int str_len = string.length();
  std::string input_string = string.toStdString();
  for (; str_len >= 0; str_len--) {
    if (!strchr("0123456789", input_string[str_len])) {
      if (string[str_len] == '.') error_code = 1;
      break;
    };
  }
  return error_code;
}


void MainWindow::pushButton_equals() {
  std::string input_string = ui->display->text().toStdString();
  if(StringFinalCheck(input_string)) return;

  double x = 0;
  x = QString(ui->x_field->text()).toDouble();

  CheckRadDeg();
  double result = ResultCalc(input_string, x, rad_deg_flag);
  ResultShow(result);
  equals_pressed = 1;
  qDebug() << "y=  " << result;
}

double MainWindow::ResultCalc(std::string input_string, double x, int rad_deg_flag) {
//    CheckRadDeg();
    calc_controller_ -> SetXtoModel(x);
    calc_controller_ -> SetStringToModel(input_string);
    calc_controller_ ->SetRadDegMode(rad_deg_flag);
    double result = calc_controller_ ->CalcExpr();
    return result;
}

void MainWindow::ResultShow(double result) {
    QString string;
    ui->error_field->setText("");
    if (!isfinite(result)) {
      ui->error_field->setText("ERROR: " + QString::number(result, 'g', 10));
    } else {
      string = QString::number(result, 'g', 15);
      ui->display->setText(string);

      del_int_list.clear();
      prev_char_list.clear();
      del_int_list.push_back(0);
      prev_char_list.push_back('0');
      int res_len = string.length();
      if(result < 0) {
          res_len--;
          del_int_list.push_back(1);
          prev_char_list.push_back('+');
      }
      for(int i = 0; i < res_len; i++){
          del_int_list.push_back(1);
          prev_char_list.push_back('9');
      }
    }
}

int MainWindow::StringFinalCheck(std::string input_string) {
    int error_code = 0;

    if (strchr("+*^d(", prev_char_list.back())) error_code += 10;
    if (!calc_controller_ -> isBracketsCorrect(input_string.c_str())) error_code++;

    if (error_code == 1) {
    ui->error_field->setText("Неправильно стоят скобки");
    } else if (error_code == 10) {
    ui->error_field->setText("Ошибка в выражении");
    } else if (error_code == 11) {
    ui->error_field->setText("Неправильно стоят скобки \nОшибка в выражении");
    }
    return error_code > 0 ? 1 : 0;
}


void MainWindow::CheckRadDeg() {
    if (ui->radioButton_rad->isChecked()) {
        rad_deg_flag = 1;
    } else {
        rad_deg_flag = 0;
    };
}

void MainWindow::pushButton_trig_func() {
  QString display_string;
  display_string = ui->display->text();

  QPushButton *button = (QPushButton *)sender();

  if(tryCalcNumber(display_string, button->text()) && equals_pressed == 0) return;

  if (checkMaxDisplStringLength(5)) return;
  if (strchr("9x.)", prev_char_list.back())) return;
  if (display_string == "0" || prev_char_list.back() == '0') {
    ui->display->setText("");
    display_string = "";
  };

  QString string;
  string = display_string + button->text() + "(";
  writeButtonInfo(button->text().length() + 1,'(');
  ui->display->setText(string);
}

void MainWindow::pushButton_ln() {
  QString display_string;
  display_string = ui->display->text();
  if (checkMaxDisplStringLength(3)) return;

  if(tryCalcNumber(display_string, "ln")) return;

  if (strchr("9x.)", prev_char_list.back())) return;
  if (display_string == "0" || prev_char_list.back() == '0') {
    ui->display->setText("");
  };
  QString string;
  string = ui->display->text() + "ln(";
  writeButtonInfo(3,'(');
  ui->display->setText(string);
}

void MainWindow::pushButton_log10() {
  QString display_string;
  display_string = ui->display->text();
  if (checkMaxDisplStringLength(4)) return;

  if(tryCalcNumber(display_string, "log")) return;

  if (strchr("9x.)", prev_char_list.back())) return;
  if (display_string == "0" || prev_char_list.back() == '0') {
    ui->display->setText("");
  };
  QString string;
  string = ui->display->text() + "log(";
  writeButtonInfo(4,'(');
  ui->display->setText(string);
}

void MainWindow::pushButton_sqrt() {
  QString display_string;
  display_string = ui->display->text();
  if (checkMaxDisplStringLength(5)) return;

  if(tryCalcNumber(display_string, "sqrt")) return;

  if (strchr("9x.)", prev_char_list.back())) return;
  if (display_string == "0" || prev_char_list.back() == '0') {
    ui->display->setText("");
  };
  QString string;
  string = ui->display->text() + "sqrt(";
  writeButtonInfo(5,'(');
  ui->display->setText(string);
}

void MainWindow::pushButton_mod() {
  if (checkMaxDisplStringLength(4)) return;
  if (prev_char_list.back() != '9' && prev_char_list.back() != 'x') return;
  if (prev_char_list.back() == '0') {
    ui->display->setText("");
  };
  QString string;
  string = ui->display->text() + "mod";
  writeButtonInfo(3,'d');
  ui->display->setText(string);
  equals_pressed = 0;
}

void MainWindow::pushButton_pow() {
  if (checkMaxDisplStringLength(2)) return;
  if (prev_char_list.back() != '9' && prev_char_list.back() != 'x' && prev_char_list.back() != '0' && prev_char_list.back() != ')') return;

  QString string;
  string = ui->display->text() + "^";
  writeButtonInfo(1,'^');
  ui->display->setText(string);
  equals_pressed = 0;
}

void MainWindow::pushButton_pow_2() {
    QString display_string;
    display_string = ui->display->text();
    tryCalcNumber(display_string, display_string + "*");
    return;
}

void MainWindow::pushButton_1divX() {
    if (ui->display->text() == "0") {
      ui->error_field->setText("ERROR: Деление на ноль");
      return;
    };
    QString display_string;
    display_string = ui->display->text();
    tryCalcNumber(display_string, "1/");
    return;
}

void MainWindow::pushButton_mult_dev() {
  if (checkMaxDisplStringLength(2)) return;
  QString string;
  string = ui->display->text();
  if (strchr("d^(", prev_char_list.back())) return;
  if (string.size() >= 2 && (prev_char_list.back() == '+' && *(string.end() - 2) == '(')) return;
  if (string.size() == 1 && prev_char_list.back() == '+') return;
  if (prev_char_list.back() == '+' || prev_char_list.back() == '*') {
    ui->display->setText(ui->display->text().remove(-1, 1));
    del_int_list.pop_back();
    prev_char_list.pop_back();
  }
  QPushButton *button = (QPushButton *)sender();
  string = ui->display->text() + button->text();
  writeButtonInfo(1,'*');
  ui->display->setText(string);
  equals_pressed = 0;
}

void MainWindow::pushButton_plus_minus() {
    if (checkMaxDisplStringLength(2)) return;
  if (prev_char_list.back() == 'd' || prev_char_list.back() == '^') return;
  if (prev_char_list.back() == '0') {
    ui->display->setText("");
  };
  if (prev_char_list.back() == '+' || prev_char_list.back() == '*') {
    ui->display->setText(ui->display->text().remove(-1, 1));
    del_int_list.pop_back();
    prev_char_list.pop_back();
  }
  QPushButton *button = (QPushButton *)sender();
  QString string;
  string = ui->display->text() + button->text();
  writeButtonInfo(1,'+');
  ui->display->setText(string);
  equals_pressed = 0;
}

void MainWindow::pushButton_br_open() {
    if (checkMaxDisplStringLength(2)) return;
  if (strchr("9x)", prev_char_list.back())) return;
  if (ui->display->text() == "0" || prev_char_list.back() == '0') {
    ui->display->setText("");
  };
  QPushButton *button = (QPushButton *)sender();
  QString string;
  string = ui->display->text() + button->text();
  writeButtonInfo(1,'(');
  ui->display->setText(string);
}

void MainWindow::pushButton_br_close() {
    if (checkMaxDisplStringLength(1)) return;
  if (strchr("+*(d^0", prev_char_list.back())) return;
  if (ui->display->text() == "0") {
    ui->display->setText("");
  };
  QPushButton *button = (QPushButton *)sender();
  QString string;
  string = ui->display->text() + button->text();
  writeButtonInfo(1,')');
  ui->display->setText(string);
}

void MainWindow::pushButton_u_minus() {
  QString string;
  string = ui->display->text();
  bool ok;
  double dbl;
  dbl = string.toDouble(&ok);
  if (ok) {
    dbl = -dbl;
    QString num;
    num.setNum(dbl, 'g', 15);
    ui->display->setText(num);
  }
  if (string == 'x' || string == "+x"){
      if(prev_char_list.at(1) != '+') {
          prev_char_list.insert(1, '+');
          del_int_list.insert(1, 1);
      }
    ui->display->setText("-x");
    return;
  };
  if (string == "-x"){
    ui->display->setText("x");
    del_int_list.erase(del_int_list.begin() + 1);
    prev_char_list.erase(prev_char_list.begin() + 1);
    return;
  };
}

void MainWindow::pushButton_plot() {
    std::string input_string = ui->display->text().toStdString();
    if(StringFinalCheck(input_string)) return;

    CheckRadDeg();
    plot = new PlotWindow(ui->display->text(), rad_deg_flag, calc_controller_);
    plot->setFixedSize(811, 811);
    plot->show();

    equals_pressed = 1;
}
void MainWindow::pushButton_copy() {
    // www.medo64.com/2019/12/copy-to-clipboard-in-qt/
    QClipboard* clipboard = QApplication::clipboard();
    QString copy_txt;
    copy_txt = ui->display->text();
    clipboard->setText(copy_txt, QClipboard::Clipboard);
    if (clipboard->supportsSelection()) {
        clipboard->setText(copy_txt, QClipboard::Selection);
    }

    #if defined(Q_OS_LINUX)
        QThread::msleep(1); //workaround for copied text not being available...
    #endif
}

int MainWindow::tryCalcNumber(QString display_string, QString func_string) {
    if (display_string == "nan") return 0;
    bool ok;
    double dbl;
    dbl = display_string.toDouble(&ok);
    if (ok && prev_char_list.back() != '0') {
        QString string;
        string = func_string +"(" + QString::number(dbl, 'f', 15) + ")" ;
        std::string input_string = string.toStdString();
        qDebug() << "str x: " << input_string;

        CheckRadDeg();
        double result = ResultCalc(input_string, 0, rad_deg_flag);
        ResultShow(result);

        equals_pressed = 1;
        return 1;
    };
    return 0;
}

void MainWindow::writeButtonInfo(int input_length, char btn_char) {
    del_int_list.push_back(input_length);
    prev_char_list.push_back(btn_char);
}

void MainWindow::cleanErrors() { ui->error_field->setText(""); }

void MainWindow::cleanStacks() {
    del_int_list.clear();
    prev_char_list.clear();
    del_int_list.push_back(0);
    prev_char_list.push_back('0');
    equals_pressed = 0;
}

int MainWindow::checkMaxDisplStringLength(int but_len) {
    if(ui->display->text().length() + but_len > 255) {
        ui->error_field->setText("Слишком длинное выражение");
        return 1;
    };
    return 0;
}


// __________Credit calc________

void MainWindow::pushButton_calc_loan() {

  double loan_amount = ui->loan_amount_SpinBox->value();
  double interest_rate = ui->interest_rate_SpinBox->value();
  int cred_type = ui->diff_radioButton->isChecked();

  int month_indx = ui->loan_term_comboBox->currentIndex();
  int months_list[] = {1, 3, 6, 9, 12, 24, 36, 60, 120, 180};
  int total_months = months_list[month_indx];


  ui->schedule_plainTextEdit->setPlainText("");
  ui->result_label->setText("");

  int error_code = 0;
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

  // --- ann --------
  if (ui->ann_radioButton->isChecked()) {
    ui->result_label->setText(
                "Total payment: " + QString::number(output_data.GetTotalPayment(), 'f', 2) +
                ", Overpayment: " + QString::number(output_data.GetOverpayment(), 'f', 2) +
                ", Monthly payment: " + QString::number(output_data.GetMonthlyPayment(), 'f', 2)
                );
    PrintCredSchdl(output_data);
  }

  // --- diff --------
  if (ui->diff_radioButton->isChecked()) {
    ui->result_label->setText(
        "Total payment: " + QString::number(output_data.GetTotalPayment(), 'f', 2) +
        ", Overpayment: " + QString::number(output_data.GetOverpayment(), 'f', 2)
        );
    PrintCredSchdl(output_data);
  }
}

void MainWindow::PrintCredSchdl(CreditOutputData& output_data) {
    ui->schedule_plainTextEdit->appendPlainText("Month\tPayment\tPercents\tbalance_after_payment");
    int total_months {output_data.GetCredTotalMonths()};
    for (int i = 0; i < total_months; i++) {
        ui->schedule_plainTextEdit->appendPlainText(
            QString(QString::number(output_data.GetCredPaymentSchdlMonth(i)) + "\t" +
                    QString::number(output_data.GetCredPaymentSchdlPayment(i), 'f', 2) + "\t" +
                    QString::number(output_data.GetCredPaymentSchdlPercents(i), 'f', 2) + "\t" +
                    QString::number(output_data.GetCredPaymentSchdlBalance(i), 'f', 2))
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

  qDebug() << "days " << dep_days;
  qDebug() << "months " << total_months;
  qDebug() << "calc t " << calculation_type;
  qDebug() << today_date.toString("dd.MM.yyyy  HH:MM:ss");
  qDebug() << last_date.toString("dd.MM.yyyy  HH:MM:ss");

  dep_controller_->SetAmountToModel(dep_amount);
  dep_controller_->SetInterestRateToModel(dep_interest_rate);
  dep_controller_->SetTaxRateToModel(dep_tax_rate);

  dep_controller_->SetTotMonthsToModel(total_months);
  dep_controller_->SetDepDaysToModel(dep_days);
  dep_controller_->SetCalculationTypeToModel(calculation_type);

  dep_controller_->CalcDeposit();

  double dep_total_amount = dep_controller_->GetTotalAmountFromModel();
  double dep_total_percents = dep_controller_->GetPercentsFromModel();
  double taxes = dep_controller_->GetTotalTaxesFromModel();

  ui->dep_res_interest->setText(QString::number(dep_total_percents, 'f', 2));
  ui->dep_res_total->setText(QString::number(dep_total_amount, 'f', 2));
  ui->dep_res_tax->setText(QString::number(taxes, 'f', 2));
}
