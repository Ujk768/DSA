#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

/**
 * @brief 
 * 
 * you can perform insertion , remove or replace
 * and you have to return minimum operations to convert string s1 to string s2.
 * 
 * s1="horse"  s2="ros"
 * 
 * possible always delete s1 and insert the chars from s2 to s1
 * 
 * 
 * replace h=> r ==> rorse
 * remove r => rose
 * remove e=> ros
 * 
 * min operations 3
 * 
 * 
 * 
 * perform string matching 
 * 
 * if matching we can move forwards
 * else 
 * not matching options
 * 1. insert of the same char
 * 2. delete and try finding some one else
 * 3. replace and match
 * 
 * 
 * try all ways => recusrion and whichever gives min return that;
 * 
 * 
 * how to write recurrecne?
 * 
 * 1. express in terms of i and j
 * 2. explore all paths of matching
 * 3. return min all paths
 * 4. base case
 * 
 * 
 * f(n-1,m-1): min operations to convert string s1[0-i] to string s2[0-j]
 * 
 *      f(i,j){
 *      if(i<0) return j+1 //j+1 insert operations
 *      if(j<0) return i+1 //i+1 delete operations
 * 
 *              if(s1[i]==s2[j]) return 0+f(i-1,j-1)
 *              
 *  in an insertion we place the char at the end but index i will not shift so only j reduces
 * 
 *   int insert=1+f(i,j-1);
 * 
 * we deleted so i will reduce by one step but j stays where it is  
 * 
 *    int del=1+f(i-1,j);
 * 
 * we always replace with the char we are looking for 
 * 
 * int replace=1+f(i-1.j-1);
 * 
 * return min(insert,del,replace);
 *      }
 * 
 * 
 * t.c: exponential  s.c:O(n+m)
 */

int frecur(int i, int j, string & s1, string & s2){

    if(j<0) return i+1;
    if(i<0) return j+1;

    if(s1[i]==s2[j]) return frecur(i-1,j-1,s1,s2);

    int insert=1+frecur(i,j-1,s1,s2);
    int del=1+frecur(i-1,j,s1,s2);
    int rep=1+frecur(i-1,j-1,s1,s2);
    return min(insert,del,rep);
}

int fdp(int i, int j, string & s1, string & s2, vector<vector<int>>& dp){

    if(j<0) return i+1;
    if(i<0) return j+1;

    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return frecur(i-1,j-1,s1,s2);
    
    int insert=1+fdp(i,j-1,s1,s2,dp);
    int del=1+fdp(i-1,j,s1,s2,dp);
    int rep=1+fdp(i-1,j-1,s1,s2,dp);
    return dp[i][j]=min(insert,del,rep);
}
int editdistanceTabulation(string str1, string str2){
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=n;j++) dp[0][j]=j;
    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
             if(str1[i]==str2[j]) dp[i-1][j-1];
    
    int insert=1+dp[i][j-1];
    int del=1+dp[i-1][j];
    int rep=1+dp[i-1][j-1];
     dp[i][j]=min(insert,del,rep);
        }
    }
    return dp[n][m];
}
 
int editdistance(string str1, string str2){
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return fdp(n-1,m-1,str1,str2,dp);
}