#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    Contact();
    Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
            const std::string& phoneNumber, const std::string& darkestSecret);

    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickname() const;
    const std::string& getPhoneNumber() const;
    const std::string& getDarkestSecret() const;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setNickname(const std::string& nickname);
    void setPhoneNumber(const std::string& phoneNumber);
    void setDarkestSecret(const std::string& darkestSecret);

private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

#endif // CONTACT_HPP
