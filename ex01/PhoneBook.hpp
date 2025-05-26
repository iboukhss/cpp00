#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  public:
    PhoneBook();

    void AddContact(const Contact &contact);
    const Contact *GetContactAtIndex(int index) const;

    int size() const;

  private:
    static const int kMaxContacts = 8;

    Contact contacts_[kMaxContacts];
    int size_;
    int next_index_;
};

#endif // PHONEBOOK_HPP
