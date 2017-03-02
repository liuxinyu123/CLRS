#include <iostream>
#include "stack.h"

void test_stack ();

using std::cout;
using std::endl;

int main (int argc, char *argv[])
{
	test_stack ();

	return 0;


}

void test_stack ()
{
	Stack<int> intStack (100);
	
	intStack.push_back (23);
	intStack.push_back (44);

	cout << intStack.pop_back () << " " << intStack.pop_back () << endl;

}
