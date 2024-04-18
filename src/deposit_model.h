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

        // int periodicity_indx_ {0};
        // int capitalization_indx_ {0};
        // int dep_month_indx_ {0};
        // const std::vector months_list<int> {1, 3, 6, 9, 12, 24, 36};
        
        // output
        double dep_total_percents_ {0};
        double dep_total_amount_ {0};
        double dep_taxes_ {0};

        double calc_deposit_persents();
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
        
        // void SetPeriodicityIndx(int indx);
        // void SetCapitalizationIndx(int indx);

        double GetTotalPercents();
        double GetTotalAmount();
        double GetTaxes();

        void print();
        
};


#endif // DEPOSIT_MODEL_H

// QT_PLUGIN_PATH to /usr/local/Cellar/qt/6.6.1/share/qt/plugins

        
        // int total_months = months_list[dep_month_indx];
        // double dep_amount = ui->dep_amount_SpinBox->value();
        // double dep_interest_rate = ui->dep_Interest_rate_SpinBox->value();
        // double dep_tax_rate = ui->dep_tax_rate_SpinBox->value();
        // int periodicity_indx = ui->dep_Periodicity_comboBox->currentIndex();
        // int capitalization_indx = ui->dep_capitalization_comboBox->currentIndex();



