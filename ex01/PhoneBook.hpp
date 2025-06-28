#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook();

    void addContact(const Contact& contact);

    int getSize() const;
    bool isEmpty() const;
    bool isFull() const;
    bool hasContactAt(int index) const;
    const Contact& getContactAt(int index) const;

private:
    static const int kMaxContacts = 8;
    Contact contacts[kMaxContacts];
    int size;
    int nextIndex;

    void checkInvariants() const;
};

#endif // PHONEBOOK_HPP
