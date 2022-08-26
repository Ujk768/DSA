#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * arr=[1,2,3] target=4
 * 
 * any elemnt can be used any number of times
 * {1,1,1,1}
 * {1,1,2}
 * {2,2}
 * {1,3}
 * 
 * figure out total number of ways and count them
 * 
 * hence we use recursion
 * in any case where we have to count number of ways the base case will always return 1 when the destination is met
 * or retuer0 when the destination is not met.
 * 
 * recuerrence
 * 1. express in terms of index,target
 * 2. explore all the possiblilites on that particular index
 * 3. add up all the possible ways
 * 
 * f(2,4) till index 2 in how many ways can you form 4
 * 
 * in any time we can use an elemnt any number of times we dont move the index if we can take the element
 *  f(ind,T){
 *      
 *      if(ind==0){
 *          if(target%arr[ind]==0) return target/arr[ind];
 *          else return 0;
 *      }
 * 
 *      nottake=f(ind-1,T);
 *      take=0;
 *      if(arr[ind]<=T)take=f(ind,T-arr[ind]);
 * 
 *      return nottake+take;
 * 
 * }
 * 
 * t.c: exponential s.c:O(target)
 * 
 * index=> at max n
 * target=> at max t
 * t.c: O(n*target) s.c:O(n*target)+O(n)
 * 
 * tabulation 
 * 1. base case
 * 2. changing parameters ind,T
 * 3. copy the recurrence
 * 
 * 
 *      for(T=0->target)dp[0][T]=(T%arr[0]==0)
 *      target=>0-T
 */


long fRecursive(int ind,int T, int *denominations){
    if(ind==0){
        if(T%denominations[ind]==0) return T/denominations[ind];
        else return 0; 
    }
    long nottake=fRecursive(ind-1,T,denominations);
    long take=0;
    if(denominations[ind]<=T) take=fRecursive(ind,T-denominations[ind],denominations);
    return nottake+take;
}


 long fDp(int ind,int T, int* denominations,vector<vector<long>>&dp){
      if(ind==0){
        if(T%denominations[ind]==0) return T/denominations[ind];
        else return 0; 
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
    long nottake=fRecursive(ind-1,T,denominations);
    long take=0;
    if(denominations[ind]<=T) take=fRecursive(ind,T-denominations[ind],denominations);
    return dp[ind][T]=nottake+take;

 }
long countWaysTabulation(int*  denominations,int n ,int value){
    vector<vector<long>>dp(n,vector<long>(value+1,0));
   for(int T=0;T<=value;T++){
    dp[0][T]=(T%denominations[0]==0); 
   }
   for(int ind=1;ind<n;ind++){
    for(int T=0;T<=value;T++){
        long nottake=dp[ind-1][T];
    long take=0;
    if(denominations[ind]<=T) take=dp[ind][T-denominations[ind]];
    
    dp[ind][T]=take+nottake;

    }
   }
   return dp[n-1][value];
}

long countWays(int*  denominations,int n ,int value){
    vector<vector<long>>dp(n,vector<long>(value+1,-1));
    return fDp(n-1,value,denominations,dp);
}