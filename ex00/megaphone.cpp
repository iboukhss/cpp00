#include <cctype>
#include <iostream>
#include <string>

static std::string toUppercase(const char* cstr)
{
    std::string res(cstr);
    for (std::string::iterator it = res.begin(); it != res.end(); ++it) {
        *it = std::toupper(static_cast<unsigned char>(*it));
    }
    return res;
}

int main(int argc, char* argv[])
{
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        std::cout << toUppercase(argv[i]);
    }
    std::cout << '\n';
    return 0;
}
