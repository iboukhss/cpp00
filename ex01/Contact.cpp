#include "Contact.hpp"

// Getters
std::string Contact::GetFirstName() const
{
    return m_FirstName;
}

std::string Contact::GetLastName() const
{
    return m_LastName;
}

std::string Contact::GetNickname() const
{
    return m_Nickname;
}

std::string Contact::GetPhoneNumber() const
{
    return m_PhoneNumber;
}

std::string Contact::GetDarkestSecret() const
{
    return m_DarkestSecret;
}

// Setters
void Contact::SetFirstName(const std::string& firstName)
{
    m_FirstName = firstName;
}

void Contact::SetLastName(const std::string& lastName)
{
    m_LastName = lastName;
}

void Contact::SetNickname(const std::string& nickname)
{
    m_Nickname = nickname;
}

void Contact::SetPhoneNumber(const std::string& phoneNumber)
{
    m_PhoneNumber = phoneNumber;
}

void Contact::SetDarkestSecret(const std::string& darkestSecret)
{
    m_DarkestSecret = darkestSecret;
}
