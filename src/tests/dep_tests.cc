#include <gtest/gtest.h>

#include <iostream>
#include "../Controllers/deposit_controller.h"
#include "../Models/deposit_model.h"

class DepositTest : public ::testing::Test {
  void SetUp() {
    DepModel_ = new DepositModel();
    DepController_ = new DepositController(DepModel_);
  }
  void TearDown() {}

 protected:
    DepositModel *DepModel_;
    DepositController *DepController_;
};

TEST_F(DepositTest, DepTest) {
    DepController_->SetAmountToModel(100000);
    DepController_->SetInterestRateToModel(10);
    DepController_->SetTotMonthsToModel(12);
    DepController_->SetTaxRateToModel(13);
    DepController_->SetCalculationTypeToModel(1);
    DepController_->SetDepDaysToModel(365);
    DepController_->CalcDeposit();

    double persents = DepController_->GetPercentsFromModel();
    double totl_amount = DepController_->GetTotalAmountFromModel();
    double tax_value = DepController_->GetTotalTaxesFromModel();

    EXPECT_NEAR(persents, 10465.30, 1e-2);
    EXPECT_NEAR(totl_amount, 110465.30, 1e-2);
    EXPECT_NEAR(tax_value, 1360.49, 1e-2);

    // std::cout << persents << " " << totl_amount << " " << tax_value<< std::endl;
};
