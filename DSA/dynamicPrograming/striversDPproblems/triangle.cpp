#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * till now we had a fixed starting point(0,0) and ending point(n-1,m-1)
 * 
 * variable starting point and ending point
 * 
 * you are given a triangle array return the minimum path sum to reach from the top to bottom row
 * 
 *  N rows and the ith row will have n+1 elements
 * 
 * 
 *      1
 *      2   3
 *      3   6   7
 *      8   9   6   10
 * 
 *      
 *  you can move to the bottom of the next row or diagonally to the next row
 *  the strating point is fixed
 *  ending point is not fixed as it states that we just have to reach the last row and any index in that last row is fine
 * 
 *  we have to find the minimum path sum in this triangle.
 * 
 *  path=> 1 2 3 8 =14 
 * 
 * Greedy cant be applied because there is no uniformity in the values
 * 
 * 
 * try out all the paths and find minimum g=hence we use recursion
 * 
 *      1. represent as an index
 *      2. do all the stuffs on that index
 *      3. find the minimum path
 * 
 *  
 *  if we start from bottom we have to make recusive calls from all the indexes in the ;last row 
 * 
 * this is  not preferable hence we start from the first element and move downwards
 * 
 * dowm=> (i+1,j)  diagonal=>(i+1,j+1)
 * 
 *      f(0,0) min path sum from (0,0) to the last row
 * 
 *                  f(i,j){
 *                      if(i==n-1) return a[n-1][j];
 *                      d=a[i][j]+f(i+1,j);
 *                      dg=a[i][j]+f(i+1,j+1);
 *                      return min(d,dg);
 *                  }      
 *          t.c: O(n*2^n)   s.c: O(n)
 * 
 *           there are overlapping subproblems hence we can apply memoization 
 * 
 * max value of i => n max value of j=>m 
 * dp[n][m]
 * 
 *                 f(i,j){
 *                      if(i==n-1) return a[n-1][j];
 *                      if(dp[i][j]!=-1) return dp[i][j];
 *                      d=a[i][j]+f(i+1,j);
 *                      dg=a[i][j]+f(i+1,j+1);
 *                      return dp[i][j]=min(d,dg);
 *                  }      
 *      t.c: O(n*n)  s.c: O(n) +O(n*n)=> dp array + recursion stack space
 * 

 *          tabulation

    for every i its equivalent ot the numbe rof columns for that particular index i

        int dp[n][m];
        for(j=0;j<n;j++){
            dp[n-1][j]=a[n-1][j];

        }
        for(int i=n-2;i>=0;i--){
            for(j=i;j>=0;j--){
                d=a[i][j]+dp[i+1][j];
                dg=a[i][j]+dp[i+1][j+1];
                dp[i][j]=min(d,dg);

            }
        }
        print(dp[0][0]);
 *  
        t.c: O(n*n)  s.c: O(n)

        space optimization
        
 */
    //recursion
int minPathSumRecursionTriangle(int i, int j,vector<vector<int>>& triangle, int n){
    if(i==n-1 ) return triangle[n-1][j];

    int d=triangle[i][j]+minPathSumRecursionTriangle(i+1,j,triangle,n);
    int dg=triangle[i][j]+minPathSumRecursionTriangle(i+1,j+1,triangle,n);
    return min(d,dg);
}
//memoization

int minPathSumTriangleDP(int i, int j,vector<vector<int>>& triangle, int n,vector<vector<int>>& dp){
    if(i==n-1) return triangle[n-1][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int d=triangle[i][j]+minPathSumTriangleDP(i+1,j,triangle,n,dp);
    int dg=triangle[i][j]+minPathSumTriangleDP(i+1,j+1,triangle,n,dp);
    return dp[i][j]=min(d,dg);
}

int minPathsum(vector<vector<int>>& triangle, int n){
    //initializing dp matrix
    vector<vector<int>>dp(n,vector<int>(n,-1));

}
//tabulation
int minPathSumTriangleTabulation(vector<vector<int>>& triangle, int n){
     vector<vector<int>>dp(n,vector<int>(n,-1));
     for(int j=0;j<n;j++){
        dp[n-1][j]=triangle[n-1][j];
     }
     for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d=triangle[i][j]+dp[i+1][j];
            int dg=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(d,dg);
        }
     }
     return dp[0][0];
}
//space optimization

int minPathSumTriangleSpaceOptimized(vector<vector<int>>& triangle, int n){
    vector<int>front(n,0),curr(n,0);
     for(int j=0;j<n;j++){
        front[j]=triangle[n-1][j];
     }
     //instead of dp[i+1] use front
     //indtead of dp[i] use curr 
     for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d=triangle[i][j]+front[j];
            int dg=triangle[i][j]+front[j+1];
            curr[j]=min(d,dg);
        }
        front=curr;
     }
     return front[0];
}