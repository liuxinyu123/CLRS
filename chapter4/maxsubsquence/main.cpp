#include <iostream>
#include <cstdlib>
#include <ctime>
#include "maxsubsquence.h"
#include "printarray.h"

int main(int argc,char **argv)
{
	const int Len = 100000;
	int *a = new int[Len];
	srand(time(0));

	for(int i = 0; i < Len; ++i)
		a[i] = rand()%1000;
	
	for(int i = 0; i < Len - 1; ++i)
		a[i] -= a[i + 1];

	clock_t start1 = clock();
	int sum1 = FindMax1(a,Len);
	clock_t end1 = clock();

	clock_t start2 = clock();
	int sum2 = FindMax(a,0,Len - 1);
	clock_t end2 = clock();
	
	clock_t start3 = clock();
	int sum3 = FindMax2(a,Len);
	clock_t end3 = clock();

	std::cout << "The array is : " << std::endl;
	PrintArray(a,Len);

	std::cout << "The maxsubsquence's sum is " << sum1 << std::endl;
	std::cout << "Time elapse: " << static_cast<double>(end1 - start1) / CLOCKS_PER_SEC << std::endl;  

	std::cout << "The maxsubsquence's sum is " << sum2 << std::endl;
	std::cout << "Time elapse: " << static_cast<double>(end2 - start2) / CLOCKS_PER_SEC << std::endl;  
	
	std::cout << "The maxsubsquence's sum is " << sum3 << std::endl;
	std::cout << "Time elapse: " << static_cast<double>(end3 - start3) / CLOCKS_PER_SEC << std::endl;  

	return 0;
}
