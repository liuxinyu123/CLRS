#ifndef _MAT_H_
#define _MAT_H_

#include <iostream>

template<typename T>
class Mat
{
		friend std::ostream& operator << (std::ostream &os, const Mat<T> &m);
		friend const Mat<T>& operator+ (const Mat<T> &m1, const Mat<T> &m2);
		friend const Mat<T>& operator- (const Mat<T> &m1, const Mat<T> &m2);
		friend const Mat<T>& operator* (const Mat<T> &m1, const Mat<T> &m2);
public:
		Mat (const int r, const int c, const T *arr)
			:_row (r), _col (c), _data (new T[_row * _col]) 
		{
			copyFrom (arr, _row * _col);
		}
		Mat (const Mat<T> &m);
		Mat<T>& operator= (const Mat<T> &m);

		int row () const
		{
			return _row;
		}
		int column () const
		{
			return _col;
		}

private:
		void copyFrom (const T *arr, int sz);
		bool check (const Mat<T> &m1, const Mat<T> &m2) const
		{
			return (m1._row == m2._row) && (m1._col == m2._col);
		}
private:
		int _row;
		int _col;
		T *_data;
};

#include "mat_impl.h"
#endif
