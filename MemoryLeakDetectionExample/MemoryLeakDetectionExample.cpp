/*https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019#enable-memory-leak-detection*/

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>


int main()
{
	std::cout << "Hello World!\n";

	int* pi = new int;

	_CrtDumpMemoryLeaks();
}





