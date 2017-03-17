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
	int iArr1[] = {1, 3, 5, 7};
	Mat<int> iMat1(2, 2, iArr1);

	int iArr2[] = {3, 32, 54, 23};
	Mat<int> iMat2 (2, 2, iArr2);
	//cout << iMat << endl;
	iMat1.print ();
	iMat2.print ();
	//cout << iMat.row () << " " << iMat.column () << endl;
	
	iMat1 += iMat2;
	iMat1.print ();
}
