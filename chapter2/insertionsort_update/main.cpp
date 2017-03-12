#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::endl;
using std::string;

void test_sort_A ();//测试insert_sort
void test_sort_B ();//test insert_sort_A

template<typename T>
void insertion_sort (T *arr, int sz);//从前向后比较，然后在移动

template<typename T>
void insertion_sort_A (T *arr, int sz);//从后向前比较，同时移动,利用了交换技术

template<typename T>
void print_array (T *arr, int sz);

template<typename T>
void move_behind_after (T &arr, int begin, int end);

int main (int argc, char *argv[])
{
	std::clock_t b1 = clock ();
	test_sort_A ();
	std::clock_t e1	= clock ();
	
	cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;

	std::clock_t b2 = clock ();
	test_sort_B ();
	std::clock_t e2 = clock ();

	cout << "Time elapse " << e1 - b1 << endl;
	cout << "Time elapse " << e2 - b2 << endl;

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
inline void move_behind_after (T &arr, int begin, int end) //[begin, end]包含的元素向后移动一个单位
{
	for (int i = end; i >= begin; --i)
		arr[i + 1] = arr[i];
}

template<typename T>
void insertion_sort_A (T *arr, int sz)
{
	for (int i = 1; i < sz; ++i)
	{
		T key = arr[i];

		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			arr[j] = key;
			--j;
		}
	}
}

void test_sort_A ()
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

}

void test_sort_B ()
{
	int iArr[] = {34, 44, 32, 1, 45, 22, 44};
	int sz = sizeof (iArr) / sizeof (int);
	cout << "Before sort: " << endl;
	print_array (iArr, sz);

	insertion_sort_A (iArr, sz);
	cout << "After sort: " << endl;
	print_array (iArr, sz);

	string strArr[] = {"hello", "world", "what", "are", "you", "doing"};
	int sz1 = sizeof (strArr) / sizeof (string);
	cout << "Before sort: " << endl;
	print_array (strArr, sz1);

	insertion_sort_A (strArr, sz1);
	cout << "After sort: " << endl;
	print_array (strArr, sz1);
		
}
