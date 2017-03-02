#include <iostream>
#include <string>
#include "doublelist.h"

using std::cout;
using std::endl;
using std::string;

void test_doblelist ();

int main (int argc, char *argv[])
{
	test_doblelist ();
	
	return 0;
}

void test_doblelist ()
{
	DoubleList<int> intList;
	for (int i = 0; i < 10; ++i)
		intList.insert (i);
	intList.traversal ();
	intList.remove (intList.search (5));
	intList.remove (intList.search (88));
	intList.traversal ();

	DoubleList<string> strList;
	strList.insert ("hello");
	strList.insert ("world");
	strList.insert ("fuck");
	strList.insert ("you");

	strList.traversal ();
	strList.remove (strList.search ("fuck"));
	strList.traversal ();


}
