#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdexcept>

const int DefaultCapacity = 50;

template<typename T>
class Queue
{

public:
		Queue (int c = DefaultCapacity)
			:cap (c), array (new T[cap]), head (0), tail (0) {}
		~Queue ()
		{
			delete [] array;
		}
		void enqueue (const T &e)
		{
			if (isFull ())
				throw std::out_of_range ("overflow");
			array[tail] = e;
			++tail;
			tail %= cap;
		}	
		T dequeue ()
		{
			if (isEmpty ())
				throw std::out_of_range ("underflow");
			T ret = array[head];
			++head;
			head %= cap;
			return ret;
		}
		T front () const
		{
			if (isEmpty ())
				throw std::out_of_range ("underflow");
			return array[head];
		}
		T back () const
		{
			if (isEmpty ())
				throw std::out_of_range ("underflow");
			return array[tail - 1];
		}
		int capacity () const 
		{
			return cap;
		}
		int size () const
		{
			return tail - head;
		}
		bool isEmpty () const
		{
			return head == tail;
		}
		bool isFull () const
		{
			return (head != 0) && (head + 1 == tail);
		}
private:
		int cap;
		T *array;
		int head;
		int tail;
};

#endif
