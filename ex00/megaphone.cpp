#include <cctype>
#include <iostream>
#include <string>

char char_to_uppercase(char c)
{
    return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

void string_to_uppercase(std::string &s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        s[i] = char_to_uppercase(s[i]);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        std::string s(argv[i]);
        string_to_uppercase(s);
        std::cout << s;
    }
    std::cout << '\n';
    return 0;
}
