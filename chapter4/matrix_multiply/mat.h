#ifndef _MAT_H_
#define _MAT_H_

#include <ostream>

template<typename T>
class Mat
{

		friend std::ostream& operator<< (std::ostream &os, const Mat<T> &m);
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
private:
		int _row;
		int _col;
		T *_data;
};

#include "mat_impl.h"
#endif
