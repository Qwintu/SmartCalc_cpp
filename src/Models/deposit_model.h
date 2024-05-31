#ifndef DEPOSIT_MODEL_H
#define DEPOSIT_MODEL_H

#include <iostream>

class DepositModel {
    private:
        // input data
        double dep_amount_ {0};
        double dep_interest_rate_ {0};
        int total_months_ {0};
        double dep_tax_rate_ {0};
        int calculation_type_ {0};
        int dep_days_ {0};
        
        // output
        double dep_total_percents_ {0};
        double dep_total_amount_ {0};
        double dep_taxes_ {0};

        double CalcDepositPersents();
        double CalcDepositTaxes();
        double CalcDepositAmount();

    public:
        DepositModel() {std::cout << "model constr\n";}
        
        void CalcDepositData();

        void SetDepAmount(double amount);
        void SetInterestRate(double rate);
        void SetTotMonths(int months);
        void SetTaxRate(double rate);
        void SetCalculationType(int calc_type);
        void SetDepDays(int days);
        
        double GetTotalPercents();
        double GetTotalAmount();
        double GetTaxes();

        void print();
        
};

#endif // DEPOSIT_MODEL_H
