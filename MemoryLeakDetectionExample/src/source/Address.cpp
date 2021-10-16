#include <cstring>
#include "Address.hpp"

Address::Address() : m_firstname{new char[1]}, m_lastname{ new char[1] },
    m_phone{new char[1]}, m_address{new char[1]}
{
	m_firstname[0] = m_lastname[0] = m_phone[0] = m_address[0] = '\n';
}

Address::Address(const Address& a2) : m_firstname{ nullptr }, m_lastname{ nullptr },
m_phone{ nullptr }, m_address{ nullptr }
{
	*this = a2;
}

Address::~Address()
{
	delete[] m_firstname;
	delete[] m_lastname;
	delete[] m_phone;
	delete[] m_address;
}

const Address& Address::operator=(const Address& a2)
{
	if (this == &a2) {
		return *this;
	}

	setFirstName(a2.getFirstName());
	setLastName(a2.getLastName());
	setAddress(a2.getAddress());
	setPhone(a2.getPhone());

	return *this;
}

const char* Address::getFirstName() const
{
	return m_firstname;
}

void Address::setFirstName(const char* value)
{
	if (m_firstname != value) {
		delete[] m_firstname;
		m_firstname = copy_string(value);
	}
}

const char* Address::getLastName() const
{
	return m_lastname;
}

void Address::setLastName(const char* value)
{
	if (m_lastname != value) {
		delete[] m_lastname;
		m_lastname = copy_string(value);
	}
}

const char* Address::getPhone() const
{
	return m_phone;
}

void Address::setPhone(const char* value)
{
	if (m_phone != value) {
		delete[] m_phone;
		m_phone = copy_string(value);
	}
}

const char* Address::getAddress() const
{
	return m_address;
}

void Address::setAddress(const char* value)
{
	if (m_address != value) {
		delete[] m_address;
		m_address = copy_string(value);
	}
}

char* Address::copy_string(const char* source)
{
	//add 1 becouse of zero termination char. 
	const int length = std::strlen(source) + 1;
	char* result = new char[length];
	strcpy_s(result, length, source);

	return result;
}
