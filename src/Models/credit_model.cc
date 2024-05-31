#include <iostream>
#include "credit_model.h"

void CreditModel::CalcCreditOutput(CreditInputData *input_data, CreditOutputData *output_data) {
    const double amount = input_data->GetCredAmount();
    const double int_rate = input_data->GetCredIntRate();
    const int months = input_data->GetCredMonths();
    const int type = input_data->GetType();

    if(type) {
      CalcDiffPayment(amount, int_rate, months, *output_data);
    } else {
      CalcAnnPayment(amount, int_rate, months, *output_data);
    };

    // SetCredPaymentSchdl(int month, double payment, double percents, double balance) {

    overpayment = total_payment - amount;
    output_data->SetMonthlyPayment(monthly_payment);
    output_data->SetOverpayment(overpayment);
    output_data->SetTotalPayment(total_payment);

    monthly_payment = 0;
    overpayment = 0;
    total_payment = 0;
};


// --- diff --------
void CreditModel::CalcDiffPayment(const double amount, const double int_rate, const int months, CreditOutputData &output_data) {
    double balance_after_payment {amount};
    double percents_monthly {0};
    double main_part_payment = amount / months;

    for (int i = 0; i < months; i++) {
      percents_monthly = DiffPaymentPercents(balance_after_payment, int_rate);
      balance_after_payment -= main_part_payment;
      monthly_payment = percents_monthly + main_part_payment;
      total_payment += monthly_payment;
std::cout << i << " dif_p " << total_payment << std::endl;
      output_data.SetCredPaymentSchdl(i + 1, monthly_payment, percents_monthly, balance_after_payment);
    }
}

double CreditModel::DiffPaymentPercents(double balance_after_payment, double interest_rate) {
  double percents_monthly = 0;
  percents_monthly = (balance_after_payment * (interest_rate / 100)) / 12;
  return percents_monthly;
};

//--- ann ------


void CreditModel::CalcAnnPayment(const double amount, const double int_rate, const int months, CreditOutputData &output_data) {
  double month_interest_rate = 0;
  month_interest_rate = int_rate / (100 * 12);
  double ann_coef = 0;

  ann_coef = (month_interest_rate / (1 - pow((1 + month_interest_rate), -months)));
  monthly_payment = amount * ann_coef;

  total_payment = months * monthly_payment;
  overpayment = total_payment - amount;

std::cout << "M_p " << monthly_payment << " o_p " << overpayment << "tp " << total_payment << std::endl;

  // ___ график платежей.
  double temp_balance_after_payment = amount;
  double percents_monthly = 0;

std::cout << "month_s\tmonthly payment\tpercents\tbalance_after_payment" << std::endl;
  for (int i = 0; i < months; i++) {
    percents_monthly = temp_balance_after_payment * month_interest_rate;
    temp_balance_after_payment = temp_balance_after_payment - (monthly_payment - percents_monthly);
std::cout << i + 1 << "\t" << monthly_payment << "\t\t" << percents_monthly << "\t" << temp_balance_after_payment << std::endl;
    output_data.SetCredPaymentSchdl(i + 1, monthly_payment, percents_monthly, temp_balance_after_payment);
  }
};
