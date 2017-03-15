template<typename>
Mat<T>::Mat (const Mat<T> &m)
	:_row (m._row), _col (m._col), _data (new T[_row * _col])
{
	copyFrom (m._data, _row * _col);
}

template<typename>
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
