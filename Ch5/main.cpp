#include <algorithm>
#include <iostream>
#include <vector>

#include "analysis.h"
#include "input.h"

std::vector<double> get_prices(std::istream & input_stream)
{
    std::cout << "Please enter some numbers.\n>";
    std::vector<double> numbers{};
    auto number = stock_prices::get_number(input_stream); 
    while(number.has_value())
    {
        numbers.push_back(number.value());
        std::cout << '>';  
        number = stock_prices::get_number(input_stream);
    }   
    return numbers;
}

int main()
{
    auto prices = get_prices(std::cin);
    if(!prices.empty())
    {
        auto result = std::ranges::minmax(prices);
        std::cout << "min " << result.min << '\n';
        std::cout << "max " << result.max << '\n';
    }
    auto invalid = std::ranges::count_if(prices, stock_prices::negative);
    std::cout << invalid << " prices below zero\n";
    std::cout << "Average " << stock_prices::average(prices) << '\n';
    stock_prices::test_analysis();
}