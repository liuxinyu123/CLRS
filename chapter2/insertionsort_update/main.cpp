#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template<typename T>
void insertion_sort (T *arr, int sz);

template<typename T>
void print_array (T *arr, int sz);

template<typename T>
void move_behind_after (T &arr, int begin, int end);

int main (int argc, char *argv[])
{
	int iArr[] = {34, 44, 32, 1, 45, 22, 44};
	int sz = sizeof (iArr) / sizeof (int);
	cout << "Before sort: " << endl;
	print_array (iArr, sz);

	insertion_sort (iArr, sz);
	cout << "After sort: " << endl;
	print_array (iArr, sz);

	string strArr[] = {"hello", "world", "what", "are", "you", "doing"};
	int sz1 = sizeof (strArr) / sizeof (string);
	cout << "Before sort: " << endl;
	print_array (strArr, sz1);

	insertion_sort (strArr, sz1);
	cout << "After sort: " << endl;
	print_array (strArr, sz1);
	

	return 0;
}

template<typename T>
void print_array (T *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

template<typename T>
void insertion_sort (T *arr, int sz)
{
	for (int i = 1; i < sz; ++i)
	{
		T key = arr[i];

		for (int j = 0; j < i; ++j)
		{
			if (key < arr[j])
			{
				move_behind_after (arr, j, i - 1);
				arr[j] = key;
				break;
			}
		}
	}	
}

template<typename T>
void move_behind_after (T &arr, int begin, int end) //[begin, end]包含的元素向后移动一个单位
{
	for (int i = end; i >= begin; --i)
		arr[i + 1] = arr[i];
}
