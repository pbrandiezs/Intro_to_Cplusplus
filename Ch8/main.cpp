#include <fstream>
#include <iostream>
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
    }
}

int main()
{
    write_to_file(stock_prices::get_prices(100.0, 10, 0.05), "prices.txt");
}