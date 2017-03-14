#include <iostream>

using std::cout;
using std::endl;

int max_subsquence_A (int *arr, int sz, int &l, int &r);//转化为增量，右端索引可以求出，但是左端不太好求，本程序所求左端不正确
int max_subsquence_B (int *arr, int sz, int &l, int &r);//暴力求解

void print_array (int *arr, int sz);
void test_max_subsquence_A ();
void test_max_subsquence_B ();

int main (int argc, char *argv[])
{
	test_max_subsquence_A ();
	test_max_subsquence_B ();


	return 0;

}

int max_subsquence_A (int *arr, int sz, int &l, int &r)
{
	int max = arr[0];
	for (int i = 0; i < sz; ++i)
	{
		int sum = arr[i];

		for (int j = i + 1; j < sz; ++j)
		{
			l = j;
			sum += arr[j];
			if (sum > max)
			{
				max = sum;
				r = j;
			}
		}
	}

	return max;
}

void test_max_subsquence_A ()
{
	int iArr[] = {-13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int sz = sizeof (iArr) / sizeof (int);

	cout << "The sequence is : " << endl;
	print_array (iArr, sz);

	int left = 0;
	int right = 0;

	int max = max_subsquence_A (iArr, sz, left, right);
	cout << "The max subsquence is : " << max << " from " << left << " to " << right << endl;
}

void test_max_subsquence_B ()
{
	int iArr[] = {100, 113, 110, 85, 105, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
	int sz = sizeof (iArr) / sizeof (int);

	cout << "The sequence is : " << endl;
	print_array (iArr, sz);

	int left = 0;
	int right = 0;

	int max = max_subsquence_B (iArr, sz, left, right);
	cout << "The max subsquence is : " << max << " from " << left << " to " << right << endl;

}

void print_array (int *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int max_subsquence_B (int *arr, int sz, int &l, int &r)//暴力求解
{
	int max = 0;//这里初始化为0
	for (int i = 0; i < sz; ++i)
	{
		for (int j = i + 1; j < sz; ++j)
		{
			if (arr[j] - arr[i] > max)
			{
				max = arr[j] - arr[i];
				l = i;
				r = j;	
			}
		}
	}

	return max;
}
