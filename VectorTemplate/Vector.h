#pragma once

template<typename T>
class Vector
{
private:
	T* elements;
	int sz;
public:
	Vector(int size);
	~Vector();

	T& operator[](int i);
	const T& operator[](int i) const;
	int size() const;
};

template<typename T>
Vector<T>::Vector(int size)
{
	this->elements = new T[size];
	this->sz = size;
}

template<typename T>
Vector<T>::~Vector()
{
	delete elements;
}

template<typename T>
T& Vector<T>::operator[](int i)
{
	return elements[i];
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
	return elements[i];
}

template<typename T>
int Vector<T>::size() const
{
	return sz;
}
