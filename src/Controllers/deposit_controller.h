#ifndef DEP_CONTROLLER_H
#define DEP_CONTROLLER_H


#include "../Models/deposit_model.h"

class DepositController {
    public:
        DepositController(DepositModel *d_m):dep_model_(d_m) {std::cout << "contrl constr\n";};

        void SetAmountToModel(double amount);
        void SetInterestRateToModel(double rate);
        void SetTotMonthsToModel(int months);
        void SetTaxRateToModel(double rate);
        void SetCalculationTypeToModel(int type);
        void SetDepDaysToModel(int days);

        void CalcDeposit();

        double GetPercentsFromModel();
        double GetTotalAmountFromModel();
        double GetTotalTaxesFromModel();

        void print_mod() {
            std::cout << "\npr_contr_mod -> ";
            dep_model_->print();
        };
    private:
        DepositModel *dep_model_;
};


#endif // DEP_CONTROLLER_H