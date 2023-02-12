#ifndef COMMON_H
#define COMMON_H

#include <vector>

// get the intermediate values of two numbers
// d = f(i)
//
// @param i0 first i in equation
// @param d0 first d in equation
// @param i1 second i in equation
// @param d1 second d in equation
std::vector<int> interpolate(int i0, float d0, int i1, float d1);

#endif  // COMMON_H
