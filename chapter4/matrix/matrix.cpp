#include <iostream>
#include <string>
#include <new>
#include "matrix.h"

#define Error(str) (std::cout << (str) << std::endl)

Mat::Mat(int r,int c):row(r),col(c)
{
	data = new Type[row * col];
}

void Mat::SetRow(int r)
{
	row = r;
}

void Mat::SetColomn(int c)
{
	col = c;
}

void Mat::InitMat()
{
	data = new Type[row * col];
}

void Mat::FreeMat()
{
	delete []data;
}

Type Mat::Read(int r,int c)
{
	if(r > row || c >> col)
	{
		Error("Invalid Parameter!");
		return -1;
	}

	return data[r * c - 1];
}

void Mat::Write(int r,int c,Type d)
{ 
	if(r > row || c > col)
	{
		Error("Invalid Parameter!");
		return;
	}
	
	data[r * c - 1] = d;
}

int Mat::GetRow()
{
	return row;
}

int Mat::GetColomn()
{
	return col;
}

int Mat::IsSquare()
{
	return row == col ? 1 : 0;
}
void Mat::Print()
{
	int cnt = 0;
	for(int i = 1; i <= row; ++i)
	{
		for(int j = 1; j <= col; ++j)
		{
				std::cout << data[cnt++] << "    " ;
		}
		
		std::cout << std::endl;
	}
}

Mat& Mat::Add(Mat m)
{
	int r = m.GetRow();
	int c = m.GetColomn();
	if(r != row)
	{
		Error("Two matrix's row is not equal!");
		return *this;
	}

	if(c != col)
	{
		Error("Two matrix's colomn is not equal!");
		return *this;
	}

	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 1; i <= r; ++i)
	{
		for(int j = 1; j <= c; ++j)
		{
			data[cnt1++] += m.data[cnt2++];
		}
	}
}

Mat& Mat::Subtract(Mat m)
{
	int r = m.GetRow();
	int c = m.GetColomn();
	if(r != row)
	{
		Error("Two matrix's row is not equal!");
		return *this;
	}

	if(c != col)
	{
		Error("Two matrix's colomn is not equal!");
		return *this;
	}

	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 1; i <= r; ++i)
	{
		for(int j = 1; j <= c; ++j)
		{
			data[cnt1++] -= m.data[cnt2++];
		}
	}

}

Mat& Mat::Multiply(Mat m)
{
	int r = m.GetRow();
	int c = m.GetColomn();

	if(col != r)
	{
		Error("This two matrix can not Multiply!");
		return *this;
	}

	col = c;


}
