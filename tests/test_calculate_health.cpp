//
// Created by mikhail on 28.08.24.
//
// test_calculate_health.cpp
#include <gtest/gtest.h>
#include "../calculate_health.h"

TEST(CalculateHealthTest, NoImpactWhenDistanceGreaterThan100) {
    EXPECT_FLOAT_EQ(calculate_health(100.0, 150.0, 50.0), 100.0);
}

TEST(CalculateHealthTest, NoImpactWhenDistanceEqual100) {
    EXPECT_FLOAT_EQ(calculate_health(100.0, 100.0, 50.0), 100.0);
}

TEST(CalculateHealthTest, FullImpactWhenDistanceIsZero) {
    EXPECT_FLOAT_EQ(calculate_health(100.0, 0.0, -50.0), 50.0);
}

TEST(CalculateHealthTest, HalfImpactWhenDistanceIsFifty) {
    EXPECT_FLOAT_EQ(calculate_health(100.0, 50.0, -50.0), 75.0);
}

TEST(CalculateHealthTest, HealthFloorTo1IfAboveZeroAndBelowOne) {
    EXPECT_FLOAT_EQ(calculate_health(1.0, 90.0, -0.95), 1.0);
}

TEST(CalculateHealthTest, HealthGoesToZeroWhenImpactIsHigh) {
    EXPECT_FLOAT_EQ(calculate_health(10.0, 0.0, -20.0), -10.0);
}

TEST(CalculateHealthTest, Healing) {
    EXPECT_FLOAT_EQ(calculate_health(10.0, 0.0, 10), 20.0);
}