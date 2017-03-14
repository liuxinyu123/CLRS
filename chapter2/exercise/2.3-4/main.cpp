#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template<typename T>
void insert_sort_incursive (T *arr, int sz);

template<typename T>
void print_array (T *arr, int sz);

void test_insert_sort ();
void test_insert_sort_A ();

int main (int argc, char *argv[])
{
	test_insert_sort ();
	test_insert_sort_A ();

	return 0;
}

template<typename T>
void insert_sort_incursive (T *arr, int sz)
{
	if (sz > 1)
	{
		insert_sort_incursive (arr, sz - 1);

		int i = sz - 2;//排好序的最后一个元素
		T tmp = arr[sz - 1];//未排序的元素
		while (i >= 0 && tmp < arr[i])
		{
			arr[i + 1] = arr[i];
			--i;
		}
		arr[i + 1] = tmp;
	}
}

void test_insert_sort ()
{
	int iArr[] = {32, 245, 54, 23, 55, 35, 66, -23};
	int sz = sizeof (iArr) / sizeof (int);

	cout << "Before sort:" << endl;
	print_array (iArr, sz);

	insert_sort_incursive (iArr, sz);

	cout << "After sort:" << endl;
	print_array (iArr, sz);
}

void test_insert_sort_A ()
{
	string strArr[] = {"hello", "world", "what", "are", "you", "doing"};
	int sz = sizeof (strArr) / sizeof (string);

	cout << "Before sort:" << endl;
	print_array (strArr, sz);

	insert_sort_incursive (strArr, sz);

	cout << "After sort:" << endl;
	print_array (strArr, sz);
	

}
template<typename T>
void print_array (T *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
