#include "maxsubsquence.h"

std::pair<int, int> find_max_cross_subsquence (int *arr, int l, int m, int r, int &s)
{
	int lSum = arr[m];
	int sum = 0;
	int left_index = m;
	for (int i = m; i >= l; --i)
	{
		sum += arr[i];

		if (sum > lSum)
		{
			lSum = sum;
			left_index = i;
		}
	}
	
	sum = 0;
	int rSum = arr[m + 1];
	int right_index = m + 1;
	for (int i = m + 1; i <= r; ++i)
	{
		sum += arr[i];
		
		if (sum > rSum)
		{
			rSum = sum;
			right_index = i;
		}	
	}

	s = lSum + rSum;

	return std::make_pair (left_index, right_index);
}

std::pair<int, int> max_subsquence (int *arr, int l, int r, int &s)
{
	if (l == r)
	{
		s = arr[l];
		return std::make_pair (l,r);
	}
	else
	{
		int m = (l + r) / 2;
		int lMax = 0;
		int rMax = 0;
		int mMax = 0;
		std::pair<int, int> lp = max_subsquence (arr, l, m, lMax);
		std::pair<int, int> rp = max_subsquence (arr, m + 1, r, rMax);
		std::pair<int, int> mp = find_max_cross_subsquence (arr, l, m, r, mMax);

		if (lMax >= rMax && lMax >= mMax)
		{
			s = lMax;
			return lp;
		}
		else if (rMax >= lMax && rMax >= mMax)
		{
			s = rMax;
			return rp;
		}
		else
		{
			s = mMax;		
			return mp;
		}

	}
}

