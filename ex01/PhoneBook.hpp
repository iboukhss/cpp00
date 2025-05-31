#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  public:
    PhoneBook();

    int Size() const;
    const Contact* GetContactAtIndex(int index) const;

    void AddContact(const Contact& contact);

  private:
    static const int k_max_contacts = 8;
    Contact m_contacts[k_max_contacts];
    int m_size;
    int m_next_index;
};

#endif // PHONEBOOK_HPP
