#ifndef CREDIT_INPUT_DATA_H
#define CREDIT_INPUT_DATA_H

class CreditInputData {
    public:
        CreditInputData(double cred_amaunt, double cred_int_rate, int months, int type) : cred_amaunt_{cred_amaunt}, cred_int_rate_{cred_int_rate} , cred_months_{months}, cred_type_{type} {};

        double GetCredAmount() {return cred_amaunt_;};
        double GetCredIntRate() {return cred_int_rate_;};
        int GetCredMonths() {return cred_months_;};
        int GetType() {return cred_type_;};

    private:
        double cred_amaunt_;
        double cred_int_rate_;
        int cred_months_;
        int cred_type_;
};

#endif // CREDIT_INPUT_DATA_H