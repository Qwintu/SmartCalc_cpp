#include "credit_controller.h"

CreditOutputData CreditController::CalcCredit(double cred_amaunt, double cred_int_rate, int months, int type) {
    CreditInputData input_data(cred_amaunt, cred_int_rate, months, type);
    CreditOutputData output_data;

    cred_model_->CalcCreditOutput(&input_data, &output_data);
      std::cout << "aa " << 4 << " " << cred_model_ << "\n";
      std::cout << " cnt " << output_data.GetCredPaymentSchdlBalance(1) << std::endl;
    return output_data;
}
