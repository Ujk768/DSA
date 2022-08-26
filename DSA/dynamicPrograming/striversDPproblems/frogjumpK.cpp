#include<iostream>
#include<vector>

using namespace std;

/**
 * @brief 
 * recrurrence relation from original frog jump question
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
 * if we could move 3 steps we would have taken a 3rd variable called ts= f(ind-3)+abs(ar[ind]-ar[ind-3])
 * and then return min of (left,right,ts)
 * 
 * observation
 * 
 * In each relation we are having ind-1,ind-2 ,ind-3 so we can express this as ind-k
 * 
 * 
 * Recursive Code
 * 
 * f(ind){
 * if(ind==0) return 0
 * 
 * int minsteps=INT_MAX;
 * for(int i=1;i<k;i++){
 * if(ind-i>=0){
 *  int jumpEnergy=f(ind-i)+abs(ar[ind]-ar[ind-i]);
 *  minsteps=min(minsteps,jumpEnergy);
 *  }
 * }
 * return minsteps;
 * }
 * 
 * t.c:O(n*k) s.c:O(n) 
 * 
 * Memoization=>top down approach
 * 
 * in each place where index is used change it to dp
 * 
 * int dp[n+1]={-1};
 * 
 * f(ind){
 * if(ind==0) return 0;
 * if(dp[ind]!=-1) return dp[ind];
 * int minsteps=INT_MAX;
 * for(int i=1;i<k;i++){
 * if(ind-i>=0){
 *      int jumpenergy=dp[ind-i]+abs(ar[ind]-ar[ind-i]);
 *      minsteps=min(minsteps,jumpenergy);
 * }
 * }
 * return dp[ind]=minsteps;
 * 
 * }
 * 
 * 
 * Tabulation=>Bottom up approach
 * 
 * int dp[n+1];
 * dp[0]=0;
 * 
 * for(int i=1;i<n;i++){
 * minsteps=INT_MAX;
 * for(j=1;j<=k;j++){
 * if((i-j)>=0){
 *  int jumpenrgy=dp[i-j]+abs(arr[i]-arr[i-j]);
 *  minsteps=min(minsteps,jumpenergy);
 * 
 * }
 * dp[i]=minsteps;
 * }
 * }
 * 
 * print dp[n-1]
 * 
 * 
 * space optimization is not possible as to compute each dp state we are using k last values
 * 
 * 
 */