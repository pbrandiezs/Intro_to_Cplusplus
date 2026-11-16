#include <print>

#include "input.h"

int main()
{
    const auto prices = stock_prices::get_prices(100.0, 10, 0.05);
    for(auto price: prices)
    {
        std::println("${:.2f}", price);
    }
}