#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "input.h"

void write_to_file(const std::vector<double> & prices,
        const std::string & filename)
{
    std::ofstream file{filename};
    if(file)
    {
        for(auto price: prices)
        {
            file << price << '\n';
        }
        std::cout << "Wrote to prices.txt\n";
    }
    else {
        throw std::runtime_error{"Failed to write to prices.txt"};
    }
}

int main()
{
    try {
        write_to_file(stock_prices::get_prices(100.0, 10, 0.05), "prices.txt");
        return 0;
    }
    catch (const std::exception & e) {
        std::cout << e.what() << '\n';
        return 1;
    }
}