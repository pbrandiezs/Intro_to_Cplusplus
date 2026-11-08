#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "input.h"

void write_to_file(const std::vector<double> & prices,
        const std::string & filename)
{
    const std::filesystem::path path = std::filesystem::current_path();
    const auto fully_pathed_filename = path / filename;
    std::ofstream file{filename};
    if(file)
    {
        for(auto price: prices)
        {
            file << price << '\n';
        }
        std::cout <<"Wrote to " << fully_pathed_filename << '\n';
    }
    else {
        auto error_message = "Failed to write to " +
        fully_pathed_filename.string();
        throw std::runtime_error(error_message);
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