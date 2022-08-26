#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * ninja has two friends alice and bob and he wants to collect max chocolates as possible with the help of his friends
 * 
 * initially alice is in the top left corner , bob is in top right corner.
 * they can move just below their current cells
 * alice or bob if at (i,j) can move to (i+1,j) (down) ,(i+1,j-1) (left diagonal) or (i+1,j+1) (right diagonal)
 * 
 * when anyone passes from that cell number of chocolates in that cell becomes 0;
 * 
 * if both stay in the same cell then none of the chocolates are picked
 * 
 * 
 * fixed starting point
 * variable ending point=> anywhere on the last row
 * non uniformity hence greedy cant be applied so we compute all paths by alice and all paths by bob
 * 
 * recursion 
 * 
 * we cant solve recursion individually as there can be a common cell between aclie and bob
 *                                    Alice        Bob
 * 1. express everyhting in terms of (i1,j1) and (i2,j2)
 * 2. explore all the paths (down left diagonal and right diagonal)
 * 3. find max sum possible
 * 
 * since there is a fixed starting point we start the recursion from there 
 * 
 * 
 * starting point (0,0) alice stating point 
 *                 (0,m-1) bob starting point
 * 
 * better to use -1e8 instead of int min as INTMIN may be added with another negative and cross the range for int
 * 
 * base case:
 * 
 * 1. destination base case => we have reached the last row
 * 2. out of boun base case=> alice/ bob might cross the
 * 
 * instead of i1 and i2 we can just use a single i as both of them will be moving to the same row at each time
 * 
 * for each  movement of alice bob can have 3 differnet movements hence 9 combos of path
 * 
 * 
 *                              i,j
 * 
 *              i+1,j-1         i+1,j        i+1,j+1
 * 
 * row is always changing to +1 
 * col changes by -1 first time then 0  then 1
 * dj[]=[-1,0,1];
 * 
 * for(i->-1 to +1){
 *      //all movements for bob when alice moves
 *      for(j->-1 to +1){
 *              
 *          }     
 * }
 * 
 *  
 *
 * f(i1,j1,j2){
 *      if(j1<0 || j1>=m || j2<0  || j2>=m) return -1e8;
 *      if(i==n-1){
 *              if(j1==j2) return A[i1][j1];
 *              else return A[i2][j2]+A[i1][j1];    
 *       }
 *           maxi=0;
 *          // explore all paths alice and bob can go together
 *        for(dj1-> -1 to 1){
 *              for(dj2 -> -1 to 1){
 *                  if(j1==j2) maxi=max(maxi,A[i1][j1]+ f(i+1,j1+dj1,j2+dj2)) =>all movements for bob and alice  
 *                  else       maxi=max(maxi,A[i1][j1]+A[i1][j2]+ f(i+1,j1+dj1,j2+dj2))
 *              }
 *          }
 *      return maxi;
 * }
 * 
 * t.c : O(3^n * 3^n)   s.c: O(n)=> auxilliary stack space
 * 
 * 
 * overlapping subproblems exists hence we apply memoization
 * 
 * 
 *                  i    *   j1  *   j2
 *   max size:      n         m       m
 * 
 *      dp[n][m][m];
 * 
 * 
 * 
 *            f(i1,j1,j2){
 *      if(j1<0 || j1>=m || j2<0  || j2>m) return -1e8;
 *      if(i==n-1){
 *              if(j1==j2) return A[i1][j1];
 *              else return A[i2][j2]+A[i1][j1];    
 *       }
 *          if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];  
 *           maxi=0;
 *          // explore all paths alice and bob can go together
 *        for(dj1-> -1 to 1){
 *              for(dj2 -> -1 to 1){
 *                  if(j1==j2) maxi=max(maxi,A[i1][j1]+ f(i+1,j1+dj1,j2+dj2)) =>all movements for bob and alice  
 *                  else       maxi=max(maxi,A[i1][j1]+A[i1][j2]+ f(i+1,j1+dj1,j2+dj2))
 *              }
 *          }
 *      return dp[i][j1][j2]=maxi;
 * }
 * 
 * t.c: O(n*m*m)*9 s.c: O(n*m*m)+O(n) 
 * 
 * 
 * 
 * 
 * 
 * 
 */     


int maximumChocolatesRecursive(int i, int j1, int j2,int c, int r,vector<vector<int>>& grid){
    if(j1<0 || j2<0 || j1>=c ||j2>=c){
        return -1e8;
    }
    if(i==r){
        if(j1==j2) return grid[i][j1];
        else{
            return grid[i][j1]+grid[i][j2];
        }
    }
    //explore all paths of bob and alice
    int maxi=-1e8;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int value=0;
            if(j1==j2) value+=grid[i][j1];
            else value+=grid[i][j1]+grid[i][j2];
            value+=maximumChocolatesRecursive(i+1,j1+dj1,j2+dj2,c,r,grid);
            maxi=max(maxi,value);
        }
    }
    return maxi;
}


int maximumChocolatesDP(int i, int j1, int j2,int c, int r,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
    if(j1<0 || j2<0 || j1>=c ,j2>=c){
        return -1e8;
    }
    if(i==r){
        if(j1==j2) return grid[i][j1];
        else{
            return grid[i][j1]+grid[i][j2];
        }
    }
    //explore all paths of bob and alice
    int maxi=-1e8;
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int value=0;
            if(j1==j2) value+=grid[i][j1];
            else value+=grid[i][j1]+grid[i][j2];
            value+=maximumChocolatesDP(i+1,j1+dj1,j2+dj2,c,r,grid,dp);
            maxi=max(maxi,value);
        }
    }
    return dp[i][j1][j2]=maxi;
}

int maximumChocolate(vector<vector<int>>& grid, int r ,int c){
    //declaring a 3d vector
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));

    return maximumChocolatesRecursive(0,0,c-1,c,r,grid);
}