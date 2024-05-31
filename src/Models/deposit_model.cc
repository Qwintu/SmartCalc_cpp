#include "deposit_model.h"

// Set
void DepositModel::SetTotMonths(int months) {
    total_months_ = months;
}

void DepositModel::SetDepAmount(double amount) {
    dep_amount_ = amount;
}

void DepositModel::SetInterestRate(double interest_rate) {
    dep_interest_rate_ = interest_rate;
}

void DepositModel::SetTaxRate(double tax_rate) {
    dep_tax_rate_ = tax_rate;
}

void DepositModel::SetCalculationType(int calc_type) {
    calculation_type_ = calc_type;
}
void DepositModel::SetDepDays(int days) {
    dep_days_ = days;
}

// Get
double DepositModel::GetTotalPercents() {
    return dep_total_percents_;
}

double DepositModel::GetTotalAmount() {
    return this -> dep_total_amount_;
}

double DepositModel::GetTaxes() {
    return this -> dep_taxes_;
}

// calc
void DepositModel::CalcDepositData() {
    dep_total_percents_ = CalcDepositPersents();
    dep_taxes_ = CalcDepositTaxes();
    dep_total_amount_ = CalcDepositAmount();
}


double DepositModel::CalcDepositPersents() {
  double persents = 0;
  double monthly_persents = 0;
  double temp_dep_amount = dep_amount_;

  if (calculation_type_ == 1) {
    for (int i = 0; i < total_months_; i++) {
      monthly_persents =
          ((temp_dep_amount * (dep_interest_rate_ / 100)) / 365) * 30.4;
      persents += monthly_persents;
      temp_dep_amount += monthly_persents;
    }

  } else if (calculation_type_ == 2) {
    persents = ((dep_amount_ * (dep_interest_rate_ / 100)) / 365) * dep_days_;
  }
  return persents;
}

double DepositModel::CalcDepositTaxes() {
    return dep_total_percents_ * (dep_tax_rate_ / 100);
}

double DepositModel::CalcDepositAmount() {
    // if(calculation_type_ != 1)
        return dep_amount_ + dep_total_percents_;
    // else
    //     return
}


void DepositModel::print() { std::cout << "from model: " << total_months_ << "  " << dep_amount_ << "  " << dep_interest_rate_ << "  " << dep_tax_rate_ << "  " << calculation_type_ << "  " << dep_days_;}
