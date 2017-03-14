#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void test_merge_sort ();
void test_merge_sort_A ();

template<typename T>
void merge (T *arr, int p, int r, int q);

template<typename T>
void merge_sort (T *arr, int l, int r);

template<typename T>
void copy_array (T *sArr, T *dArr, int sz);

template<typename T>
void print_array (T *arr, int sz);

int main (int argc, char *argv[])
{
	test_merge_sort ();
	test_merge_sort_A ();

	return 0;
}

void test_merge_sort ()
{
	int iArr[] = {23, 44, 43, 2, 355, 12, 45, -23};
	int sz = sizeof (iArr) / sizeof (int);

	cout << "Before sort: " << endl;
	print_array (iArr, sz);

	merge_sort (iArr, 0, sz - 1);
	
	cout << "After sort: " << endl;
	print_array (iArr, sz);
}

void test_merge_sort_A ()
{
	string strArr[] = {"hello", "world", "what", "are", "you", "doing", "fuck", "you", "sorry"};
	int sz = sizeof (strArr) / sizeof (string);

	cout << "Before sort: " << endl;
	print_array (strArr, sz);

	merge_sort (strArr, 0, sz - 1);
	cout << "After sort: " << endl;
	print_array (strArr, sz);
}

template<typename T>
void merge (T *arr, int p, int r, int q)//合并已经排好序的arr[p,r] arr[r+1,q]
{	
	int lsz = r - p + 1;
	int rsz = q - r;
	T *lArr = new T[lsz];
	T *rArr = new T[rsz];

	copy_array (arr + p, lArr, lsz);
	copy_array (arr + r + 1, rArr, rsz);
	//print_array (lArr, lsz);
	//print_array (rArr, rsz);
	
	int i = 0;//lArr 的索引
	int j = 0;//rArr的索引
/*
	while (p <= r)
	{
		if (i < lsz && j < rsz)
		{
			if (lArr[i] < rArr[j])
				arr[p++] = lArr[i++];
			else
				arr[p++] = rArr[j++];
		}
		else if (i >= lsz)
			arr[p++] = rArr[j++];
		else
			arr[p++] = lArr[++i];
	}
*/
/*
	while (p <= r)
	{
		if (i < lsz && j >= rsz)
			arr[p++] = lArr[i++];
		if (j < rsz && i >= lsz)
			arr[p++] = rArr[j++];
		if (i < lsz && j < rsz && lArr[i] < rArr[j])
			arr[p++] = lArr[i++];
		if (i < lsz && j < rsz && rArr[j] < lArr[i])
			arr[p++] = rArr[j++];
	}
*/
	int k = p;	
	while (i < lsz && j < rsz)//lArr和rArr任何一个都不为空
	{
		if (lArr[i] <= rArr[j])
			arr[k++] = lArr[i++];		
		else
			arr[k++] = rArr[j++];
	}

	while (i < lsz)//lArr不为空
	{
		arr[k++] = lArr[i++];
	}
	while (j < rsz)//rArr 不为空
	{
		arr[k++] = rArr[j++];
	}


	delete [] lArr;
	delete [] rArr;
		
}

template<typename T>
void merge_sort (T *arr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		merge_sort (arr, l, m);
		merge_sort (arr, m + 1, r);
		merge (arr, l, m, r);
	}	
}
template<typename T>
void copy_array (T *sArr, T *dArr, int sz)
{
	for (int i = 0; i < sz; ++i)
		dArr[i] = sArr[i];
}

template<typename T>
void print_array (T *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
