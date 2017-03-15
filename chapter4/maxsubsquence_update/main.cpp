#include <iostream>
#include <utility>

using std::cout;
using std::endl;

int max_subsquence_A (int *arr, int sz, int &l, int &r);//转化为增量，右端索引可以求出，但是左端不太好求，本程序所求左端不正确
int max_subsquence_B (int *arr, int sz, int &l, int &r);//暴力求解
int max_subsquence_recursive (int *arr, int l, int r);//最大子数组的递归求解
std::pair<int, int> find_max_crossing_subsquence (int *arr, int l, int m, int h, int &s);//返回索引，s作为和返回

void print_array (int *arr, int sz);
void test_max_subsquence_A ();
void test_max_subsquence_B ();
void test_max_subsquence_recursive ();
int max_in_three (int a, int b, int c);

int main (int argc, char *argv[])
{
	test_max_subsquence_A ();
	test_max_subsquence_B ();
	test_max_subsquence_recursive ();


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

int max_subsquence_recursive (int *arr, int l, int r)//arr[l,r]
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		int lmax = max_subsquence_recursive (arr, l, mid);
		int rmax = max_subsquence_recursive (arr, mid + 1, r);
		int mmax = 0;
		auto lr = find_max_crossing_subsquence (arr, l, mid, r, mmax);
		
		return max_in_three (lmax, rmax, mmax);


	}

	return 0;
}

std::pair<int, int> find_max_crossing_subsquence (int *arr, int l, int m, int r, int &s)
{
	int lsum = 0;//最好设为负无穷
	int sum = 0;
	int left = m;
	for (int i = m; i >= l; --i)
	{
		sum += arr[i];

		if (sum > lsum)
		{
			lsum = sum;
			left = i;	
		}
	}

	int rsum = 0;//最好设为负无穷
	int right = m + 1;
	for (int i = m + 1; i <= r; ++i)
	{
		sum += arr[i];
		if (sum > rsum)
		{
			rsum = sum;
			right = i;
		}
	}
	
	s = lsum + rsum;

	return std::make_pair(left, right);
	
}

int max_in_three (int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		else
			return c;
	}
	else
	{
		if (b > c)
			return b;
		else
			return c;
	}
}

void test_max_subsquence_recursive ()
{
	int iArr[] = {-13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int sz = sizeof (iArr) / sizeof (int);

	cout << "The sequence is : " << endl;
	print_array (iArr, sz);

	int left = 0;
	int right = 0;

	int max = max_subsquence_recursive (iArr,0, sz - 1);
	cout << "The max subsquence is : " << max << " from " << left << " to " << right << endl;
	
}
