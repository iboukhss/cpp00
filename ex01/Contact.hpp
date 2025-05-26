#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
  public:
    void set_first_name(const std::string &first_name);
    void set_last_name(const std::string &last_name);
    void set_nickname(const std::string &nickname);
    void set_phone_number(const std::string &phone_number);
    void set_darkest_secret(const std::string &darkest_secret);

    std::string first_name() const;
    std::string last_name() const;
    std::string nickname() const;
    std::string phone_number() const;
    std::string darkest_secret() const;

  private:
    std::string first_name_;
    std::string last_name_;
    std::string nickname_;
    std::string phone_number_;
    std::string darkest_secret_;
};

#endif // CONTACT_HPP
