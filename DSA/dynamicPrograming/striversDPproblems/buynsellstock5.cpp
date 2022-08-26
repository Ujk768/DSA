#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * a transaction fee is cost at the end of each buy and sell cycle
 * prices[]={1,3,2,8,4,9}
 * 
 * fee=2
 * 8-1=7
 * 5-2=3
 * (7-2)+(5-2)=8
 * 
 * only change to buy and seel stock 2 code is subtract fee 
 * when sold(end of transaction) from the profit obtained 
 */