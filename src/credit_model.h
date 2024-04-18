#ifndef CREDIT_MODEL_H
#define CREDIT_MODEL_H

#include "cred_output_data.h"
#include "cred_input_data.h"

class CreditModel {
    public:
        void CalcCreditOutput(CreditInputData *input_data, CreditOutputData *output_data);
        void CalcDiffPayment(const double amount, const double int_rate, const int months, CreditOutputData &output_data);
        void CalcAnnPayment(const double amount, const double int_rate, const int months, CreditOutputData &output_data);

    private:
        double monthly_payment {0};
        double overpayment {0};
        double total_payment {0};

        double DiffPaymentPercents(double balance_after_payment, double interest_rate);
};

#endif // CREDIT_MODEL_H