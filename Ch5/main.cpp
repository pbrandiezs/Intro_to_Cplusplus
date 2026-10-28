#include <algorithm>
#include <functional>
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
    std::sort(prices.begin(), prices.end());
    for(auto p: prices)
    {
        std::cout << p << '\n';
    }
    std::sort(prices.begin(), prices.end(), std::greater{});
    std::cout << '\n';
    for(auto p: prices)
    {
        std::cout << p << '\n';
    }
    std::ranges::sort(prices);
    std::cout << '\n';
    for(auto p: prices)
    {
        std::cout << p << '\n';
    }

    std::ranges::sort(prices, std::ranges::greater{});
    std::cout << '\n';
    for(auto p: prices)
    {
        std::cout << p << '\n';
    }

    auto iterator = std::ranges::find_if(prices,
                             stock_prices::negative);
    auto positive = std::vector(prices.begin(), iterator);
    std::cout << '\n';
    for(auto p: positive) {
        std::cout << p << '\n';
    }
}