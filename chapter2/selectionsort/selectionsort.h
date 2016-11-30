#ifndef _SELECTIONSORT_H_
#define _SELECTIONSORT_H_

typedef int ElemType;

void SelectionSort(ElemType *arr,int len);
int FindMinIndex(ElemType *arr,int begin,int end);
void Swap(ElemType &l,ElemType &r);

#endif
