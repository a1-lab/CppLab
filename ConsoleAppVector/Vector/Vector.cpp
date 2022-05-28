#include "Vector.h"

Vector::Vector(int size) : sz{size}
{
	elements = new int[size];
}

Vector::Vector(std::initializer_list<int> list) : Vector(list.size())
{
	int i = 0;
	for (auto o: list) {
		elements[i] = o;
		i++;
	}
}

Vector::Vector(Vector& obj) : elements{new int[obj.sz]}, sz{obj.sz}
{
	for (int i = 0; i < sz; i++) {
		this->elements[i] = obj.elements[i];
	}
}

Vector::~Vector()
{
	delete[] elements;
}

Vector& Vector::operator=(const Vector& obj)
{
	return *this;
}

int& Vector::operator[](int i)
{
	return elements[i];
}

int Vector::size()
{
	return sz;
}
