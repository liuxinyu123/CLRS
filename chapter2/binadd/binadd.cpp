#include "binadd.h"

void BinAdd(int *arr1,int *arr2,int *res)
{
	int len = sizeof(arr1) / sizeof(int);
	
	int carry = 0;
	for(int i = len - 1; i >= 0; --i)
	{
		carry = 0;
		if(arr1[i] + arr2[i] + carry >= 2)
		{
			carry = 1;
			res[i + 1] = (carry + arr1[i] + arr2[i]) % 2;
		}
		
	}

	res[0] = carry;
}
