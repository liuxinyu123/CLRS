#include <iostream>

using std::cout;
using std::endl;

int max_subsquence_A (int *arr, int sz, int &l, int &r);

void print_array (int *arr, int sz);
void test_max_subsquence_A ();

int main (int argc, char *argv[])
{
	test_max_subsquence_A ();


	return 0;

}

int max_subsquence_A (int *arr, int sz, int &l, int &r)//暴力求解
{
	int max = arr[0];
	int sum = 0;
	for (int i = 0; i < sz; ++i)
	{
		sum = arr[i];

		for (int j = i; j < sz; ++j)
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

	return sum;
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

void print_array (int *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

