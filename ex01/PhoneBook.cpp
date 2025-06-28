#include "PhoneBook.hpp"

#include <cassert>

PhoneBook::PhoneBook()
    : size(0),
      nextIndex(0)
{
}

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

bool PhoneBook::hasContactAt(int index) const
{
    return (index >= 0 && index < size);
}

const Contact& PhoneBook::getContactAt(int index) const
{
    assert(!isEmpty());
    assert(hasContactAt(index));
    return contacts[index];
}

void PhoneBook::checkInvariants() const
{
    assert(kMaxContacts > 0);
    assert(size >= 0 && size <= kMaxContacts);
    assert(nextIndex >= 0 && nextIndex < kMaxContacts);
}

void PhoneBook::addContact(const Contact& contact)
{
    checkInvariants();
    contacts[nextIndex] = contact;
    nextIndex = (nextIndex + 1) % kMaxContacts;
    if (size < kMaxContacts) {
        ++size;
    }
}
