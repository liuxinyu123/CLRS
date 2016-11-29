#include <iostream>
#include "binadd.h"
#include "printarray.h"

int main(int argc,char **argv)
{
	int a1[5] = {1,1,0,0,1};
	int a2[5] = {1,1,1,1,1};
	int res[6] = {0};

	std::cout << "The array 1 is : " << std::endl;
	PrintArray(a1,5);
	std::cout << "The array 2 is : " << std::endl;
	PrintArray(a2,5);

	BinAdd(a1,a2,res);
	
	std::cout << "The result array of addition of array 1 and array 2 is : " << std::endl;
	PrintArray(res,6);

	return 0;
}
