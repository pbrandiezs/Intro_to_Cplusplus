#include <iostream>
#include <random>

#include "analysis.h"
#include "input.h"

void random_experiment()
{
    std::random_device rd{};
    std::default_random_engine generator(rd());
    std::uniform_int_distribution distribution{1, 6};
    const int roll = distribution(generator);
    std::cout << "Dice roll " << roll << '\n';
}

void trading_game()
{
    const double start_price = 100.0;
    std::cout << "Stock bought for: " << start_price << '\n';
    auto prices = stock_prices::get_prices(start_price, 10);
    for(auto price : prices)
    {
        std::cout << "Current price: " << price << '\n';
        std::cout << "Press (s) to sell\n>";
        char choice{};
        std::cin >> choice;
        if (choice == 's')
        {
            const double profit = price - start_price;
            std::cout << "Profit " << profit << '\n';
            break;
        }
    }
    std::cout << "Game over\n";
}

int main()
{
    random_experiment();
    stock_prices::test_input();
    const auto prices = stock_prices::get_prices(100.0, 10);
    std::cout << "Got prices:\n";
    for(double price: prices)
    {
        std::cout << price << '\n';
    }
    const auto profit = stock_prices::profit_on_first_uptick(prices);
    std::cout << "Profit " << profit << '\n';
    trading_game();
}