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
	int iArr[] = {23, 44, 43, 2, 355, 12, 45, -23, 55};
	int sz = sizeof (iArr) / sizeof (int);

	cout << "Before sort: " << endl;
	print_array (iArr, sz);

	merge_sort (iArr, 0, sz - 1);
	
	cout << "After sort: " << endl;
	print_array (iArr, sz);
}

void test_merge_sort_A ()
{

}

template<typename T>
void merge (T *arr, int p, int r, int q)//合并已经排好序的arr[p,r] arr[r+1,q]
{	
	int lsz = r - p + 1;
	int rsz = q - r;
	T *lArr = new T[lsz];
	T *rArr = new T[rsz];

	copy_array (arr, lArr, lsz);
	copy_array (arr + lsz, rArr, rsz);
	
	int i = 0;//lArr 的索引
	int j = 0;//rArr的索引

	while (p <= r)
	{
		if (lArr[i] < rArr[j] || j >= rsz)
			arr[p++] = lArr[i++];
		else 
			arr[p++] = rArr[j++];
	}
/*	
	while (i < lsz && j < rsz)//lArr和rArr任何一个都不为空
	{
		if (lArr[i] < rArr[j])
			arr[p++] = lArr[i++];		
		else
			arr[p++] = rArr[j];
	}

	if (i >= lsz)//lArr空了
	{
		for (;j < rsz; ++j)
			arr[p++] = rArr[j];
	}
	else
	{
		for (;i < lsz; ++i)
			arr[p++] = lArr[i];
	}
*/

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
