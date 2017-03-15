#ifndef _MAXSUBSQUENCE_H_
#define _MAXSUBSQUENCE_H_

#include <utility>

std::pair<int, int> find_max_cross_subsquence (int *arr, int l, int m, int r, int &s);
std::pair<int, int> max_subsquence (int *arr, int l, int m, int &s);

#endif
