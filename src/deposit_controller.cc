#include "deposit_controller.h"

void DepositController::SetAmountToModel(double amount) {
    dep_model_->SetDepAmount(amount);
};

void DepositController::SetInterestRateToModel(double rate) {
    dep_model_->SetInterestRate(rate);
};

void DepositController::SetTotMonthsToModel(int months) {
    dep_model_->SetTotMonths(months);
};

void DepositController::SetTaxRateToModel(double rate) {
    dep_model_->SetTaxRate(rate);
};

void DepositController::SetCalculationTypeToModel(int type) {
    dep_model_->SetCalculationType(type);
};

void DepositController::SetDepDaysToModel(int days) {
    dep_model_->SetDepDays(days);
}

void DepositController::CalcDeposit() {
    dep_model_->CalcDepositData();
}
// void DepositController::SetPeriodicityIndxToModel(int indx) {
//     dep_model_->SetPeriodicityIndx(indx);
// };

// void DepositController::SetCapitalizationIndxToModel(int indx) {
//     dep_model_->SetCapitalizationIndx(indx);
// };





double DepositController::GetPercentsFromModel() {
    return dep_model_->GetTotalPercents();
};

double DepositController::GetTotalAmountFromModel() {
    return dep_model_->GetTotalAmount();
};

double DepositController::GetTotalTaxesFromModel() {
    return dep_model_->GetTaxes();
};