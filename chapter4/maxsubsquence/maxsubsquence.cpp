#include <climits>
#include "maxsubsquence.h"

ps FindMaxCrossArray(int *arr,Index lo,Index mid,Index hi)
{
	ps p;
	
	int leftSum = INT_MIN;
	int leftIndex = mid;
	int left = mid;
	int sum = 0;
	while(leftIndex >= lo)
	{
		sum += arr[leftIndex];
		if(sum > leftSum)
		{
			leftSum = sum;
			left = leftIndex;
		}

		--leftIndex;
	}
	
	sum = 0;
	int rightIndex = mid + 1;
	int right = mid + 1;
	int rightSum = INT_MIN;
	while(rightIndex <= hi)
	{
		sum += arr[rightIndex];
		if(sum > rightSum)
		{
			rightSum = sum;
			right = rightIndex;
		}
	}

	p -> begin = left;
	p -> end = right;
	p -> sum = leftSum + rightSum;

	return p;
}

ps FindMax(int *arr,Index lo,Index hi)
{
	ps lp;
	ps rp;
	ps cp;
	ps p;

	if(lo == hi)
	{
		p -> begin = lo;
		p -> end = hi;
		p -> sum = arr[lo];

		return p;
	}

	else
	{
		int mid = (lo + hi) / 2;
		lp = FindMax(arr,lo,mid);
		rp = FindMax(arr,mid + 1,hi);
		cp = FindMaxCrossArray(arr,lo,mid,hi);
	}

	if(lp -> sum > rp -> sum && lp -> sum > cp -> sum)
		return lp;
	else if(rp -> sum > lp -> sum && rp -> sum > cp -> sum)
		return rp;
	else
		return cp;
}
