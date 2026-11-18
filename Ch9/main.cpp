#include <iostream>
#include <print>
#include <stdexcept>

#include "input.h"

void trading_game(const std::vector<double> & prices) {
    const double initial_funds{100.0};
    double funds{initial_funds};
    int number_of_shares{};

    for(auto price : prices)
    {
        auto status = std::format("Funds ${:.2f}, Shares {}",
                              funds, number_of_shares);
        std::println("{}", status);
        auto price_message = std::format("Current price: ${:.2f}", price);
        std::println("{: >{}}", price_message, status.size());
        std::println("Press (s) to sell, (b) to buy");
        std::print("or something else to continue>");
        char choice{};
        std::cin >> choice;

        if (choice == 's')
        {
            if(number_of_shares > 0)
            {
                --number_of_shares;
                funds += price;
            }
            else
            {
                std::println("No stock to sell");
            }
        }
        else if(choice == 'b')
        {
            if(price <= funds)
            {
                ++number_of_shares;
                funds -= price;
            }
            else
            {
                std::println("Insufficient funds");
            }
        }
    }
    std::println("Total profit ${:.2f}", funds - initial_funds);
}

int main(int argc, char *argv[])
{
    using namespace stock_prices;
    const auto prices = (argc>1) ? read_from_file(argv[1]) :
                                   get_prices(100.0, 10, 0.05);
    trading_game(prices);
}