#ifndef _DOUBLELIST_H_
#define _DOUBLELIST_H_


template<typename T>
struct DoubleListNode
{
	T key;
	DoubleListNode<T> *prev;
	DoubleListNode<T> *next;	

	DoubleListNode () = default;
	DoubleListNode (const T &e, DoubleListNode *p = nullptr, DoubleListNode *n = nullptr)
		:key (e), prev (p), next (n) {}
	~DoubleListNode ()
	{
		
	}

};

template<typename T>
class DoubleList
{

public:
		DoubleList ()
			:head (new DoubleListNode<T>), tail (new DoubleListNode<T>)
		{
			head -> prev = nullptr;
			head -> next = tail;
			tail -> prev = head;
			tail -> next = nullptr;
		}
		~DoubleList ()
		{
			delete head;
			delete tail;
		}
		void insert (const T &e)
		{
			auto p = new DoubleListNode<T> (e);
			p -> next = head -> next;
			head -> next -> prev = p;
			head -> next = p;
			p -> prev = head;
		}
		DoubleListNode<T>* search (const T &e) const
		{
			auto p = head -> next;
			for (; p -> next && p -> key != e; p = p -> next);

			if (p -> key == e)
				return p;
			return nullptr;
		}
		bool isEmpty () const
		{
			return head -> next == tail;
		}
		void remove (DoubleListNode<T> *p)
		{
			if (!p)
				return;
			p -> prev -> next = p -> next;
			p -> next -> prev = p -> prev;
			delete p;
		}
		
		void traversal () const
		{
			for (auto p = head -> next; p -> next; p = p -> next)
				std::cout << p -> key << " ";
			std::cout << std::endl;
		}
private:
		DoubleListNode<T> *head;
		DoubleListNode<T> *tail;

};

#endif
