#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * given n=> rod length
 *                 1 2 3 4 5 
 * price array[]=>[2 5 7 8 10]
 *  
 * for every piece of length 1 the price in the market is 2 => total price you get is 10
 * 
 * 1 2 2 => 2 5 5 => 12 
 * 
 * 1 4 => 10
 * 
 * max cost you can get is 12
 * 
 * 
 * collect rod lengths to make n and maximize=> now becomes similar to knapsack problems
 * 
 * 
 * try to pick lengths in all possible ways  and sum them up to make the given n 
 * 
 * hence we use recursion
 * 
 * write in terms of index and len
 * explore all possibilities=> nottalke and take
 * find max price
 * 
 *      f(4,N)=> till index 4 what is the max price you obtain to form rod length n
 * 
 *          f(ind,N){
 *                  if(ind==0){
 *                      return n*price[0];   
 *                  }
 *                int nottake=0+f(ind-1,N);
 *                  int take=INT_Min;
 *                  rodlength=ind+1;
 * 
 *                  if(rodlenth<=n) take=price[ind] +f(ind,n-rodlength)
 *                  return max(nottake,take );
 *          } 
 * 
 * t.c: exponential s.c:O(target)
 * 
 * memoization t.c:O(n*n) s.c:O(n*n)+O(target)
 * 
 * 
 * 
 */

int frecur(int ind,int N,vector<int>&price){
    if(ind==0){
        return N*price[0];
    }
    int nottake=frecur(ind-1,N,price);
    int take=INT_MIN;
    int rodlen=ind+1;
    if(rodlen<=N) take=price[ind]+frecur(ind,N-rodlen,price);

    return max(nottake,take);
}

int fdp(int ind,int N,vector<int>&price, vector<vector<int>>& dp){
    if(ind==0){
        return N*price[0];
    }
    if(dp[ind][N]!=-1) return dp[ind][N];
    int nottake=fdp(ind-1,N,price,dp);
    int take=INT_MIN;
    int rodlen=ind+1;
    if(rodlen<=N) take=price[ind]+fdp(ind,N-rodlen,price,dp);

    return dp[ind][N]=max(nottake,take);
}
int cutRodTabulation(vector<int>&price,int n){
    
    vector<vector<int>> dp(n,vector<int>(n+1,0));

    for(int N=0;N<=n;N++){
        dp[0][N]=N*price[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
             int nottake=dp[ind-1][N];
            int take=INT_MIN;
            int rodlen=ind+1;
            if(rodlen<=N) take=price[ind]+dp[ind][N-rodlen];

            dp[ind][N]=max(nottake,take);
        }
    }
    return dp[n-1][n];

}

int cutRod(vector<int>&price,int n){
    
    vector<vector<int>> dp(n,vector<int>(n+1,-1));

}