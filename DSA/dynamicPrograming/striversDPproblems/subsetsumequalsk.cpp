#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 *  [1,3,2]  => [1,2]
 *  [3,2] 
 * [2,3 ] is not a subsequence as it doesnt follow the order
 * 
 * you are given an array with positive intergers and you have to find if there exists a subset/subarray with sum=k
 * 
 * 
 * generate all the subsequences and check if there exists a subsequence with sum=k
 * 
 * 1.to solve dp on subsequences we will have a index and a target
 * 2. explore possiblities on that index    => pick the arr index or dont pick the arr index    
 * 3. return true or false
 * 
 * f(n-1,target)=> in the entire array till index n-1 does there exist a target
 * f(3,4) from index 0-3 does there exist someone with a target 4
 * 
 *            f(ind,target){
 *              if(target ==0) return true;
 *              if(ind==0 && arr[ind]==target) return true; 
 *              
 *              bool nottake=f(ind-1,target);
 *              bool take= false;
 *              if(target>=ar[ind]){
 *                    take=f(ind-1,target-arr[ind]);   
 *              }
 *                return take or nottake;
 *      
 *              } 
 * 
 * t.c: O(2^n) for every array element we have 2 options either take or not take
 * s.c: O(n) aux stack space
 * 
 */



bool subsetSumToKRecursive(int ind,int target,vector<int>& arr){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);
    
    bool notTake=subsetSumToKRecursive(ind-1,target,arr);
    bool take=false;
    if(arr[ind]<=target){
          take=subsetSumToKRecursive(ind-1,target-arr[ind],arr);
    } 
  

    return take|| notTake;
}

bool subsetSumToKDP(int ind,int target,vector<int>& arr,vector<vector<int>>& dp){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTake=subsetSumToKDP(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target){
          take=subsetSumToKDP(ind-1,target-arr[ind],arr,dp);
    } 
  
    //will autoatically convert to int
    return dp[ind][target]= take|| notTake;
}

bool subsetSumToKTabulation(int n,int target,vector<int>& arr){
   vector<vector<bool>> dp (n,vector<bool> (target+1,0));
   //targetis achieb=ved hence mark as true
   for(int i=0;i<n;i++) dp[i][0]=true;
   //from index 0 target A[0] can be achieved hence marked as true
   dp[0][arr[0]]=true;
   for(int i=1;i<n;i++){
    for(int k=1;k<=target;k++){
                bool notTake=dp[i-1][target];
                bool take=false;
                if(arr[i]<=target){
                    take=dp[i-1][target-arr[i]];
                } 
                dp[i][k]=take || notTake;
        }
    }
    return dp[n-1][target];
}

//
//t.c: O(n*target) s.c: O(n*target)

//space optimization
bool subsetSumToKTabulationSpaceOptmized(int n,int target,vector<int>& arr){
   vector<bool>prev(target+1,0),curr(target+1,0);
   //target is achieved hence mark as true
   prev[0]=curr[0]=true;
   //from index 0 target A[0] can be achieved hence marked as true
    if(arr[0]<target) prev[arr[0]]=true;
   for(int i=1;i<n;i++){
    for(int k=1;k<=target;k++){
                bool notTake=prev[target];
                bool take=false;
                if(arr[i]<=target){
                    take=prev[target-arr[i]];
                } 
                curr[k]=take | notTake;
        }
        prev=curr;
    }
    return prev[target];
}

//t.c: O(n*target) s.c: O(target)



bool subsetSumToK(int n,int target,vector<int>& arr){
   vector<vector<int>>dp(n,vector<int>(target+1,-1));
   return subsetSumToKDP(n-1,target,arr,dp);
}