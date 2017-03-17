#ifndef _MAT_IMPL_H_
#define _MAT_IMPL_H_

#include <iostream>
#include <cstdio>

template<typename T>
Mat<T>::Mat (const Mat<T> &m)
	:_row (m._row), _col (m._col), _data (new T[_row * _col])
{
	copyFrom (m._data, _row * _col);
}

template<typename T>
void Mat<T>::copyFrom (const T *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		_data[i] = arr[i];
	}	
}

template<typename T>
Mat<T>& Mat<T>::operator= (const Mat<T> &m)
{
	
}

template<typename T>
std::ostream& operator << (std::ostream &os, const Mat<T> &m)
{
	int idx = 0;
	for (int i = 0; i < m._row; ++i)
	{
		for (int j = 0; j < m._col; ++j)
		{
			std::cout << m._data[idx++] << " ";
		}

		std::cout << std::endl;
	}

	return os;

}

template<typename T>
const Mat<T>& operator+ (const Mat<T> &m1, const Mat<T> &m2)
{
	if (!check (m1, m2))
		std::perror ("The row or column of this two mat is not equal\n");
	
	Mat<T> retMat (m1);
	
	return retMat.operator+= (m2);
}

template<typename T>
const Mat<T>& operator- (const Mat<T> &m1, const Mat<T> &m2)
{
	if (!check (m1, m2))
		std::perror ("The row or column of this two mat is not equal\n");

	Mat<T> retMat (m1);
	
	return retMat.operator-= (m2);

}

template<typename T>
const Mat<T>& operator* (const Mat<T> &m1, const Mat<T> &m2)
{


}

template<typename T>
void Mat<T>::print () const
{
	int idx = 0;
	for (int i = 0; i < _row; ++i)
	{
		for (int j = 0; j < _col; ++j)
		{
			std::cout << _data[idx++] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

template<typename T>
Mat<T>& Mat<T>::operator+= (const Mat<T> &m)
{
	if (!check (*this, m))
		std::perror ("The row or column of this two mat is not equal\n");
	for (int i = 0; i < _row * _col; ++i)
		_data[i] += m._data[i];

	return *this;
}

template<typename T>
Mat<T>& Mat<T>::operator-= (const Mat<T> &m)
{
	if (!check (*this, m))
		std::perror ("The row or column of this two mat is not equal\n");
	for (int i = 0; i < _row * _col; ++i)
		_data[i] -= m._data[i];

	return *this;

}

#endif
