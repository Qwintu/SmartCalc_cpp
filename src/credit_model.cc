#include <iostream>
#include "credit_model.h"

void CreditModel::CalcCreditOutput(CreditInputData *input_data, CreditOutputData *output_data) {
    const double amaunt = input_data->GetCredAmount();
    const double int_rate = input_data->GetCredIntRate();
    const int months = input_data->GetCredMonths();
    const int type = input_data->GetType();

// перенести в прайват
    // double monthly_payment {0};
    // double overpayment {0};
    // double total_payment {0};

std::cout << amaunt << std::endl;
std::cout << int_rate << std::endl;
std::cout << months << std::endl;
std::cout << type << std::endl;


    if(type) {
std::cout << "diff" << std::endl;
        CalcDiffPayment(amaunt, int_rate, months, *output_data);
    } else {
std::cout << "ann" << std::endl;

    // Думаем тут!!
    // перетащить формулу
    // дописываем тут!


    };



    // SetCredPaymentSchdl(int month, double payment, double percents, double balance) {

    output_data->SetMonthlyPayment(monthly_payment);
    // output_data->SetOverpayment(overpayment);
    // output_data->SetTotalPayment(total_payment);

    monthly_payment = 0;
    overpayment = 0;
    total_payment = 0;
};



void CreditModel::CalcDiffPayment(const double amount, const double int_rate, const int months, CreditOutputData &output_data) {
    double balance_after_payment {amount};
    double percents_monthly {0};
    double main_part_payment = amount / months;
    // total_payment = months * monthly_payment;

    // ui->schedule_plainTextEdit->appendPlainText("Month\tPayment\tPercents\tbalance_after_payment");

    for (int i = 0; i < months; i++) {
      percents_monthly = DiffPaymentPercents(balance_after_payment, int_rate);
      balance_after_payment -= main_part_payment;
      monthly_payment = percents_monthly + main_part_payment;
      total_payment += monthly_payment;
std::cout << i << " tt " << total_payment << std::endl;
      output_data.SetCredPaymentSchdl(i + 1, monthly_payment, percents_monthly, balance_after_payment);


    //   ui->schedule_plainTextEdit->appendPlainText(
    //       QString(QString::number(i + 1) + "\t" +
    //               QString::number(monthly_payment, 'f', 2) + "\t" +
    //               QString::number(percents_monthly, 'f', 2) + "\t" +
    //               QString::number(balance_after_payment, 'f', 2)));
    }

    overpayment = total_payment - amount;

    output_data.SetOverpayment(overpayment);
    output_data.SetTotalPayment(total_payment);

    // ui->result_label->setText(
    //     "Total payment: " + QString::number(total_payment, 'f', 2) +
    //     ", Overpayment: " + QString::number(overpayment, 'f', 2));

for (int i = 0; i < months; i++) {
  std::cout << i << " cc " << output_data.GetTotalPayment() << std::endl;
}

}

//---------
double CreditModel::DiffPaymentPercents(double balance_after_payment, double interest_rate) {
  double percents_monthly = 0;
  percents_monthly = (balance_after_payment * (interest_rate / 100)) / 12;
  return percents_monthly;
};





// ann from QT

double ann_payment(const double amount, const double int_rate, const int months, CreditOutputData &output_data) {
  double month_interest_rate = 0;
  month_interest_rate = int_rate / (100 * 12);
  double ann_payment = 0;
  double ann_coef = 0;

  ann_coef = (month_interest_rate / (1 - pow((1 + month_interest_rate), -months)));
  ann_payment = amount * ann_coef;

  // ___ временная ф-ция для вывода графика платежа в консоль. Потом переписать ее для вывода в программе.

  double temp_balance_after_payment = amount;
  double temp_ann_payment = ann_payment;
  double percents = 0;

  percents = temp_balance_after_payment * month_interest_rate;
  temp_balance_after_payment = temp_balance_after_payment - (temp_ann_payment - percents);
  printf("month\tmonthly payment\tpercents\t\tbalance_after_payment\n");
  printf("1\t%f\t%f\t\t%f\n", temp_ann_payment, percents, temp_balance_after_payment);

  for (int i = 0; i < months - 1; i++) {
    percents = temp_balance_after_payment * month_interest_rate;
    temp_balance_after_payment = temp_balance_after_payment - (temp_ann_payment - percents);

    printf("%d\t%f\t%f\t\t%f\n", i + 2, temp_ann_payment, percents, temp_balance_after_payment);
  }
  printf("\n\n");

  // ___end временная ф-ция____

  return ann_payment;
};
// ann из QT
    // payment_monthly = ann_payment(balance_after_payment, interest_rate, total_months);
    // total_payment = total_months * payment_monthly;
    // overpayment = total_payment - loan_amount;
