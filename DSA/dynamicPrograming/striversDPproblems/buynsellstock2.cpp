#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * @brief 
 * prices=[7,1,5,3,6,4]
 * 
 * prices given on each day.
 * we can buy as many times as we want and sell as many times as we want
 * 
 * once you buy before performing the next buy you have to sell
 * 
 *  try all ways and find the best possible ans=> recursion
 * 
 *  1.represent in terms of index
 * 
 * -on any index we have to know wheter i have 
 * bought anything previously or not
 * 
 * hence we make use of another variable buy
 * 
 * 2. explore all possibilities on that index
 * 
 * 3. take the max of all profits made
 * 
 * 4. base case
 * 
 * 
 * 1=> buy  0=> cant buy
 * 
 * profit= -prices[i]+ cal at which its sold
 * 
 * f(ind,buy){
 * 
 *  if(ind==n){
 *      //no profit to be made
 *      return 0;
 *  }
 *  
 *  if(buy){
 * // 2 options either buy or dont buy
 * // cant buy on nxt hence we pass 0 and move forward
 * //we havent bought so we move forward but buy is still at 1 as we can buy in the future
 *     
 *   profit=max{-prices[ind]+f(ind+1,0),f(ind+1,1)}
 *  }
 *  else{
 * //selling
 *      2 options either sell or dont sell
 *      if we have sold we have liberty to buy at the next index
 *      else if we dont sell then we have to keep buy as 0
 *      profit=max{prices[ind]+f(ind+1,1),f(ind+1,0)}
 *  
 *  }
 *  
 * 
 * }
 * 
 * 
 * t.c: 2^n  s.c: O(n)
 * 
 *  ind=> n
 * buy=>0/1 
 * dp[n][2]
 * 
 * 
 */


long frecur(int ind,int buy,long * values, int n){
        if(ind==n) return 0;

        long profit=0;
        if(buy){
            profit=max(-values[ind]+frecur(ind+1,0,values,n),frecur(ind+1,1,values,n));
        }else{
            profit=max(values[ind]+frecur(ind+1,1,values,n),frecur(ind+1,0,values,n));
        }
       return profit;
} 

long fdp(int ind,int buy,long * values, int n, vector<vector<long>> & dp){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        long profit=0;
        if(buy){
            profit=max(-values[ind]+frecur(ind+1,0,values,n),frecur(ind+1,1,values,n));
        }else{
            profit=max(values[ind]+frecur(ind+1,1,values,n),frecur(ind+1,0,values,n));
        }
       return dp[ind][buy]=profit;
} 
//t.c:O(n*2) s.c:O(n*2)+O(n)

long getMaximumProfitTabulation(long* values,int n){

    vector<vector<long>>dp(n+1,vector<long>(2,0));
    dp[n][0]=0;
    for(int ind= n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
             long profit=0;
        if(buy){
            profit=max(-values[ind]+dp[ind+1][0],dp[ind+1][1]);
        }else{
            profit=max(values[ind]+dp[ind+1][1],dp[ind+1][0]);
        }
       dp[ind][buy]=profit;
        }
        return dp[0][1];
    }
}

long getMaximumProfit(long* values,int n){

    vector<vector<long>>dp(n,vector<long>(2,-1));
    return fdp(0,1,values,n,dp);
}