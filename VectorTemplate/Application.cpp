#include <iostream>
#include "Vector.h"

int main() {
	Vector<int>* v1 = new Vector<int> (20);
	std::cout << "size is: " << v1->size();
	
	delete v1;
	return 0;
}