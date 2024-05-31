#ifndef CALC_CONTR_H
#define CALC_CONTR_H

#include <string>
#include "../Models/calc_model.h"

class CalcController {
private:
    CalcModel* calc_model_;
public:
    CalcController(CalcModel* calc_model) : calc_model_ (calc_model) {std::cout << calc_model_ << "Calc contrl constr\n";};
    int isBracketsCorrect(std::string input_str);
    void SetXtoModel(double x);
    void SetStringToModel(std::string input_str);
    void SetRadDegMode(int rad_deg);
    double CalcExpr();
};

#endif // CALC_CONTR_H