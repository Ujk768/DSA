#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * 
 * printing subsequences with given sum as k
 * 
 *      f(ind,[],s){
 *          if(i==n){
 *              if(s==sum) print arr;
 *              return;
 *              }
 *          arr.add(Arr[i]);
 *          s+=arr[i];
 *          f(ind+1,[],s)
 *          arr.popback();
 *          s-=arr[i];
 *          f(ind+1,arr,s);
 * 
 *      }
 * 
 * 
 * 
 * check for only a single subsequence
 * 
 *   f(ind,[],s){
 *          if(i==n){
 *              if(s==sum) print arr; return true; 
 *              return false;
 *              }
 *          arr.add(Arr[i]);
 *          s+=arr[i];
 *          if(f(ind+1,[],s)==true) return true;
 *          arr.popback();
 *          s-=arr[i];
 *          if(f(ind+1,arr,s)==true) return true;
 *          return false; 
 *      }
 * 
 * 
 * 
 * 
 * GRID UNIQUE PATHS
 * 
 * we use recursion because we are trying out all posible ways
 * 
 * 1. express evrything in terms of index(i,j)
 * 2. do all stuffs on that index
 * 3. sum/max/min of all the ways
 * 
 * 
 * (0,0)=> (n-1,n-1)
 * f(i,j)=> no of unique ways to reach from (0,0) to (i,j)
 * 
 * f(n-1,n-1)=> starting point
 * 
 * 
 * base case=> if we reached destination return 1 else we return 0
 * 
 * f(i,j){
 *      if(i==0 && j==0) return 1;
 *       //not a path as we get out of the boundary
 *      if(i>0 || j<0) return 0;
 * 
 *      up=f(i-1,j);
 *      left=f(i,j-1);
 *      return up+left;
 * 
 * }
 * each box we take 2 paths hence 2^n
 * t.c O(2^m*n)
 * s.c: O(m-1 + n-1)
 * 
 * 
 * we have overlapping subproblems hence we can use memoizaton
 * 
 * (i,j)=> max value of i is m-1
 * max value of j is n-1
 * 
 * hence we declare an array of size dp[m][n] as it will have index m-1 and n-1
 *
 * t.c: O(n*m) max calls of m*n calls for recusion
 * s.c: O(n-1+m-1)+O(n*m)=> dp 
 * n+1 +m-1 path length
 * 
 * //Tabulation => bottom up approach 
 * dp[n][m];
 * dp[0][0]=1;
 * 
 * 1. declare base case
 * 2. ecpress all states in for loops
 * 3. copy the recurrence
 * 
 * for(int i=0->n-1){
 *      for(j=0-> n-1){
 *              if(i==0 && j==0) dp[0][0]=1;
 *              if(i>0) up=dp[i-1][j];
 *              if(j>0) left=dp[i][j-1];
 *              dp[i][j]=up+left;
 *      }
 * }
 * 
 * print(dp[n-1][m-1]);
 * 
 * t.c: o(n*m) sc: o(n*m)
 * 
 * if there is a prev row and a prev column you can do space 
 * optimization
 * 
 * 
 *  
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */