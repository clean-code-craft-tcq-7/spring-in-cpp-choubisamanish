#include "stats.h"

#include "gtest/gtest.h"
#include <cmath>

TEST(Statistics, ReportsAverageMinMax) {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    EXPECT_LT(std::abs(computedStats.average - 4.525), epsilon);
    EXPECT_LT(std::abs(computedStats.max - 8.9), epsilon);
    EXPECT_LT(std::abs(computedStats.min - 1.5), epsilon);
}

TEST(Statistics, AverageNaNForEmpty) {
    auto computedStats = Statistics::ComputeStatistics({});
    // All fields of computedStats (average, max, min) must be
    // NAN (not-a-number), as defined in math.h
    EXPECT_TRUE(std::isnan(computedStats.average));
    EXPECT_TRUE(std::isnan(computedStats.max));
    EXPECT_TRUE(std::isnan(computedStats.min));
    
    // Specify the EXPECT statement here.
    // Use http://www.cplusplus.com/reference/cmath/isnan/
}

TEST( Statistics, NanInInputIsIgnored) {
    auto invalidReading = std::numeric_limits<float>::quiet_NaN();
    auto computedStats = Statistics::ComputeStatistics({1.5, invalidReading, 3.2, 4.5});
    float epsilon = 0.001;
    EXPECT_LT(std::abs(computedStats.average - 3.4), epsilon);
    EXPECT_LT(std::abs(computedStats.max - 4.5), epsilon);
    EXPECT_LT(std::abs(computedStats.min - 1.5), epsilon);
}

TEST(Statistics, OutputIsNaNforAbsuredInput){
    autp computedStats = Statistics::ComputeStatistics({-1.5, 10000, 3.2, 4.5});
    EXPECT_TRUE(std::isnan(computedStats.average));
    EXPECT_TRUE(std::isnan(computedStats.max));
    EXPECT_TRUE(std::isnan(computedStats.min));

}