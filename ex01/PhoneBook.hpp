#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  public:
    PhoneBook();

    int GetSize() const;
    const Contact& GetContactAtIndex(int index) const;

    void AddContact(const Contact& contact);

  private:
    static const int k_MaxContacts = 8;

    Contact m_Contacts[k_MaxContacts];
    int m_Size;
    int m_NextIndex;
};

#endif // PHONEBOOK_HPP
