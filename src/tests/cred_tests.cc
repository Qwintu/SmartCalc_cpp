#include <gtest/gtest.h>

#include <iostream>
#include "../Controllers/credit_controller.h"
#include "../Models/credit_model.h"

class CreditTest : public ::testing::Test {
  void SetUp() {
    CreditModel CredModel;
    CreditController CredController(&CredModel);
    CredModel_ = &CredModel;
    CredController_ = &CredController;
  }
  void TearDown() {}

 protected:
    CreditModel *CredModel_;
    CreditController *CredController_;
};


TEST_F(CreditTest, CredTest) {
    CreditOutputData data = CredController_->CalcCredit(100000, 12, 12, 0);

    EXPECT_NEAR(data.GetMonthlyPayment(), 8884.88, 1e-2);
    EXPECT_NEAR(data.GetOverpayment(), 6618.55, 1e-2);
    EXPECT_NEAR(data.GetTotalPayment(), 106618.55, 1e-2);

    data = CredController_->CalcCredit(100000, 12, 12, 1);

    EXPECT_NEAR(data.GetMonthlyPayment(), 8416.67, 1e-2);
    EXPECT_NEAR(data.GetOverpayment(), 6500, 1e-2);
    EXPECT_NEAR(data.GetTotalPayment(), 106500, 1e-2);
};