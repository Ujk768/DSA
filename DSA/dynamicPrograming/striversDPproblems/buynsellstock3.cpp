#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * @brief
 *
 * prices=[3,3,5,0,0,3,1,4]
 *
 * at max 2 transactions
 *
 * 3-0=3 4-1=3 max profit=6
 *
 * cap= max number of transactions you can do
 *
 * a transaction is only complete once the stock has been sold
 * f(ind,buy,cap)
 *
 */

int frecur(int ind,int buy,int cap,int n,vector<int>& prices){
    if(cap==0) return 0;
    if(ind==n) return 0;
    int profit=0;
    if(buy){
        profit= max(-prices[ind]+frecur(ind+1,0,cap,n,prices),frecur(ind+1,1,cap,n,prices));
    }else{
        profit= max(prices[ind]+frecur(ind+1,1,cap-1,n,prices),frecur(ind+1,0,cap,n,prices));
    }
    return profit;
}

int fdp(int ind,int buy,int cap,int n,vector<int>& prices,vector<vector<vector<int>>>& dp){
    if(cap==0) return 0;
    if(ind==n) return 0;
    if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
    int profit=0;
    if(buy){
        profit= max(-prices[ind]+fdp(ind+1,0,cap,n,prices,dp),fdp(ind+1,1,cap,n,prices,dp));
    }else{
        profit= max(prices[ind]+fdp(ind+1,1,cap-1,n,prices,dp),fdp(ind+1,0,cap,n,prices,dp));
    }
    return dp[ind][buy][cap]= profit;
}

//in recursion we fill from 0-> n-1 hence in tabulation we fil from n-1 to 0
int maxprofitTabulation(vector<int>&prices,int n){
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                int profit=0;
                if(buy){
        profit= max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
    }else{
        profit= max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
    }
    dp[ind][buy][cap]= profit;
            }
        }
    }
    return dp[0][1][2];
}

int maxprofit(vector<int>&prices,int n){
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

}
