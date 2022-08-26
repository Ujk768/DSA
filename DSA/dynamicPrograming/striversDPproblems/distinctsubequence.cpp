#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

/**
 * @brief   distinct subsequences
 * 
 * 
 * s1="babgbag"  s2="bag"
 * 
 * babgbag
 * 
 * 5 ocuurences of s2 in string s1.
 * 
 * given two string tell no of times s2 appears in s1.
 * 
 * you have to follow different ways of comparing
 * 
 * trying all ways=> recursion
 * 
 * count the no of ways 
 * 
 * 
 *      f(){
 *      base case returns 1 or 0    
 *      }
 * 
 * how to write the recurrence
 * 
 * 1. express everthing in terms of i and j
 * 2. explore all possibilities
 * 3. return summation of all possibilities
 * 4. base case 
 * 
 * s1=babgbag
 * s2=bag
 * 
 * i starts at n-1 and j starts at m-1
 * 
 * f(n-1,m-1) => number of distinct subsequences of string s2[0-j] in string s1[0-i]
 *  f(i,j){
 * 
 * //base case possibilities
 * 
 * 1. we exhaust i but still there is some string j remaining
 * 2. if we have exhausted j it means we have completed s2 and we can return 1
 * 
 * if(j<0) return 1;
 * if(i<0) return 0;
 * 
 *      
 * 
 *  if(s1[i]==s2[j]){
 *      //1.  we can use the element we have got in that case we will reduce both the strings s1 and s2
 *      //2. or we can ignore the element matched and search for another occurence in the string s1.
 *      f(i-1,j-1)+f(i-1,j)
 * 
 *  }else{
 *  //if they dont match we reduce the s1 keeping s2 same
 *      f(i-1,j)
 * }
 *  
 * }
 * 
 * 
 * t.c : exponential s.c: o(n+m)
 * 
 * 
 * can be optimized due to overlapping subproblems
 * 
 * changing parameters i and j 
 * 
 * i max value n j max value is m
 * 
 * dp[n][m]
 */


int frecur(int i,int j,string &s1, string &s2){
    if(j<0) return 1;
    if(i<0) return 0;

    if(s1[i]==s2[j]){
        return frecur(i-1,j-1,s1,s2) + frecur(i-1,j,s1,s2);
    }else return frecur(i-1,j,s1,s2);

}


int fdp(int i,int j,string& s1, string& s2, vector<vector<int>> &dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j]= fdp(i-1,j-1,s1,s2,dp) + fdp(i-1,j,s1,s2,dp);
    }else return dp[i][j]=fdp(i-1,j,s1,s2,dp);

}


int numDistinctTabulation(string s1, string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //1 based indexing needed coz calls of i==-1 and ==-1
    //change the base conditions to i==0 and j==0
    //when comparing we compare with one lesser as we have increased the values
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int j=1;j<=m;j++) dp[0][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1]){
                dp[i][j]= dp[i-1][j-1] + dp[i-1][j];
            }else  dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][m];
}

int numSpaceOptiized(string s1, string s2){
    int n=s1.size();
    int m=s2.size();
  vector<int>prev(m+1,0),curr(m+1,0);
    //1 based indexing needed coz calls of i==-1 and ==-1
    //change the base conditions to i==0 and j==0
    //when comparing we compare with one lesser as we have increased the values
   prev[0]=curr[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1]){
                curr[j]= prev[j-1] + prev[j];
            }else  curr[j]=perv[j];
        }
        prev=curr;
    }
    return prev[m];
}

//further optimized

/**
 *
 * we are only using the values prev[j-1]+prev[j] to compute our values
 *  so we can put the values from the end of prev to start of prev 
 *   we need to write from end only as we need the first values to compute our current ans
 */
int numSpaceOptiizedFutheter(string s1, string s2){
    int n=s1.size();
    int m=s2.size();
  vector<int>prev(m+1,0);
    //1 based indexing needed coz calls of i==-1 and j==-1
    //change the base conditions to i==0 and j==0
    //when comparing we compare with one lesser as we have increased the values

   
   prev[0]=curr[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1]){
                prev[j]= prev[j-1] + prev[j];
            }
        }
      
    }
    return prev[m];
}
int numDistinct(string s1, string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return fdp(n-1,m-1,s1,s2,dp);
}

// if its overflowing use double to create the vectors and then typecast to int at the end