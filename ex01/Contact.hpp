#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
  public:
    std::string FirstName() const;
    std::string LastName() const;
    std::string Nickname() const;
    std::string PhoneNumber() const;
    std::string DarkestSecret() const;

    void SetFirstName(const std::string& first_name);
    void SetLastName(const std::string& last_name);
    void SetNickname(const std::string& nickname);
    void SetPhoneNumber(const std::string& phone_number);
    void SetDarkestSecret(const std::string& darkest_secret);

  private:
    std::string m_first_name;
    std::string m_last_name;
    std::string m_nickname;
    std::string m_phone_number;
    std::string m_darkest_secret;
};

#endif // CONTACT_HPP
