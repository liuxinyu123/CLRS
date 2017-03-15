#include <iostream>

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
std::ostream& operator<< (std::ostream &os, const Mat<T> &m)
{
	int idx = 0;
	for (int i = 0; i < m._row; ++i)
	{
		for (int j = 0; j < m._col; ++j)
		{
			if (((i + 1) * (j + 1)) % m._col == 0)
				std::cout << std::endl;
			std::cout << m._data[idx++] << " ";
		}
	}

}
