#include <iostream> 
#include <vector>  

void vector_experiment()
{
    std::vector numbers{0, 1}; 
    numbers.push_back(-123);
    for(const auto number: numbers)  
    {
        std::cout << number << '\n'; 
    }
}

void vector_insert()
{
    std::vector<int> numbers{0, 1};
    auto iterator = numbers.begin(); 
    numbers.insert(++iterator, -123); 
    for(const auto number: numbers)
    {
        std::cout << number << '\n';
    }
}

int main()
{
    vector_experiment();
    vector_insert();
}
