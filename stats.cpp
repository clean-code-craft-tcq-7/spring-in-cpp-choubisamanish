#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& readings ) {

    //Implement statistics here
    Stats stats;
    stats.average = std::accumulate(readings.begin(), readings.end(), 0.0f) / readings.size();
    stats.max = *std::max_element(readings.begin(), readings.end());
    stats.min = *std::min_element(readings.begin(), readings.end());
    return stats;
}
