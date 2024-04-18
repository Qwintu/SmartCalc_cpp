#ifndef DEP_CONTROLLER_H
#define DEP_CONTROLLER_H


#include "deposit_model.h"

class DepositController {
    public:
        DepositController(DepositModel *d_m):dep_model_(d_m) {std::cout << "contrl constr\n";};

        void SetAmountToModel(double amount);
        void SetInterestRateToModel(double rate);
        void SetTotMonthsToModel(int months);
        void SetTaxRateToModel(double rate);
        void SetCalculationTypeToModel(int type);
        void SetDepDaysToModel(int days);
        // void SetPeriodicityIndxToModel(int indx);
        // void SetCapitalizationIndxToModel(int indx);

        void CalcDeposit();

        double GetPercentsFromModel();
        double GetTotalAmountFromModel();
        double GetTotalTaxesFromModel();



        void print() { std::cout << "contr\n";};
        void print_mod() {
            std::cout << "\npr_contr_mod -> ";
            dep_model_->print();
        };
    private:
        DepositModel *dep_model_;
        // CreditModel *credit_model;
        // CalcModel *calc_model;

        // ExampleModel *model;
};


#endif // DEP_CONTROLLER_H


        // void SetDepAmount(double amount);
        // void SetInterestRate(double rate);
        // void SetTotMonths(int months);
        // void SetTaxRate(double rate);
        // void SetPeriodicityIndx(int indx);
        // void SetCapitalizationIndx(int indx);

        // double GetTotalPercents();
        // double GetTotalAmount();
        // double GetTaxes();