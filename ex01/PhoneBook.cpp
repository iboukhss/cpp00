#include "PhoneBook.hpp"

#include <stdexcept>

PhoneBook::PhoneBook() : m_Size(0), m_NextIndex(0)
{
}

void PhoneBook::AddContact(const Contact& contact)
{
    m_Contacts[m_NextIndex] = contact;
    m_NextIndex = (m_NextIndex + 1) % k_MaxContacts;
    if (m_Size < k_MaxContacts)
    {
        m_Size++;
    }
}

const Contact& PhoneBook::GetContactAtIndex(int index) const
{
    if (index < 0 || index >= m_Size)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_Contacts[index];
}

int PhoneBook::GetSize() const
{
    return m_Size;
}
