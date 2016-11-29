#include <iostream>
#include "insertionsort.h"

int main(int argc,char **argv)
{
	int a[] = {23,12,543,1,21,44,123,2,-22,-231};
	int l = sizeof(a) / sizeof(int);

	std::cout << "The array is : " << std::endl;
	PrintArray(a,l);

	InsertionSort(a,l);
	std::cout << "After InsertionSort,the array is : " << std::endl;
	PrintArray(a,l);

	return 0;
}
