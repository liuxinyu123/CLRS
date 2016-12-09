#include <iostream>
#include "matrix.h"

int main(int argc,char **argv) 
{
	int r = 0;
	int c = 0;
	std::cout << "Please input matrix's row: " ;
	std::cin >> r;
	std::cout << "Please input matrix's colomn: ";
	std::cin >> c;

	Mat m1(r,c);
	m1.InitMat();
	m1.Write(2,4,123);
	m1.Write(1,1,32);
	m1.Write(2,3,323);
	m1.Write(2,2,23);

	Mat m2;
	m2.SetRow(r);
	m2.SetColomn(c);
	m2.Write(1,1,23);
	m2.Write(2,2,32);
	m2.Write(3,2,321);
	m2.Write(4,3,33);
	std::cout << "The matrix 1 is :" << std::endl;
	m1.Print();
	std::cout << "The matrix 1 is square? : " << m1.IsSquare() << std::endl;
	std::cout << "The matrix 2 is :" << std::endl;
	m2.Print();

	m1.Add(m2);
	std::cout << "Matrix 1 add Matrix 2 is : " << std::endl;
	m1.Print();

	m2.Subtract(m1);
	std::cout << "Matrix 2 subtract Matrix 1 is : " << std::endl;
	m2.Print();
	


	return 0;
}


