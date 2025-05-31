#include "Contact.hpp"

// Setters
void Contact::SetFirstName(const std::string& first_name)
{
    m_first_name = first_name;
}

void Contact::SetLastName(const std::string& last_name)
{
    m_last_name = last_name;
}

void Contact::SetNickname(const std::string& nickname)
{
    m_nickname = nickname;
}

void Contact::SetPhoneNumber(const std::string& phone_number)
{
    m_phone_number = phone_number;
}

void Contact::SetDarkestSecret(const std::string& darkest_secret)
{
    m_darkest_secret = darkest_secret;
}

// Getters
std::string Contact::FirstName() const
{
    return m_first_name;
}

std::string Contact::LastName() const
{
    return m_last_name;
}

std::string Contact::Nickname() const
{
    return m_nickname;
}

std::string Contact::PhoneNumber() const
{
    return m_phone_number;
}

std::string Contact::DarkestSecret() const
{
    return m_darkest_secret;
}
