#ifndef CREDIT_OUTPUT_DATA_H
#define CREDIT_OUTPUT_DATA_H


#include <vector>

class CreditOutputData {
    public:
        void SetMonthlyPayment(double monthly_payment) {cred_monthly_payment_ =monthly_payment;};
        void SetOverpayment(double overpayment) {cred_overpayment_ = overpayment;};
        void SetTotalPayment(double total_payment) {cred_total_payment_ = total_payment;};

        double GetMonthlyPayment() {return cred_monthly_payment_;};
        double GetOverpayment() {return cred_overpayment_;};
        double GetTotalPayment() {return cred_total_payment_;};

        void SetCredPaymentSchdl(int month, double payment, double percents, double balance) {
            // first var
            cred_payment_schdl.push_back ({month, payment, percents, balance});

            // second var
            // cred_monthly_payment_data monthly_paymnt;
            // monthly_paymnt.month_no_ = month;
            // monthly_paymnt.payment_ = payment;
            // monthly_paymnt.percents_ = percents;
            // monthly_paymnt.balance_after_payment_ = balance;
            // cred_payment_schdl.push_back (monthly_paymnt);
        }
        int GetCredPaymentSchdlMonth(int i) {
            return cred_payment_schdl[i].month_no_;
        }
        double GetCredPaymentSchdlPayment(int i) {
            return cred_payment_schdl[i].payment_;
        }
        double GetCredPaymentSchdlPercents(int i) {
            return cred_payment_schdl[i].percents_;
        }
        double GetCredPaymentSchdlBalance(int i) {
            return cred_payment_schdl[i].balance_after_payment_;
        }
    
    private:
        double cred_monthly_payment_;
        double cred_overpayment_;
        double cred_total_payment_;

        struct cred_monthly_payment_data{
            int month_no_;
            double payment_;
            double percents_;
            double balance_after_payment_;
        };
        std::vector<cred_monthly_payment_data> cred_payment_schdl;
};

#endif // CREDIT_OUTPUT_DATA_H
