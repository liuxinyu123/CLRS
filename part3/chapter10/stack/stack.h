#ifndef _SATCK_H_
#define _SATCK_H_

#include <stdexcept>
#include <iostream>

const int DefaultSize = 50;
template<typename T>
class Stack
{
public:
		Stack (int c = DefaultSize)
			:cap (c), bottom (new T[cap]), first_empty (bottom)
	   	{
		}
		bool isEmpty () const
		{
			return size () == 0; 
		}
		int size () const
		{
			return first_empty - bottom;
		}
		T top () const
		{
			if (isEmpty ())
				throw std::out_of_range ("overflow");
			auto top = first_empty - 1;
			return *top;
		}
		void push_back (const T &e)
		{
			if (isFull ())
				throw std::out_of_range ("overflow");
			*first_empty++ = e;			
		}
		int pop_back ()
		{
			if (isEmpty ())
				throw std::out_of_range ("underflow");
			return *(--first_empty);
		}
		int capacity () const
		{
			return cap;
		}
		//void print () const
		//{
			//for (int i = 0, T *be = bottom; i < size (); ++i)
				//std::cout << *be++ << " ";
			//std::cout << std::endl;
		//}
private:
		int cap;
		T *bottom;
		T *first_empty;
private:
		bool isFull () const
		{
			return size () == cap;
		}
};

#endif
