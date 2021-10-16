/*https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019#enable-memory-leak-detection*/

#include "console_mem_leak_debug.h"


int main()
{
	std::cout << "Hello World!\n";

	int* pi = new int;

	_CrtDumpMemoryLeaks();
}





