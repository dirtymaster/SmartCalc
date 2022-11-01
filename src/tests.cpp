#include <gtest/gtest.h>

#include "Controller/controller.h"

namespace s21 {
const double COMPRASSION_TOLERANCE = 1e-7;

TEST(Test, smartcalc_tests_1) {
    // Некорректный ввод
    Controller my_controller;
    bool return_value = my_controller.Calculate(")cos)(17+4)*", "0");
    EXPECT_EQ(return_value, false);
}

TEST(Test, smartcalc_tests_2) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("16*sin(2)^2+(cos(2)^2/sin(2)^2)-7", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 6.4385994, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_3) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "3.5-acos(0.5)+asin(1)-atan(100)+3.5-acos(0.5)+asin(1)-atan(100)+3.5-"
        "acos(0.5)+asin(1)-atan(100)",
        "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 7.3884063464702026,
                COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_4) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("acos(7)", "0");
    EXPECT_EQ(return_value, false);
}

TEST(Test, smartcalc_tests_5) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("asin(1.000001)", "0");
    EXPECT_EQ(return_value, false);
}

TEST(Test, smartcalc_tests_6) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("1+2/(1-1)", "0");
    EXPECT_EQ(return_value, false);
}

TEST(Test, smartcalc_tests_7) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(1+2)mod(1-1)", "");
    EXPECT_EQ(return_value, false);
}

TEST(Test, smartcalc_tests_8) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("3.5-acos(0.5)+asin(1)-atan(100)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 2.4628021, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_9) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("sqrt(0.25)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.5, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_10) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("0+sqrt(0.25)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.5, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_11) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("-sqrt(0.25)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -0.5, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_12) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(ln(25.9))", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 3.2542429, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_13) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("-log(982.465)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -2.992317, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_14) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("+(-1+(+1))", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_15) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("7*(2)*1", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 14, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_16) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("2^sin(3)/1", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.1027608, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_17) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("sin(-1000000)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.3499935, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_18) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("cos(123456)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -0.6722948, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_19) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("atan(1000000)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.5707953, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_20) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("tan(2)+ln(40)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.5038395, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_21) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("log(2)+log(3)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0.7781512, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_22) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("sin(x)+cos(-x)+tan(+x)", "654123.891357");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.5927179, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_23) {
    Controller my_controller;
    bool return_value =
        my_controller.Calculate("sin(x)+cos(-x)+tan(+x)", "24e-4");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 1.0047971223053938,
                COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_24) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(2.7e3+2)+sin(x)", "1");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 2702.841470984808,
                COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_25) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("x-x*x/x", "1");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_26) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(-0)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_27) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(-1*0)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_28) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(0*(-1))", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_29) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("(0*(-1))", "aboba");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), 0, COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_30) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)", "0");
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -4.3521688871149582,
                COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_31) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("", "0");
    EXPECT_EQ(return_value, false);
}

TEST(Test, smartcalc_tests_32) {
    Controller my_controller;
    bool return_value = my_controller.Calculate("", 0.);
    EXPECT_EQ(return_value, false);
}

TEST(Test, smartcalc_tests_33) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)", 0.);
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -4.3521688871149582,
                COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_34) {
    Controller my_controller;
    bool return_value = my_controller.Calculate(
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)", 0.);
    EXPECT_EQ(return_value, true);
    EXPECT_NEAR(my_controller.GetResult(), -4.3521688871149582,
                COMPRASSION_TOLERANCE);
}

TEST(Test, smartcalc_tests_35) {
    Controller my_controller;
    long double x_min, x_max, y_min, y_max, step;
    bool return_value = my_controller.CheckGraphicParameters(
        "10", "-10", "10", "-10", "0.1", x_min, x_max, y_min, y_max, step);
    EXPECT_EQ(return_value, true);
}

TEST(Test, smartcalc_tests_36) {
    Controller my_controller;
    long double x_min, x_max, y_min, y_max, step;
    bool return_value = my_controller.CheckGraphicParameters(
        "10", "-10e+8bbb", "g10", "-10", "0.1", x_min, x_max, y_min, y_max, step);
    EXPECT_EQ(return_value, false);
}
}  // namespace s21

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
