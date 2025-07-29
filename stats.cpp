#include "stats.h"
#include <numeric>
#include <limits>

bool readingsAreOutofRange(const std::vector<float>& readings) {
    // Check if the readings are out of range
    for (const auto& reading : readings) {
        if (std::isnan(reading) || reading < 0 || reading > 10000) {
            return true; // Out of range reading found
        }
    }
    return false; // All readings are within range
}

bool readingsAreSuspect(const std::vector<float>& readings) {
    // Check if the readings are suspect
   return (readings.empty() || readingsAreOutofRange(readings))
}


Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& readings ) {

    //Implement statistics here
    Statistics::Stats stats;
    if( readingsAreSuspect() ) {
        stats.average = std::numeric_limits<float>::quiet_NaN();
        stats.max = std::numeric_limits<float>::quiet_NaN();
        stats.min = std::numeric_limits<float>::quiet_NaN();
    }
    else
    {
        stats.average = std::accumulate(readings.begin(), readings.end(), 0.0f) / readings.size();
        stats.max = *std::max_element(readings.begin(), readings.end());
        stats.min = *std::min_element(readings.begin(), readings.end());
    }
    return stats;
}
