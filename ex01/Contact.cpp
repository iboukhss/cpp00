#include "Contact.hpp"

// Setters
void Contact::set_first_name(const std::string &first_name)
{
    first_name_ = first_name;
}

void Contact::set_last_name(const std::string &last_name)
{
    last_name_ = last_name;
}

void Contact::set_nickname(const std::string &nickname)
{
    nickname_ = nickname;
}

void Contact::set_phone_number(const std::string &phone_number)
{
    phone_number_ = phone_number;
}

void Contact::set_darkest_secret(const std::string &darkest_secret)
{
    darkest_secret_ = darkest_secret;
}

// Getters
std::string Contact::first_name() const
{
    return first_name_;
}

std::string Contact::last_name() const
{
    return last_name_;
}

std::string Contact::nickname() const
{
    return nickname_;
}

std::string Contact::phone_number() const
{
    return phone_number_;
}

std::string Contact::darkest_secret() const
{
    return darkest_secret_;
}
