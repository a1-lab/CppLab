#pragma once
#include <initializer_list>

class Vector
{
public:
    Vector(int size);
    Vector(std::initializer_list<int> list);
    Vector(Vector& obj);

    ~Vector();

    Vector& operator=(const Vector& obj);
    int& operator[](int i);
    int size();
private:
    int sz;
    int* elements;
};
