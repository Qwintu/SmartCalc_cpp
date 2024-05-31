#ifndef CREDIT_CONTROLLER_H
#define CREDIT_CONTROLLER_H


#include <iostream>
#include <vector>
#include "../Models/credit_model.h"
#include "cred_output_data.h"
#include "cred_input_data.h"

class CreditController {
    public:
        CreditController(CreditModel *cred_model) : cred_model_ (cred_model) {std::cout << "cred contrl constr\n";};
        CreditOutputData CalcCredit(double cred_amaunt, double cred_int_rate, int months, int type);
    private:
        CreditModel *cred_model_;
        
};

#endif // CREDIT_CONTROLLER_H