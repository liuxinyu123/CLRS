#include <iostream>
#include <string>
#include "queue.h"

using std::cout;
using std::endl;
using std::string;

void test_queue ();

int main (int argc, char *argv[])
{
	test_queue ();

	return 0;

}

void test_queue ()
{
	Queue<int> intQueue;
	cout << intQueue.capacity () << endl;
	cout << intQueue.size () << endl;

	for (int i = 0; i < 40; ++i)
		intQueue.enqueue (i);
	cout << intQueue.front () << " " << intQueue.back () << endl;
	for (int i = 0; i < 40; ++i)
		cout << intQueue.dequeue () << " ";
	cout << endl;

	Queue<string> strQueue (4);
	strQueue.enqueue ("hello");
	strQueue.enqueue ("world");
	strQueue.enqueue ("ok");
	
	cout << strQueue.dequeue () << endl;
	strQueue.enqueue ("hi");
	cout << strQueue.dequeue () << endl;
	strQueue.enqueue ("sorry");
	while (!strQueue.isEmpty ())
		cout << strQueue.dequeue () << " ";
	cout << endl;
}
