#include "selectionsort.h"

void Swap(ElemType &l,ElemType &r)
{
	ElemType t = l;
	l = r;
	r = t;
}

int FindMinIndex(ElemType *arr,int begin,int end)
{
	int idx = begin;
	ElemType min = arr[idx];

	for(int i = begin; i < end; ++i)
	{
		if(arr[i] < min)
		{
			idx = i;
			min = arr[idx];
		}
	}

	return idx;
}

void SelectionSort(ElemType *arr,int len)
{
	for(int i = 0; i <= len - 2; ++i)
	{
		int idx = FindMinIndex(arr,i,len);
		Swap(arr[i],arr[idx]);
	}
}
