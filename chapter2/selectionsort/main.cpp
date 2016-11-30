#include <iostream>
#include "printarray.h"
#include "selectionsort.h"

int main(int argc,char **argv)
{
	int a[] = {232,34,12,1,54,-34,-332,44,2212};
	int l = sizeof(a) / sizeof(int);

	std::cout << "The array is : " << std::endl;
	PrintArray(a,l);

	SelectionSort(a,l);
	std::cout << "After SelectionSort,the array is : " << std::endl;
	PrintArray(a,l);

	return 0;

}
