#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * in an unbounded knapsack we have infinite supply of  a particular item in the array
 * 
 *  wt=[2 4 6]
 *  val=[5 11 13]
 *  weight=10
*
*   wt->6 : 13
    wt->4: 11
* ans = 24

*   wt->6:13
    wt->2*2:5*2
 ans=23

    wt->4 *2=22
    wt->2=5
    ans=27  => maximim possible value hence return this


        recursion to find all possible ways to solve this
        1. represent in terms of index,weight
        2. explore all possibilities
        3. return max possiility


        f(ind,W){
            if(ind==0){
              return (W/arr[0])*val[0];
            }

            nottake=f(ind-1,W);
            int take=INT_MIN;
            if(w[ind]<=W) take=val[ind]+f(ind,W-wt[ind]);
            return max(take,nottake);
        }

        t.c: exponential s.c: O(W)

 */

int fRecur(int ind,int W,vector<int>&value, vector<int>&wt){

    if(ind==0){
        return (int)(W/wt[ind])*value[ind];
    }

    int nottpick=0+fRecur(ind-1,W,value,wt);
    int pick=INT_MIN;
    if(wt[ind]<=W) pick=value[ind]+fRecur(ind,W-wt[ind],value,wt);
    return max(pick,nottpick);
}
//memoization topdown 

int fDp(int ind,int W,vector<int>&value, vector<int>&wt, vector<vector<int>>& dp){

    if(ind==0){
        return (int)(W/wt[ind])*value[ind];
    }
    if(dp[ind][W]!=-1) return dp[ind][W];
    int nottpick=0+fRecur(ind-1,W,value,wt);
    int pick=INT_MIN;
    if(wt[ind]<=W) pick=value[ind]+fRecur(ind,W-wt[ind],value,wt);
    return dp[ind][W]=max(pick,nottpick);
}


int unboundedknapsacktabulation(int n, int w, vector<int>& value,vector<int>&wt){

    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int W=0;W<=w;W++) dp[0][W]=(int)(W/wt[0])*value[0];

    for(int i=1;i<n;i++){
        for(int W=0;W<=w;W++){
               int nottpick=0+dp[i-1][W];
                int pick=INT_MIN;
                if(wt[i]<=W) pick=value[i]+dp[i][W-wt[i]];
                dp[i][W]=max(pick,nottpick);
            }
        }
         return dp[n-1][w];
    }
   
int unboundedknapsackSpaceOptimized(int n, int w, vector<int>& value,vector<int>&wt){
        vector<int>prev(w+1,0),curr(w+1,0);
    for(int W=0;W<=w;W++) prev[W]=(int)(W/wt[0])*value[0];

    for(int i=1;i<n;i++){
        for(int W=0;W<=w;W++){
               int nottpick=0+prev[W];
                int pick=INT_MIN;
                if(wt[i]<=W) pick=value[i]+curr[W-wt[i]];
                curr[W]=max(pick,nottpick);
            }
            prev=curr;
        }
         return prev[w];
    }


int unboundedknapsack(int n, int w, vector<int>& value,vector<int>&wt){

    vector<vector<int>>dp(n,vector<int>(w+1,-1));

}