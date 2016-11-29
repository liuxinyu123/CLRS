#include <iostream>
#include "insertionsort.h"

void PrintArray(ElemType *arr,int len)
{
	for(int i = 0; i < len; ++i)
		std::cout << arr[i] << " " ;

	std::cout << std::endl;
}

void InsertionSort(ElemType *arr,int len)
{
	for(int i = 1; i < len; ++i)
	{
		ElemType temp = arr[i];

		int j = i - 1;
		while(j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			--j;
		}

		arr[j + 1] = temp;
	}
}
