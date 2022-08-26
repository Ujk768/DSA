#include<iostream>
#include<vector>
using namespace std;


/**
 * @brief 
 * 
 * 
 *      5   9   6
 *      11  5   2
 *  only allowed to move in the bottom or in the right
 * 
 *  path fron (0,0) to (1,2)
 *  
 *  paths=> 5 11 5 2 = 23
 *  path=> 5 9 5 2 = 21 => minimum
 * 
 *  whenever there is no uniformity in the values you cannot apply greedy nature
 * 
 *  minimu cost path => try out all paths and find the miminum path from there
 * 
 *  1. express recurence in terms of index
 *  2. do all stuffs on that index
 *  3. take the minimal path
 *          
 *              f(i,j)=> minimum cost to reach from (0,0) to (i,j)
 * 
 *          f(i,j){
 *              if(i==0 and j==0) return A[0][0];
 *              if(i<0 || j<0) return INT_MAX;
 *              
 *              up=A[i][j]+f(i-1,j);
 *              left=A[i][j]+f(i,j-1);
 *              return min(up,left);
 *              
 *      }
 * 
 *      since there are overlapping subproblem we can apply memoization
 *      int dp[n][m]=-1;
 *        f(i,j){
 *              if(i==0 and j==0) return A[0][0];
 *              if(i<0 || j<0) return INT_MAX;
 *              if(dp[i][j]!=-1) return dp[i][j];
 *              up=A[i][j]+f(i-1,j);
 *              left=A[i][j]+f(i,j-1);
 *              return dp[i][j]=min(up,left);
 *              
 *      }
 * 
 * 
 *      T.c: O(n*m)  S.c: O(m-1 +n-1)
 * 
 *      Tabulation
 *       int dp[n][m];
 *      
 *       for(i=0->n-1){
 *          for(j=0->m-1){
 *                  if(i==0 and j==0) dp[i][j]=A[0][0];
 *                  else{
 *                         if(i>0) up=A[i][j]+dp[i-1,j];
 *                         if(j>0) left=A[i][j]+dp[i][j-1];
 *                          dp[i][j]=min(up,left);
 *                      }
 *                  
 *          }    
 *      }
 *      return dp[n-1][m-1];
 * 
 */
        //recursive
    int minSumPathrecursive(int i, int j, vector<vector<int>>&grid){
                if(i==0 && j==0) return grid[0][0];

                if(i<0 || j<0) return INT_MAX;

                int up=grid[i][j]+minSumPathrecursive(i,j-1,grid);
                int left=grid[i][j]+minSumPathrecursive(i-1,j,grid);
                return min(up,left); 


    }

    //memoization
       int minSumPathMemoization(int i, int j, vector<vector<int>>&grid,vector<vector<int>>& dp){
                if(i==0 && j==0) return grid[0][0];

                if(i<0 || j<0) return INT_MAX;

                if(dp[i][j]!=-1) return dp[i][j];

                int up=grid[i][j]+minSumPathMemoization(i,j-1,grid,dp);
                int left=grid[i][j]+minSumPathMemoization(i-1,j,grid,dp);
                return dp[i][j]=min(up,left); 

    }

    int minSumPathTabulation(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
      
        vector<vector<int>>dp(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=grid[0][0];
                else{
                    int up=grid[i][j];
                    if(j>0){
                        up+=dp[i][j-1];
                    }else up+=1e9;
                    int left=grid[i][j];
                    if(i>0){
                        left+=dp[i-1][j];
                    }else left+=1e9;

                    dp[i][j]=min(left,up);
                }
            }
        }
        return dp[n-1][m-1];


    }






    int minSumPath(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        //declaring a 2d matrix with -1 initialized
        vector<vector<int>>dp(n,vector<int>(m,-1));

    }