#pragma once

#include <vector>

namespace stock_prices 
{
    inline bool negative(double value) 
    {
        return value < 0.0;
    }
    std::vector<double> remove_invalid(std::vector<double> prices);
    void test_analysis();
} 