#include<stdio.h>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * arr: [1 2 3 1]
 * target 3 
 * assigns signs to each element in the array to get the target 
 *    - + + - => -1+2+3-1=>3
 * 
 * how many ways can you assign signs such that you can get the given target
 * +-++=> 3
 * 
 * 
 * use the method used in count subset 
 * 
 * just use the exaxt same code as s1-s2=D and it will solve it
 * 
 */