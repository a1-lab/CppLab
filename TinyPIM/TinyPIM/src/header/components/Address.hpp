#pragma once
class Address {
public:
	Address();
	Address(const Address&);
	~Address();

	const Address& operator=(const Address&);

	const char* getFirstName() const;
	void setFirstName(const char*);
	const char* getLastName() const;
	void setLastName(const char*);
	const char* getPhone() const;
	void setPhone(const char*);
	const char* getAddress() const;
	void setAddress(const char*);
private:
	char* m_firstname;
	char* m_lastname;
	char* m_phone;
	char* m_address;

	char* copy_string(const char*);
};

