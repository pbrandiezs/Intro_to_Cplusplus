#include <iostream>
#include <random>

void random_experiment()
{
    std::random_device rd{};
    std::default_random_engine generator(rd());
    std::uniform_int_distribution distribution{1, 6};
    const int roll = distribution(generator);
    std::cout << "Dice roll " << roll << '\n';
}

int main()
{
    random_experiment();
}