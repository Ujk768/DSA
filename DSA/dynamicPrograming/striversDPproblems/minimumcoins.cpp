#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * you are given an array which contains coin denominations and you have to select minimum number of coins to get to a particluar target
 * arr[]=>{1    2   3}  target=7
 * 
 * (3,3,1)=> this will be ans as it takes min number of coins
 * (2,2,2,1)
 * 
 * 
 * greedy => pick up the biggest biggest denomination and keep diving till possible then find the reamining value from arr
 * 
 * where does greedy fails
 * 
 * {9 6 5 1} target=11
 * 11/9=1
 * 2/1=2
 * 3 coins needed but we can get 11 from only two coind 6 and 5 hence greedy fails
 * 
 * greedy wont work hence 
 * we try to find all possible combinations and take onw with minum coins
 * 
 * 1. express interms of index and target
 * 2. explore all possibliltes
 * 3. find min number of coins 
 * 
 * f(n-1,target)=> returns minimum number of coins required to form target from 0->n-1
 * 
 * we have an infinite supply of the coins 
 * 
 * infinite supply // multiple uses => always stand at the same index when we consider take and just alter the target
 * 
 *  f(ind,T){=> return number of coins needed to form the target
 *        
 *      if(ind==0){
 *          if(target%arr[ind]==0) return target/arr[ind];
 *          else return 1e9;
 *      }
 * 
 *      int nottake=0+f(ind-1,T);
 *      int take=INT_MAX;
 *      if(arr[ind]<=target) take=  1+f(ind,T-arr[ind]);
 *      return min(take,nottake);
 * }
 * 
 * 
 * t.c: >>O(2^n)=> exponential s.c:O(target) 
 * 
 * 
 * //memoization 
 * changing parameters are n and target
 * 
 * dp[n][target+1]
 * 
 * 
 *  *  f(ind,T){=> return number of coins needed to form the target
 *        
 *      if(ind==0){
 *          if(target%arr[ind]==0) return target/arr[ind];
 *          else return 1e9;
 *      }
 *      if(dp[ind][target]!=-1) return dp[ind][target]
 *      int nottake=0+f(ind-1,T);
 *      int take=INT_MAX;
 *      if(arr[ind]<=target) take=  1+f(ind,T-arr[ind]);
 *      return dp[ind][target] min(take,nottake);
 * }
 * 
 * t.c:O(n*target)  s.c:o(n)+O(n*target)
 * 
 * 
 * tabulation 
 * 1. base case
 * 2. look at what parameters are changing 
 * 3. copy the recurence
 * 
 * 
 */

int fRecursive(int ind, int T, vector<int>&nums){
    if(ind==0){
        if(T%nums[0]==0) return T/nums[0];
        else return 1e9;
    }
    int notTake=fRecursive(ind-1,T,nums);
    int take=1e9;
    if(nums[ind]<=T) take=fRecursive(ind,T-nums[ind],nums);

    return min(take,notTake);

}
int fDp(int ind, int T, vector<int>&nums,vector<vector<int>> & dp){
    if(ind==0){
        if(T%nums[0]==0) return T/nums[0];
        else return 1e9;
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
    int notTake=fDp(ind-1,T,nums,dp);
    int take=1e9;
    if(nums[ind]<=T) take=fDp(ind,T-nums[ind],nums,dp);

    return dp[ind][T]= min(take,notTake);

}
//memoization

int minElements(vector<int>& nums, int target){
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(target+1 ,-1));
    int ans=fDp(n-1,target,nums,dp);
    if(ans>=1e9) return -1;
    else return ans;
}

//tabulation

int minElements(vector<int>& nums, int target){
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(target+1 ,0));
    for(int T=0;T<=target;T++){
        if(T%nums[0]==0) dp[0][T]= T/nums[0];
        else dp[0][T]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=target;T++){
             int notTake=dp[ind-1][T];
            int take=1e9;
            if(nums[ind]<=T) take=dp[ind][T-nums[ind]];

         dp[ind][T]= min(take,notTake);
        }
    }
   int ans=dp[n-1][target];
   if(ans>=1e9) return -1;
   else return ans;
}

//space optimized

int minElementsSpaceOptimized(vector<int>& nums, int target){
    int n=nums.size();

    vector<int>prev(target+1,0),curr(target+1,0);
    for(int T=0;T<=target;T++){
        if(T%nums[0]==0) prev[T]= T/nums[0];
        else prev[T]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=target;T++){
             int notTake=prev[T];
            int take=1e9;
            if(nums[ind]<=T) take=curr[T-nums[ind]];

         curr[T]= min(take,notTake);
        }
        prev=curr;
    }
   int ans=prev[target];
   if(ans>=1e9) return -1;
   else return ans;
}