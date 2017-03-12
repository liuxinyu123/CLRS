#include <iostream>

using std::cout;
using std::endl;

void binary_addtion (int arr1[8], int arr2[8], int arr3[9]);
void print_array (int *arr, int sz);
void dec_to_bin (int num, int arr[8]);//assert num < 100

int main (int argc, char *argv[])
{
	int a = 23;
	int a_bin_arr[8] = {0};
	int b = 45;
	int b_bin_arr[8] = {0};
	dec_to_bin (a, a_bin_arr);	
	dec_to_bin (b, b_bin_arr);

	cout << a << " = ";
	print_array (a_bin_arr, 8);
	cout << b << " = ";
	print_array (b_bin_arr, 8);
	
	int c_bin_arr[9] = {0};
	binary_addtion (a_bin_arr, b_bin_arr, c_bin_arr);
	cout << a + b << " = ";
	print_array (c_bin_arr, 9);

	return 0;
}


void binary_addtion (int arr1[8], int arr2[8], int arr3[9])
{
	int carry = 0;
	for (int i = 8; i >= 0; --i)
	{
		arr3[i] = (arr1[i - 1] + arr2[i - 1] + carry) % 2;
		carry = (arr1[i - 1] + arr2[i - 1] + carry) / 2;		
	}		
}

void print_array (int *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
		cout << arr[i];
	cout << endl;
}

void dec_to_bin (int num, int arr[8])
{
	for (int i = 7; num > 0 && i >= 0; --i)
	{
		arr[i] = num % 2;
		num /= 2;
	}
}
