#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

const int NIL = -1;

template<typename T>
int find_element_in_array (const T *arr, int sz, const T &e);

void testA ();
void testB ();

int main (int argc, char *argv[])
{
	testA ();
	testB ();


	return 0;	
}

template<typename T>
int find_element_in_array (const T *arr, int sz, const T &e)
{
	for (int i = 0; i < sz; ++i)
	{
		if (e == arr[i])
			return i;
	}

	return NIL;
}

void testA ()
{
	int iArr[] = {23, 45, 22, 55, 12, 546, 3, 66, 5};
	int sz = sizeof (iArr) / sizeof (int);
	
	int a = 45;
	cout << find_element_in_array (iArr, sz, a) << endl;
}

void testB ()
{
	string strArr[] = {"hello", "world", "what", "are", "you", "doing"};
	int sz = sizeof (strArr) / sizeof (string);

	string s = "ou";
	cout << find_element_in_array (strArr, sz, s) << endl;
}
