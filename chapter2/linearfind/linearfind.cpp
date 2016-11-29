#include <iostream>
#include "linearfind.h"

int LinearFind(ElemType *arr,int len,ElemType value)
{
	for(int i = 0; i < len; ++i)
	{
		if(value == arr[i])
		{
			return i;		
		}
	}

	return -1;
}
