#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template<typename T>
void selection_sort (T *arr, int sz);

template<typename T>
void swap (T &a, T &b);

template<typename T>
void print_array (T *arr, int sz);

void test_selection_sort ();
void test_selection_sort_A ();

int main (int argc, char *argv[])
{
	test_selection_sort ();
	test_selection_sort_A ();

	return 0;
}

void test_selection_sort ()
{
	int iArr[] = {23, 233, 422, 44, 1, 34, -23, 332};
	int sz = sizeof (iArr) / sizeof (int);
	
	cout << "Before sort: " << endl;
	print_array (iArr, sz);

	selection_sort (iArr, sz);
	cout << "After sort: " << endl;
	print_array (iArr, sz);

}

void test_selection_sort_A ()
{
	string strArr[] = {"hello", "world", "what", "are", "you", "doing"};
	int sz = sizeof (strArr) / sizeof (string);

	cout << "Before sort: " << endl;
	print_array (strArr, sz);

	selection_sort (strArr, sz);
	cout << "After sort: " << endl;
	print_array (strArr, sz);
}

template<typename T>
void selection_sort (T *arr, int sz)
{
	for (int i = 0; i < sz - 1; ++i)
	{
		int idx = i;
		for (int j = i + 1; j < sz; ++j)
		{
			if (arr[j] < arr[idx])
				idx = j;
		}

		swap (arr[i], arr[idx]);
	}
	
}

template<typename T>
void swap (T &a, T &b)
{
	T tmp = b;
	b = a;
	a = tmp;
}

template<typename T>
void print_array (T *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
