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
    const auto prices = stock_prices::get_prices(100.0, 10, 0.05);
    std::cout << "Got prices:\n";
    for(double price: prices)
    {
        std::cout << price << '\n';
    }
    const auto profit = stock_prices::profit_on_first_uptick(prices);
    std::cout << "Profit " << profit << '\n';
    std::random_device rd{};
    std::default_random_engine gen{rd()};
    std::normal_distribution distrib;
    double price = 100.0;
    const double volatility = 0.05;
    auto next_price = [volatility, &price, &gen, &distrib]()
    {
        double percent  = volatility * distrib(gen);
        price += price * percent;
        return price;
    };
    const double step = price/100.0;
    std::uniform_int_distribution<> uniform_distrib{-1, +1};
    auto next_uniform_price = [step, &price, &gen, &uniform_distrib]()
    {
        price += step*uniform_distrib(gen);
        return price;
    };
    const auto even_more_prices = stock_prices::get_prices(100.0, 10,
                                      next_uniform_price);

    const auto more_prices = stock_prices::get_prices(100.0, 10, next_price);
    trading_game();
}