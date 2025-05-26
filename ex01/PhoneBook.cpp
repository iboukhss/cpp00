#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : size_(0), next_index_(0)
{
    // Empty
}

void PhoneBook::AddContact(const Contact &contact)
{
    contacts_[next_index_] = contact;
    next_index_ = (next_index_ + 1) % kMaxContacts;
    if (size_ < kMaxContacts)
    {
        size_++;
    }
}

const Contact *PhoneBook::GetContactAtIndex(int index) const
{
    if (index < 0 || index >= size_)
    {
        return NULL;
    }
    return &contacts_[index];
}

int PhoneBook::size() const
{
    return size_;
}
