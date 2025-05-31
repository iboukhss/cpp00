#include "PhoneBook.hpp"

#include <cctype>
#include <iostream>
#include <string>

static void TrimLeft(std::string& str)
{
    std::string::iterator it = str.begin();

    while (it != str.end() && std::isspace(static_cast<unsigned char>(*it)))
    {
        ++it;
    }
    str.erase(str.begin(), it);
}

static void TrimRight(std::string& str)
{
    std::string::reverse_iterator rit = str.rbegin();

    while (rit != str.rend() && std::isspace(static_cast<unsigned char>(*rit)))
    {
        ++rit;
    }
    str.erase(rit.base(), str.end());
}

static void TrimBoth(std::string& str)
{
    TrimLeft(str);
    TrimRight(str);
}

static void ReadLine(const std::string& prompt, std::string& str)
{
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, str);

        TrimBoth(str);
        if (!str.empty())
        {
            break;
        }
    }
}

static void SaveContactInfo(PhoneBook& phonebook)
{
    Contact contact;
    std::string input;

    ReadLine("First name: ", input);
    contact.SetFirstName(input);

    ReadLine("Last name: ", input);
    contact.SetLastName(input);

    ReadLine("Nickname: ", input);
    contact.SetNickname(input);

    ReadLine("Phone number: ", input);
    contact.SetPhoneNumber(input);

    ReadLine("Darkest secret: ", input);
    contact.SetDarkestSecret(input);

    phonebook.AddContact(contact);
}

int main(void)
{
    std::cin.exceptions(std::istream::eofbit);

    try
    {
        PhoneBook phonebook;
        std::string command;

        while (true)
        {
            ReadLine("\nEnter command (ADD, SELECT, EXIT): ", command);

            if (command == "ADD")
            {
                SaveContactInfo(phonebook);
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
    catch (const std::ios_base::failure& e)
    {
        std::cout << std::endl;
    }
    return 0;
}
