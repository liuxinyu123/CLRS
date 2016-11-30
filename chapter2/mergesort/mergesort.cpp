#include <new>
#include "mergesort.h"

void Merge(ElemType *arr,int l,int m,int r)
{
	int len1 = m - l + 1;
	int len2 = r - m;
	
	ElemType *la = new ElemType[len1];
	ElemType *ra = new ElemType[len2];

	for(int i = 0; i < len1; ++i)
	{
		la[i] = arr[l++];	
	}	

	for(int i = 0; i < len2; ++i)
		ra[i] = arr[++m];

	int rIdx = 0;
	int lIdx = 0;
	for(int i = l; i <= r; ++i)
	{
		if(la[lIdx] < ra[rIdx])
		{
			arr[i] = la[lIdx];
			++lIdx;
		}
		else
		{
			arr[i] = ra[rIdx];
			++rIdx;
		}
	}
}

void MergeSort(ElemType *arr,int begin,int end)
{
	if(begin < end)
	{
		int mid = (begin + end) / 2;
		MergeSort(arr,begin,mid);
		MergeSort(arr,mid + 1,end);
		Merge(arr,begin,mid,end);
	}
}

