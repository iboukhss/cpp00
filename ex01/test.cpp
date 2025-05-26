#include "PhoneBook.hpp"

#include <iostream>
#include <string>

int main(void)
{
    std::cin.exceptions(std::istream::eofbit);

    try
    {
        while (true)
        {
            std::string command;
            std::cout << "\nEnter command (ADD, SELECT, EXIT): ";
            std::getline(std::cin, command);

            if (command == "ADD")
            {
                continue;
            }
            else if (command == "SELECT")
            {
                continue;
            }
            else if (command == "EXIT")
            {
                break;
            }
            else
            {
                std::cout << "Unknown command\n";
            }
        }
    }
    catch (const std::ios_base::failure &e)
    {
        std::cout << std::endl;
    }
    return 0;
}
