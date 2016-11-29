#include <iostream>
#include "linearfind.h"
#include "printarray.h"

int main(int argc,char **argv)
{
	int a[] = {2,34,333,23,1,634,-3,-312,231,22,11,33};
	int l = sizeof(a) / sizeof(int);

	std::cout << "The array is: " << std::endl;
	PrintArray(a,l);
	
	std::cout << "Please input an integer value: " ;
	int v = 0;
	std::cin >> v;

	std::cout << std::endl;
	std::cout << v << " in the array is in the index of " << LinearFind(a,l,v) << std::endl;
	
	return 0;	
}
