#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * find the max path that can be obtained from a path starting from any cell
 *  in the first row to any cell in the last row
 * 
 * from a particular cell we can move directly below that row, diagonally left or diagonally right   
 * 
 * greedy cant be used as the values are not uniform
 * 
 * to solve any problem dealing with path we can solve this using recurson by trying out all the paths
 * 
 *   1. express everyhing in terms of i,j
 *  2. do all stuffs on index i,j
 *  3. figure out max of all the paths
 * 
 *      max path sum can end at any elemnt of the last index
 * 
 *      f(i,j)=> max path sum to reach i,j from any cell in the first row
 * 
 *              f(i,j){
 *                    if(j<0 || j>=m) return INT_MIN;
 *                    if(i==0) return dp[i][j];
 *                    
 *                     int s=A[i][j]+f(i-1,j);
 *                     int ld=A[i][j]+f(i-1,j-1);
 *                      int rd=A[i][j]+f(i-1,j+1);
 *                      return max(s,max(ld,rd));
 *                     
 *              }
 * 
 *          T.c(3^n *n) s.c: O(n)
 * 
 *      after memoization : t.c : O(n*m ) s.c: O(n*m) +O(n)
 * 
 *      tabulation: bottom up
 *  1. decalre dp table    
 *  2. base cases
 * 3. observe states (i,j) and convert to loops
 * 
 * 
 */

int getMaxPathSumRecursive(int i ,int j, vector<vector<int>>& matrix){
    if(j<0 || j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[i][j];

    int u=matrix[i][j]+getMaxPathSumRecursive(i-1,j,matrix);
     int ld=matrix[i][j]+getMaxPathSumRecursive(i-1,j-1,matrix);
      int rd=matrix[i][j]+getMaxPathSumRecursive(i-1,j+1,matrix);
      return max(u,max(ld,rd));
}

int getMaxPathSumDp(int i ,int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    if(j<0 || j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int u=matrix[i][j]+getMaxPathSumDp(i-1,j,matrix,dp);
     int ld=matrix[i][j]+getMaxPathSumDp(i-1,j-1,matrix,dp);
      int rd=matrix[i][j]+getMaxPathSumDp(i-1,j+1,matrix,dp);
      return dp[i][j]= max(u,max(ld,rd));
}

int getMaxMainFunction( vector<vector<int>>& matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e8;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    //call recursion from all the columns of the la st row
    for(int j=0;j<m;j++){
        maxi=max(maxi,getMaxPathSumRecursive(n-1,j,matrix));
    }
    return maxi;
}