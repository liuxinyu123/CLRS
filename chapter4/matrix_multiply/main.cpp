#include <iostream>
#include "mat.h"

using std::cout;
using std::endl;

void test_mat ();

int main (int argc, char *argv[])
{
	test_mat ();

	return 0;	
}

void test_mat ()
{
	int iArr[] = {1, 3, 5, 7};
	Mat<int> iMat(2, 2, iArr);

	cout << iMat << endl;
	cout << iMat.row () << " " << iMat.column () << endl;
}
