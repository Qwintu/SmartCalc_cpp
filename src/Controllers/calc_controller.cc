#include "calc_controller.h"    
    
    void CalcController::SetXtoModel(double x) {
        // std::cout << "Contr x: " << x << calc_model_ << std::endl;
        calc_model_->SetX(x);
    }
    
    void CalcController::SetStringToModel(std::string input_str) {
        //  std::cout << "Contr Str: " << input_str << std::endl;
        calc_model_->SetInputString(input_str);
    }

    void CalcController::SetRadDegMode(int rad_deg) {
        //  std::cout << "Contr RadDeg: " << rad_deg << std::endl;
        calc_model_->SetRadDeg(rad_deg);
    }

    double CalcController::CalcExpr() {
        double y = calc_model_->CalcExpression();
        // std::cout << "Contr y: " << y << std::endl;
        return y;
    }

    int CalcController::isBracketsCorrect(std::string input_str) {
        int open_par = 0;
        int close_par = 0;
        for (int i = 0; input_str[i] != '\0'; i++) {
            if (input_str[i] == '(') open_par++;
            if (input_str[i] == ')') close_par++;
            if (open_par < close_par) return 0;
        }
        return open_par == close_par ? 1 : 0;
    }