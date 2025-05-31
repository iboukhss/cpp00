#include "PhoneBook.hpp"

#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <exception>
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
    do
    {
        std::cout << prompt;
        std::getline(std::cin, str);

        TrimBoth(str);
    }
    while (str.empty());
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

int ParseInt(const std::string& str)
{
    const char* nptr = str.c_str();
    char* endptr = NULL;
    errno = 0;

    long val = std::strtol(nptr, &endptr, 10);

    if (nptr == endptr)
    {
        throw std::invalid_argument("Invalid string: '" + str + "'");
    }
    if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
    {
        throw std::out_of_range("Value out of range: '" + str + "'");
    }
    while (*endptr != '\0' && std::isspace(static_cast<unsigned char>(*endptr)))
    {
        ++endptr;
    }
    if (*endptr != '\0')
    {
        throw std::invalid_argument("Invalid trailing characters: '" + str + "'");
    }
    return static_cast<int>(val);
}

static void DisplayContactInfo(const PhoneBook& phonebook)
{
    if (phonebook.GetSize() == 0)
    {
        std::cout << "Phonebook is empty. Add new contacts.\n";
        return;
    }

    while (true)
    {
        std::string input;

        ReadLine("Enter index to display: ", input);
        try
        {
            int index = ParseInt(input);
            const Contact& contact = phonebook.GetContactAtIndex(index);

            std::cout << "First name: " << contact.GetFirstName() << '\n';
            std::cout << "Last name: " << contact.GetLastName() << '\n';
            std::cout << "Nickname: " << contact.GetPhoneNumber() << '\n';
            std::cout << "Phone number: " << contact.GetPhoneNumber() << '\n';
            std::cout << "Darkest secret: " << contact.GetDarkestSecret() << '\n';
            break;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
}

int main(void)
{
    std::cin.exceptions(std::istream::eofbit);

    try
    {
        PhoneBook phonebook;

        while (true)
        {
            std::string command;

            ReadLine("\nEnter command (ADD, SELECT, EXIT): ", command);
            if (command == "ADD")
            {
                SaveContactInfo(phonebook);
            }
            else if (command == "SELECT")
            {
                DisplayContactInfo(phonebook);
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
    catch (const std::ios_base::failure&)
    {
        std::cout << std::endl;
    }
    return 0;
}
