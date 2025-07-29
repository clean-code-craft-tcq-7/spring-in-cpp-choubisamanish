#include <vector>


namespace Statistics {
    struct Stats {
        float average;
        float max;
        float min;
    };
    // define the Stats structure here. See the tests to infer its properties
    
    Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& readings );
}
