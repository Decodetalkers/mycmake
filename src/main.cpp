#include <iostream>
#include "types.h"
#include "video.h"
int main (int argc, char *argv[])
{
	std::cout<< "Hello " << std::endl;
	int a = 10;
	add(a);
	std::cout << a << std::endl;
	if(sub(a)) {
		std::cout << a << std::endl;
	}
	return 0;
}
