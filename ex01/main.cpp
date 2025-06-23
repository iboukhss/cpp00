#include "PhoneBook.hpp"

#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

static void trimLeft(std::string& str)
{
    std::string::iterator it = str.begin();

    while (it != str.end() && std::isspace(static_cast<unsigned char>(*it))) {
        ++it;
    }
    str.erase(str.begin(), it);
}

static void trimRight(std::string& str)
{
    std::string::reverse_iterator rit = str.rbegin();

    while (rit != str.rend() && std::isspace(static_cast<unsigned char>(*rit))) {
        ++rit;
    }
    str.erase(rit.base(), str.end());
}

static void trimBoth(std::string& str)
{
    trimLeft(str);
    trimRight(str);
}

static void readLine(const std::string& prompt, std::string& str)
{
    do {
        std::cout << prompt;
        std::getline(std::cin, str);
        trimBoth(str);
    }
    while (str.empty());
}

static void saveContactInfo(PhoneBook& phonebook)
{
    Contact contact;
    std::string input;

    readLine("First name: ", input);
    contact.setFirstName(input);

    readLine("Last name: ", input);
    contact.setLastName(input);

    readLine("Nickname: ", input);
    contact.setNickname(input);

    readLine("Phone number: ", input);
    contact.setPhoneNumber(input);

    readLine("Darkest secret: ", input);
    contact.setDarkestSecret(input);

    phonebook.addContact(contact);
}

static int parseInt(const std::string& str)
{
    const char* nptr = str.c_str();
    char* endptr = NULL;
    errno = 0;

    long val = std::strtol(nptr, &endptr, 10);

    if (nptr == endptr) {
        throw std::invalid_argument("Invalid string: '" + str + "'");
    }
    if (errno == ERANGE || val > INT_MAX || val < INT_MIN) {
        throw std::out_of_range("Value out of range: '" + str + "'");
    }
    while (*endptr != '\0' && std::isspace(static_cast<unsigned char>(*endptr))) {
        ++endptr;
    }
    if (*endptr != '\0') {
        throw std::invalid_argument("Invalid trailing characters: '" + str + "'");
    }
    return static_cast<int>(val);
}

static const int kNumColumns = 4;
static const int kColumnWidth = 10;

static void drawRowBorder()
{
    std::string cellBorder(kColumnWidth, '-');

    for (int i = 0; i < kNumColumns; ++i) {
        std::cout << '+' << cellBorder;
    }
    std::cout << "+\n";
}

static void drawCellData(const std::string& str)
{
    std::string trimmed;

    if (str.length() > kColumnWidth) {
        trimmed = str.substr(0, kColumnWidth - 1) + '.';
    }
    else {
        trimmed = str;
    }
    std::cout << '|';
    std::cout << std::right << std::setw(kColumnWidth) << trimmed;
}

static void drawTableHeader()
{
    drawRowBorder();
    drawCellData("Index");
    drawCellData("First name");
    drawCellData("Last name");
    drawCellData("Nickname");
    std::cout << "|\n";
}

static void drawRowData(const Contact& contact, int index)
{
    drawRowBorder();
    std::cout << '|';
    std::cout << std::right << std::setw(kColumnWidth) << index;
    drawCellData(contact.getFirstName());
    drawCellData(contact.getLastName());
    drawCellData(contact.getNickname());
    std::cout << "|\n";
}

static void displayContactList(const PhoneBook& phonebook)
{
    drawTableHeader();
    for (int i = 0; i < phonebook.getSize(); ++i) {
        const Contact* contact = phonebook.getContactAt(i);
        drawRowData(*contact, i);
    }
    drawRowBorder();
}

static void displayContactInfo(const PhoneBook& phonebook)
{
    if (phonebook.isEmpty()) {
        std::cout << "Phonebook is empty. Add new contacts first.\n";
        return;
    }

    displayContactList(phonebook);

    std::string input;

    readLine("Enter index to display: ", input);
    int index = parseInt(input);
    const Contact* contact = phonebook.getContactAt(index);

    std::cout << "First name: " << contact->getFirstName() << '\n';
    std::cout << "Last name: " << contact->getLastName() << '\n';
    std::cout << "Nickname: " << contact->getNickname() << '\n';
    std::cout << "Phone number: " << contact->getPhoneNumber() << '\n';
    std::cout << "Darkest secret: " << contact->getDarkestSecret() << '\n';
}

int main(void)
{
    std::cin.exceptions(std::istream::eofbit);

    try {
        PhoneBook phonebook;

        phonebook.addContact(Contact("Tupac", "Shakur", "2Pac", "none", "none"));
        phonebook.addContact(Contact("Christopher", "Wallace", "Biggie", "none", "none"));
        phonebook.addContact(Contact("Sean", "Combs", "Diddy", "none", "none"));
        phonebook.addContact(Contact("Aubrey", "Graham", "Drake", "none", "none"));
        phonebook.addContact(Contact("Kayne", "West", "Ye", "none", "none"));
        phonebook.addContact(Contact("Shawn", "Carter", "JAY-Z", "none", "none"));

        while (true) {
            std::string command;

            readLine("Enter command (ADD, SELECT, EXIT): ", command);

            if (command == "ADD") {
                saveContactInfo(phonebook);
            }
            else if (command == "SELECT") {
                displayContactInfo(phonebook);
            }
            else if (command == "EXIT") {
                break;
            }
            else {
                std::cout << "Unknown command\n";
            }
        }
    }
    catch (const std::ios_base::failure&) {
        std::cout << std::endl;
    }
    return 0;
}
