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

	int iArr2[] = {1, 1, 1, 1};
	Mat<int> iMat2 (2, 2, iArr2);

	int iArr3[] = {232, 534, 544, 34, 53, 54};
	Mat<int> iMat3 (2, 3, iArr3);
	iMat1.print ();
	iMat2.print ();
	
	iMat1 += iMat2;
	iMat1.print ();

	iMat1 *= iMat2;
	iMat1.print ();

	iMat2 = iMat1;
	iMat2.print ();
}
