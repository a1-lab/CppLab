#include "iostream"
#include "Vector.h"

namespace test_on_stack{
	int main() {
		Vector v = { 1,2,3,4,5,6,7,8 };
		std::cout << "Vector size: " << v.size() << std::endl;
		std::cout << "End Application";
		
		return 0;
	}
}

namespace test_on_heap {
	int main() {
		Vector* v = new Vector({ 1,2,3,4,5,6,7,8,9,10 });
		Vector& ref = *v;
		ref[0] = 1;
		(*v)[0] = 3;
		double value = (*v)[0];

		std::cout << "Vector size: " << v->size() << std::endl;
		std::cout << "v[0]: " << value << std::endl;

		delete v;
		std::cout << "End Application";

		return 0;
	}
}

namespace test_copy_constructor {
	int main(){
		Vector v1 = { 1,2,3,4 };
		Vector v2{ v1 };

	    return 0;
	}
}

int main() {
	return test_on_heap::main();
}