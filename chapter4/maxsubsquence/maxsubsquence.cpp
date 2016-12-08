#include <climits>
#include "maxsubsquence.h"

int FindMax1(int *arr,int len)
{
	int maxSum = arr[0];

	for(int i = 0; i < len; ++i)
	{
		int sum = 0;

		for(int j = i; j < len; ++j)
		{
			sum += arr[j];
			if(sum > maxSum)
				maxSum = sum;
		}
	}

	return maxSum;
}

int FindMaxCrossArray(int *arr,int lo,int mid,int hi)
{
	int leftSum = arr[mid];
	int sum = 0;
	for(int i = mid; i >= lo; --i)
	{
		sum += arr[i];
		if(sum > leftSum)
			leftSum = sum;
	}	

	sum = 0;
	int rightSum = arr[mid + 1];
	for(int i = mid + 1; i <= hi; ++i)
	{
		sum += arr[i];
		if(sum > rightSum)
			rightSum = sum;
	}

	return (leftSum + rightSum);
}

int FindMax(int *arr,int lo,int hi)
{
	if(lo == hi)
		return arr[lo];
		
	int mid = (lo + hi) / 2;
	int leftMax = FindMax(arr,lo,mid);
	int rightMax = FindMax(arr,mid + 1,hi);
	int crossMax = FindMaxCrossArray(arr,lo,mid,hi);
	
	if(leftMax >= rightMax && leftMax >= crossMax)
		return leftMax;
	else if(rightMax >= leftMax && rightMax >= crossMax)
		return rightMax;
	else
		return crossMax;
}

int FindMax2(int *arr,int len)
{
	int sum = arr[0];
	int max = arr[0];

	for(int i = 1; i < len; ++i)
	{
		if(sum <= 0)
			sum = arr[i];
		else
			sum += arr[i];

		if(sum > max)
			max = sum;

	}

	return max;
}
