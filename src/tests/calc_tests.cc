#include <gtest/gtest.h>

#include <iostream>
#include "../Controllers/calc_controller.h"
#include "../Models/calc_model.h"

class CalcTest : public ::testing::Test {
  void SetUp() {
    CalcModel_ = new CalcModel();
    CalcController_ = new CalcController(CalcModel_);
    std::cout << "mod addr: " << &CalcModel_ << std::endl;
    std::cout << "contr addr: " << &CalcController_ << std::endl;
  }
  void TearDown() {}

 protected:
    CalcModel *CalcModel_;
    CalcController *CalcController_;
    std::string string;
    double result;
    int bool_res;
};

TEST_F(CalcTest, BracketsCorrect) {
    bool_res = CalcController_->isBracketsCorrect("(654)");
    EXPECT_TRUE(bool_res == 1);
    bool_res = CalcController_->isBracketsCorrect("()6)ghjk54()");
    EXPECT_FALSE(bool_res == 1);
    bool_res = CalcController_->isBracketsCorrect("sin((-30)-1)");
    EXPECT_TRUE(bool_res == 1);
    bool_res = CalcController_->isBracketsCorrect("((-30-1)");
    EXPECT_TRUE(bool_res == 0);
    bool_res = CalcController_->isBracketsCorrect("(-3))+((-30)-1))");
    EXPECT_TRUE(bool_res == 0);
    bool_res = CalcController_->isBracketsCorrect("3+3+36");
    EXPECT_TRUE(bool_res == 1);
    bool_res = CalcController_->isBracketsCorrect("()");
    EXPECT_TRUE(bool_res == 1);
};

TEST_F(CalcTest, simple_func) {
  CalcController_->SetXtoModel(9.3);
  CalcController_->SetRadDegMode(0);
  CalcController_->SetStringToModel("2+3-7*8+5/2");
  result = CalcController_->CalcExpr();
  EXPECT_TRUE(result == -48.5);

  CalcController_->SetStringToModel("sin(90)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 1, 1e-7);

  CalcController_->SetStringToModel("cos(45)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 0.70710678118, 1e-7);

  CalcController_->SetStringToModel("tan(30)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 0.57735026, 1e-7);

  CalcController_->SetStringToModel("asin(0.36)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 21.10019602, 1e-7);

  CalcController_->SetStringToModel("acos(-0.56)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 124.0557977, 1e-7);

  CalcController_->SetStringToModel("atan(25.6)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 87.76302093, 1e-7);

  CalcController_->SetStringToModel("3.5^6.12");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 2136.46819225, 1e-7);

  CalcController_->SetStringToModel("ln(25)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 3.21887582, 1e-7);

  CalcController_->SetStringToModel("log(15)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 1.17609125, 1e-7);

  CalcController_->SetStringToModel("sqrt(14.6)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 3.8209946, 1e-7);

  CalcController_->SetStringToModel("32mod21");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 11, 1e-7);
};


TEST_F(CalcTest, long_func) {
  CalcController_->SetXtoModel(0);
  CalcController_->SetRadDegMode(0);

  CalcController_->SetStringToModel("-3+2*2/5-2/3^2+2.3^2/7*6-5+3^2");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 6.1120634920, 1e-7);

  CalcController_->SetStringToModel("-(+53*sin(45)^2.1+147.62-0)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, -173.217312717, 1e-7);

  CalcController_->SetStringToModel("2*((3+1*5)/4)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 4, 1e-7);

  CalcController_->SetStringToModel("+13+12.2*(-5+9^2*(3+5))-12.5/5+2.1*((+4.5+2^2)/4)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 7859.5625, 1e-7);

  CalcController_->SetStringToModel("sin(5+3)*sqrt(4*2)*2^tan(3)+sin(30)+cos(6^2)*ln(3+1)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 2.029739091, 1e-7);

  CalcController_->SetStringToModel("-sin((-30)-1)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 0.515038074, 1e-7);

  CalcController_->SetStringToModel("((2))");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 2, 1e-7);

  CalcController_->SetStringToModel("-((2))");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, -2, 1e-7);

  CalcController_->SetStringToModel("-(-(2))");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 2, 1e-7);

  CalcController_->SetRadDegMode(1); // RAD mode

  CalcController_->SetStringToModel("sin(5.3)");
  result = CalcController_->CalcExpr();
  std::cout << "result: " << result << std::endl;
  EXPECT_NEAR(result, -0.83226744, 1e-7);

  CalcController_->SetStringToModel("cos(sin(-23))");
  result = CalcController_->CalcExpr();
  std::cout << "result: " << result << std::endl;
  EXPECT_NEAR(result, 0.6628179, 1e-7);

  CalcController_->SetStringToModel("tan(-46.3)");
  result = CalcController_->CalcExpr();
  std::cout << "result: " << result << std::endl;
  EXPECT_NEAR(result, 1.08010626, 1e-7);
};


TEST_F(CalcTest, Errors) {
  // double nan = NAN;
  // double nan = std::numeric_limits<float>::quiet_NaN();
  CalcController_->SetStringToModel("sqrt(-2)");
  result = CalcController_->CalcExpr();
  EXPECT_TRUE(std::isnan(result));
  
  CalcController_->SetStringToModel("log(-2)");
  result = CalcController_->CalcExpr();
  EXPECT_TRUE(std::isnan(result));

  CalcController_->SetStringToModel("1/0");
  result = CalcController_->CalcExpr();
  EXPECT_TRUE(std::isinf(result));
};

TEST_F(CalcTest, setX) {
  CalcController_->SetRadDegMode(0);

  CalcController_->SetXtoModel(90);
  CalcController_->SetStringToModel("sin(x)+sqrt(x)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 10.486832980, 1e-7);

  CalcController_->SetXtoModel(5.0);
  CalcController_->SetStringToModel("-x+(x)");
  result = CalcController_->CalcExpr();
  EXPECT_NEAR(result, 0, 1e-7);
};

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}