#include <iostream>
#include <string>
#include "stack.h"

void test_stack ();

using std::cout;
using std::endl;
using std::string;

int main (int argc, char *argv[])
{
	test_stack ();

	return 0;


}

void test_stack ()
{
	Stack<int> intStack (100);
	
	for (int i = 0; i < 100; ++i)
		intStack.push_back (i);
	
	for (int i = 0; i < 100; ++i)
	{
		cout << intStack.top () << " ";
		intStack.pop_back ();
	}
	cout << endl;

	Stack<string> strStack;
	cout << strStack.capacity () << endl;
	cout << strStack.size () << endl;
	strStack.push_back ("hello");
	strStack.push_back ("world");
	
	cout << strStack.top () << endl;

}
