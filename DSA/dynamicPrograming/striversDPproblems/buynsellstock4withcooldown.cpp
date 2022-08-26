#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * buy and sell stock but with a cool down
 * 
 * cooldown means you cant buy right after sell 
 * 
 * 
 * prices[]={4,9,0,4,10}
 * 
 *  code for buy and sell stock 2
 * 
 * 
 * f(ind,buy){
 * 
 *  if(ind==n) return 0;
 * 
 * if(buy){
 *  return max{-prices[ind]+f(ind+1,0),f(ind+1,1)}
 * }else{
 *  return max(prices[ind]+f(ind+1,1),f(ind+1,0))
 * }
 * 
 * }
 * 
 * since we cant buy immeadiately after selling insead of buying 
 * at ind+1 we can start buying at ind+2
 * 
 * 
 */


int frec(int ind,int buy,int n,vector<int>& prices){
    if(ind>=n) return 0;
    int profit=0;
    if(buy){
        profit=max(-prices[ind]+frec(ind+1,0,n,prices),frec(ind+1,1,n,prices));
    }else{
        profit=max(prices[ind]+frec(ind+2,1,n,prices),frec(ind+1,0,n,prices));
    }
    return profit;
}

int fdp(int ind,int buy,int n,vector<int>& prices,vector<vector<int>> & dp){
    if(ind>=n) return 0;
    
    if(dp[buy][ind]!=-1) return dp[ind][buy];
    if(buy){
         return dp[ind][buy]=max(-prices[ind]+frec(ind+1,0,n,prices),frec(ind+1,1,n,prices));
    }else{
         return dp[ind][buy]=max(prices[ind]+frec(ind+2,1,n,prices),frec(ind+1,0,n,prices));
    }
   
}
int maxProfitTabulation(vector<int>&prices,int n){
    vector<vector<int>>dp(n+2,vector<int>(2,0));
    
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++ ){
             if(buy){
          dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
             }else{
         dp[ind][buy]=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
             }
        }
    }

}

int maxProfit(vector<int>&prices,int n){
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return fdp(0,1,prices.size(),prices,dp);
}