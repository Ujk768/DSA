#include<iostream>
#include<vector>

using namespace std;

/***
 * frog jump
 *
 * frog on the first step of a n stair long staircase
 * frog wants to reach the nth stair
 * height[i] is height of i+1th stair
 * if frog jumps from ith stir to jth stair,
 * the energy lost in the jump is given by:
 *  height[i-1]-height[j-1]
 *
 * if the frog is on the ith stair case he can jump to
 * either (i+1)th stair or to the (i+2)th stair.
 *
 *
 * find the minimum total energy used by the frog to reach from
 * 1st stair to nth stair
 *
 * 0   1   2   3
 * 10  20  30  10
 *
 * min energy to move from 0-1 is 10(20-10)
 *  min energy to move from 1-2 is 10(30-20)
 *  min energy to move from 2-3 is 20(10-30)
 *
 * total energy used is: 40
 *
 *  min energy to move from 0-2 is 20(30-10)
 *  min energy to move from 2-3 is 10
 * total energy used is:30
 *
 * min energy to move from 0-1 :10
 * min energy to move from 1-3:10
 * total energy used is :20
 *
 * we are trying all possible ways hence a recursive problem
 *
 * and find path with minimum cost
 *
 * steps
 * 1) express all paths in index
 * 2) do al stuffs on that index
 * 3) take the minimum of all stuffs
 *
 *
 * f(n-1): min energy required to reach n-1 from index 0
 * f(ind){
 * if(ind==0) return 0
 * // frog is allowed to jump +1 or +2 from an index
 * left=f(ind-1)+abs(ar[ind]-ar[ind-1]);
 * if(ind>1){
 * right=f(ind-2)+abs(ar[ind]-ar[ind-2]);
 * }
 * return min(left,right);
 * }
 *
 *
 * to apply memoization look at the parameters changing
 *
 * memoization is a top down approach
 *
 * int dp[6]
 *
 *  f(ind){
 * if(ind==0) return 0
 * if(dp[ind]!=-1) return dp[ind];
 * // frog is allowed to jump +1 or +2 from an index
 * left=f(ind-1)+abs(ar[ind]-ar[ind-1]);
 * if(ind>1){
 * right=f(ind-2)+abs(ar[ind]-ar[ind-2]);
 * }
 * return dp[ind]=min(left,right);
 * }
 *
 * t.c: O(n) s.c:O(n)+O(n)
 * one for recursive stack and one for array size
*/
//recursive solution
int frogjJumpRecursive(int ind,vector<int>&height){
    if(ind==0) return 0;
    int l=frogjJumpRecursive(ind-1,height)+abs(height[ind]-height[ind-1]);
    int r=INT_MAX;
    if(r>1) r=frogjJumpRecursive(ind-2,height)+abs(height[ind]-height[ind-2]);
    return min(l,r);
}
//dynamic programming
int frogjJumpDP(int ind,vector<int>&height,vector<int>&dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int l=frogjJumpDP(ind-1,height,dp)+abs(height[ind]-height[ind-1]);
    int r=INT_MAX;
    if(r>1) r=frogjJumpDP(ind-2,height,dp)+abs(height[ind]-height[ind-2]);
    return dp[ind]= min(l,r);
}
//Tabulation
int frogJumpTabulation(int n,vector<int>&height){
   vector<int>dp(n,0);
   dp[0]=0;
   for(int i=1;i<n;i++){
    int fs=dp[i-1]+abs(height[i-1]-height[i]);
    int ss=INT_MAX;
    if(i>1){
         ss=dp[i-2]+abs(height[i-2]-height[i]);
    }
    dp[i]=min(fs,ss);
   }

   return dp[n-1];

}

//space optimization
// there will always be space optimization if there is ind-1 and ind-2

int frogJumpSpaceOptimized(int n,vector<int>&height){

   int prev=0,prev2=0;
   for(int i=1;i<n;i++){
    int fs=prev+abs(height[i-1]-height[i]);
    int ss=INT_MAX;
    if(i>1){
        int ss=prev2+abs(height[i-2]-height[i]);
    }
    int curr=min(fs,ss);
    prev2=prev;
    prev=curr;
   }

   return prev;

}




int frogjump(int n, vector<int>& height){
    vector<int>dp(n+1,-1);
    return frogjJumpDP(n-1,height,dp);
}
