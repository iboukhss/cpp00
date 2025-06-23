#include "PhoneBook.hpp"

#include <cassert>
#include <stdexcept>

// Constructors
PhoneBook::PhoneBook()
    : size(0),
      nextIndex(0)
{
}

void PhoneBook::checkInvariants() const
{
    assert(kMaxContacts > 0);
    assert(size >= 0 && size <= kMaxContacts);
    assert(nextIndex >= 0 && nextIndex < kMaxContacts);
}

// Getters
int PhoneBook::getSize() const
{
    return size;
}

bool PhoneBook::isEmpty() const
{
    return (size == 0);
}

bool PhoneBook::isFull() const
{
    return (size == kMaxContacts);
}

const Contact* PhoneBook::getContactAt(int index) const
{
    if (size == 0 || (index < 0 || index >= size)) {
        return (NULL);
    }
    return &contacts[index];
}

// Setters
void PhoneBook::addContact(const Contact& contact)
{
    this->checkInvariants();

    contacts[nextIndex] = contact;
    nextIndex = (nextIndex + 1) % kMaxContacts;
    if (size < kMaxContacts) {
        ++size;
    }
}
