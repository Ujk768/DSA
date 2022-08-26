#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * @brief 
 * 
 * arr: [7,1,5,3,6,4]
 * 
 * buy and sell only once 
 * 
 * buy: 1 sell: 6 diff=5 hence this is the ans
 * 
 * for a stock you will buy when on the left its minimal
 * 
 * if you are selling on ith day you buy on minimum price from 0->i-1
 * 
 * try for everyday
 * 
 * keep track for minimal on the left
 * 
 * 
 * mini=arr[0],profit=0;
 * 
 * for(int i=1;i<n;i++){
 *     cost=a[i]-mini;
 *      profit=max(profit,cost);
 *      mini=min(mini,arr[i]);
 * }
 * 
 * 
 * 
 */


 int maximumProfit(vector<int>&prices){
    int mini=prices[0];
    int maxProfit=0;
    int n=prices.size();
    for(int i=0;i<n;i++){
        int cost=prices[i]-mini;
        maxProfit=max(maxProfit,cost);
        mini=min(mini,cost);
    }
    return maxProfit;
 }