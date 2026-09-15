#include <iostream>

int main()
{
    std::cout << "Please enter a number.\n>";
    double number{};
    std::cin >> number;
    if(std::cin)
    {
        std::cout << number << '\n';
    }
    else
    {
        std::cout << "Something went wrong\n";
    }
}
