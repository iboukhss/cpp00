#include "PhoneBook.hpp"

#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
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
    } while (str.empty());
}

static void saveContactInfo(PhoneBook& pb)
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

    pb.addContact(contact);
}

static bool tryParseInt(const std::string& str, int& out)
{
    const char* nptr = str.c_str();
    char* endptr = NULL;
    errno = 0;

    long val = std::strtol(nptr, &endptr, 10);
    if (nptr == endptr) {
        return false;
    }
    if (errno == ERANGE || val > INT_MAX || val < INT_MIN) {
        return false;
    }

    while (*endptr != '\0' && std::isspace(static_cast<unsigned char>(*endptr))) {
        ++endptr;
    }
    if (*endptr != '\0') {
        return false;
    }

    out = static_cast<int>(val);
    return true;
}

static const int kNumColumns = 4;
static const int kColumnWidth = 10;

static void drawRowBorder()
{
    std::string cellBorder(kColumnWidth, '-');

    for (int i = 0; i < kNumColumns; ++i) {
        std::cout << "+" << cellBorder;
    }
    std::cout << "+\n";
}

static void drawCellData(const std::string& str)
{
    std::string trimmed;

    if (str.length() > kColumnWidth) {
        trimmed = str.substr(0, kColumnWidth - 1) + ".";
    }
    else {
        trimmed = str;
    }
    std::cout << "|";
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
    std::cout << "|";
    std::cout << std::right << std::setw(kColumnWidth) << index;
    drawCellData(contact.getFirstName());
    drawCellData(contact.getLastName());
    drawCellData(contact.getNickname());
    std::cout << "|\n";
}

static void displayContactList(const PhoneBook& pb)
{
    drawTableHeader();
    for (int i = 0; i < pb.getSize(); ++i) {
        const Contact& contact = pb.getContactAt(i);
        drawRowData(contact, i);
    }
    drawRowBorder();
}

static void displayContactInfo(const PhoneBook& pb)
{
    if (pb.isEmpty()) {
        std::cout << "Phonebook is empty. Add new contacts first.\n";
        return;
    }

    displayContactList(pb);

    std::string input;
    int index;

    while (true) {
        readLine("\nEnter index to display: ", input);

        if (!tryParseInt(input, index)) {
            std::cout << "Invalid number. Try again.\n";
            continue;
        }
        if (!pb.hasContactAt(index)) {
            std::cout << "Invalid index. Try again.\n";
            continue;
        }
        break;
    }

    const Contact& contact = pb.getContactAt(index);

    std::cout << "First name: " << contact.getFirstName() << "\n";
    std::cout << "Last name: " << contact.getLastName() << "\n";
    std::cout << "Nickname: " << contact.getNickname() << "\n";
    std::cout << "Phone number: " << contact.getPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << contact.getDarkestSecret() << "\n";
}

int main(void)
{
    std::cin.exceptions(std::ios_base::eofbit);

    try {
        PhoneBook pb;

        pb.addContact(Contact("Tupac", "Shakur", "2Pac", "none", "none"));
        pb.addContact(Contact("Christopher", "Wallace", "Biggie", "none", "none"));
        pb.addContact(Contact("Sean", "Combs", "Diddy", "none", "none"));
        pb.addContact(Contact("Aubrey", "Graham", "Drake", "none", "none"));
        pb.addContact(Contact("Kayne", "West", "Ye", "none", "none"));
        pb.addContact(Contact("Shawn", "Carter", "JAY-Z", "none", "none"));

        std::string command;

        while (true) {
            readLine("\nEnter command (ADD, SELECT, EXIT): ", command);

            if (command == "ADD") {
                saveContactInfo(pb);
            }
            else if (command == "SELECT") {
                displayContactInfo(pb);
            }
            else if (command == "EXIT") {
                break;
            }
            else {
                std::cout << "Unknown command '" << command << "'\n";
            }
        }
    }
    catch (const std::ios_base::failure&) {
        std::cout << std::endl;
    }
    return 0;
}
