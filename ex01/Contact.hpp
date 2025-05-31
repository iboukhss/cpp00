#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
  public:
    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetNickname() const;
    std::string GetPhoneNumber() const;
    std::string GetDarkestSecret() const;

    void SetFirstName(const std::string& firstName);
    void SetLastName(const std::string& lastName);
    void SetNickname(const std::string& nickname);
    void SetPhoneNumber(const std::string& phoneNumber);
    void SetDarkestSecret(const std::string& darkestSecret);

  private:
    std::string m_FirstName;
    std::string m_LastName;
    std::string m_Nickname;
    std::string m_PhoneNumber;
    std::string m_DarkestSecret;
};

#endif // CONTACT_HPP
