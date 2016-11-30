#include <iostream>
#include "printarray.h"
#include "mergesort.h"

int main(int argc,char **argv)
{
	int arr[] = {232,123,2,1,44,22,4343,-23,435,65};
	int len = sizeof(arr) / sizeof(int);

	std::cout << "The array is : " << std::endl;
	PrintArray(arr,len);

	MergeSort(arr,0,len - 1);

	std::cout << "The array is : " << std::endl;
	PrintArray(arr,len);

	return 0;

}
