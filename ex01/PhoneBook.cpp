#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : m_size(0), m_next_index(0)
{
}

void PhoneBook::AddContact(const Contact& contact)
{
    m_contacts[m_next_index] = contact;
    m_next_index = (m_next_index + 1) % k_max_contacts;
    if (m_size < k_max_contacts)
    {
        m_size++;
    }
}

const Contact* PhoneBook::GetContactAtIndex(int index) const
{
    if (index < 0 || index >= m_size)
    {
        return NULL;
    }
    return &m_contacts[index];
}

int PhoneBook::Size() const
{
    return m_size;
}
