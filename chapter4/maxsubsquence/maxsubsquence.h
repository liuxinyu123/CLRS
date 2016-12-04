#ifndef _MAXSUBSQUENCE_H_
#define _MAXSUBSQUENCE_H_

typedef int index;

struct s
{
	index begin;
	index end;
	int sum;
};

typedef s *ps;

ps FinMaxCrossArry(int *arr,index lo,index mid,index hi);
ps FinMax(int *arr,index lo,index hi);

#endif
