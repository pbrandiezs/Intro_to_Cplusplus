#include <iostream>
#include <string>

void show_characters_before(const std::string & value,
        char character)
{
    auto position = value.find(character);
    if(position != std::string::npos)
    {
        std::string partial = value.substr(0, position);
        std::cout << "Before " << character <<  ": " << partial<< '\n';
    }
    else
    {
        std::cout << character << " not found\n";
    }
}

int main(int argc, char *argv[])
{
    for(int i = 0; i<argc; ++i)
    {
        std::cout << "Argument " << argv[i] << '\n';
        show_characters_before(argv[i], '/');
        show_characters_before(argv[i], '\\');
    }
}