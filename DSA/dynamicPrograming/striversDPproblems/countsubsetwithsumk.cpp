#include<iostream>
#include<vector>
using namespace std;
/**
 * @brief
 *
 * to write recursive code
 * 1. express in form of index
 * 2. explore all possiblities
 * 3. sum of all the posssiblilitesand return
 *
 * f(3,3) how many subsequences from 0-3 have the sum 3
 *
 *                  f(ind,s){
 *                  if(sum==0) return 1;
 *                  if(ind==0){
 *                      return (ar[ind]==sum) ;
 *
 *                  }
 *                  notpick=f(ind-1,s);
 *                  pick=0;
 *                  if(ar[ind]<=s) pick=f(ind-1,s-ar[ind]);
 *                  return pick+notpick;
 *              }
 *
 * t.c: O(2^n ) s.c: O(n)
 *
 *
 * memoization => top down approach
 *
 * ind,sum
 * ind-> 0 to n-1 hence n size needed
 * sum=sum+1
 *
 * dp[n][sum+1];
 *
 * t.c: O(n*sum) s.c: O(n*sum)+O(n)
 *
 * tabulation=> botom up approach
 * 1. base case
 * 2. look at changing parameters and write nested loops
 * 3. copy the recursion
 *
 */



int countsubsetSumRecursive(int ind, int sum, vector<int> arr){
  if(sum==0) return 1;
  if(ind==0){
    return (sum==arr[ind]);
  }
  int pick=0;
  if(arr[ind]<=sum) pick=countsubsetSumRecursive(ind-1,sum-arr[ind],arr);
  int notpick=countsubsetSumRecursive(ind-1,sum,arr);

  return pick+notpick;
}



int countsubsetSumDP(int ind, int sum, vector<int> arr,vector<vector<int>>& dp){
  if(sum==0) return 1;
  if(ind==0){
    return (sum==arr[ind]);
  }
  if(dp[ind][sum]==-1) return dp[ind][sum];
  int pick=0;
  if(arr[ind]<=sum) pick=countsubsetSumDP(ind-1,sum-arr[ind],arr,dp);
  int notpick=countsubsetSumDP(ind-1,sum,arr,dp);
  return dp[ind][sum]= pick+notpick;
}

int countSubsetSumTabulation(vector<int>arr,int target){
  int n=arr.size();
  vector<vector<int>>dp(n,vector<int>(target+1,0));
  for(int ind=0;ind<n;ind++) dp[ind][0]=1;
  if(arr[0]<=target) dp[0][arr[0]]=1;
  for(int ind=1;ind<n;ind++){
    for(int j=0;j<=target;j++){
      int pick=0;
      if(arr[ind]<=target) pick=dp[ind-1][target-arr[ind]];
      int notpick=dp[ind-1][target];
      dp[ind][target]=pick+notpick;
    }
  }
return dp[n-1][target];
}


int countSubsetSumTabulationSpaceOptimized(vector<int>arr,int target){
  int n=arr.size();
  vector<int>prev(target+1,0),curr(target+1);
  prev[0]=curr[0]=1;
  if(arr[0]<=target) prev[arr[0]]=1;
  for(int ind=1;ind<n;ind++){
    for(int j=0;j<=target;j++){
      int pick=0;
      if(arr[ind]<=target) pick=prev[target-arr[ind]];
      int notpick=prev[target];
      curr[target]=pick+notpick;
    }
    prev=curr;
  }
return prev[target];
}


int countSubsetSum(vector<int>arr,int target){
  int n=arr.size();
  vector<vector<int>>dp(n,vector<int>(target+1,-1));
  return countsubsetSumDP(n-1,target,arr,dp);
}



/**
if we are told to that 0s will be present in the array then we alter the base cases

if(ind==0){
//dont pick the sum or pick the sum taget will be reached
  if(sum==0 && num[0]==0) return 2;
  if(sum==0 || num[0]==sum) return 1;
  return 0;

}


{0 0 1}
                 f(2,1)
            f(1,1)   f(1,0)=> returns 1 here do the last couple of 0s are not considered

     hence we need to go deeper

     we need to find number of ways to form that subcequence

     if sum=0 and ar[ind]==0 then two ways of taking it into the subsequence

      1. take the 0 
      2. dont take the 0 use null set

**/
