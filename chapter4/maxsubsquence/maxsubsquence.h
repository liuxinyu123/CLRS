#ifndef _MAXSUBSQUENCE_H_
#define _MAXSUBSQUENCE_H_

typedef int Index;

struct s
{
	Index begin;
	Index end;
	int sum;
};

typedef s *ps;

ps FindMaxCrossArry(int *arr,Index lo,Index mid,Index hi);
ps FindMax(int *arr,Index lo,Index hi);

#endif
