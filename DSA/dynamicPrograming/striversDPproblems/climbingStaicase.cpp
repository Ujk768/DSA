#include<iostream>
using namespace std;

/**
 * when to use dp
 * 1. count the total number of ways
 * 2. min /max output
 * 3.
 *
 * whenever concept of try all possible ways comes in we use dp
 *  or best way thats when we use recursion
 *
 *
 * find the number of ways to reach n steps if we can take only one or at max two steps
 *
 * 1 .try to represent the problem in terms of an index
 *
 * 2. do all possible stuff on that index according to the
 * problem statement
 *
 * 3. sum of all stuffs=> count all ways
 * min(of all stuffs)=> for minimum
 *
 *
 * 0 1 2 3 4 5 ........      N
 *
 * f(n)=> number of ways to reach 0-n
 *
 * f(ind){
 *
 * //from an index we can jump one or jump two
 *
 its ind-1 and ind-2 coz we use top down approach
 *  if(ind==0) return 1;
 * if(ind==1) return 0;
 *  return  f(ind-1)+f(ind-2)
 *
 * }
 *
 * this is similar to fibonacci number code
 *
 *
 *
 */
