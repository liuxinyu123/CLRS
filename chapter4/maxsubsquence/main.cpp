#include <iostream>
#include "maxsubsquence.h"
#include "printarray.h"

int main(int argc,char **argv)
{
	int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,-15,-4,7};
	int len = sizeof(a) / sizeof(int);
	
	ps p = FindMax(a,0,len - 1);

	std::cout << "The array is : " << std::endl;
	PrintArray(a,len);

	std::cout << "The maxsubsquence's sum is " << p -> sum << 
			" is from index of " << p -> begin << " to " << p -> end << std::endl;

	return 0;
}
