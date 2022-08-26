#include<iostream>
#include<vector>
#include<string>

using namespace std;

/**
 * @brief 
 * 
 * ? matches with single char
 * * matches with sequence with length one or more
 * 
 * s1=?ay s2=ray they match return true
 * 
 * s1=ab*cd  s2= abcdef  * becomes=> def hence they match return true
 * 
 * s1=ab?d s2=abcc  false
 * 
 * 
 * we need to try out all possible ways in which * can be used to form a pattern    
 * 
 * all possible ways=> recursion
 * 
 * 1. express in terms of i and j
 * 2. explore comparisions
 * 3. out of all comparisions if anyone can you return true
 * 
 * f(n-1,m-1) in the strin g 0-i and the string 0-j are they matching
 * 
 * f(i,j){
 * 
 *  //base case=> s1 gets exhausted or s2 gets exhausted
 * //if s1 has no more chars left and s2 also has no more chars left then 
 * // both strings needs to be exhausted ofr the comaprision to be true
 * 
 * if(i<0 && j<0) return true;
 * if(i<0 && j>=0) return false;
 * if(j<0 && i>=0 ){
 *      for(int k=0;k<=i;k++) if(s1[i]!='*') return false
 *      return true;
 *  }
 * 
 * 
 * 
 *  if(s1[i]==s1[j] || s1[i]==? ) return f(i-1,j-1);
 * 
 *  with * we can match 0,1,2 --- n any number of chars for *
 *  if(s1[i]==*){
 *      //compare with empty or keep deleting one char each time
 *      return f(i-1,j) || f(i,j-1)
 * }
 * 
 * return false;    
 * 
 * 
 * } 
 * 
 * 
 * 
 * 
 */

int frecur(int i, int j, string & pattern, string & text){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0 ) return false;
    if(j<0 && i>=0){
        for(int k=0;k<=i;k++) if(pattern[k]!='*') return false; 
        return true;
    }
    if(pattern[i]==text[j] || pattern[i]=='?'){
        return frecur(i-1,j-1,pattern,text);
    }
    if(pattern[i]=='*'){
        return frecur(i-1,j,pattern,text) ||frecur(i,j-1,pattern,text); 
    }
    return false;

}

int fdp(int i, int j, string & pattern, string & text,vector<vector<int>> & dp){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0 ) return false;
    if(j<0 && i>=0){
        for(int k=0;k<=i;k++) if(pattern[k]!='*') return false; 
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(pattern[i]==text[j] || pattern[i]=='?'){
        return fdp(i-1,j-1,pattern,text,dp);
    }
    if(pattern[i]=='*'){
        return dp[i][j]= fdp(i-1,j,pattern,text,dp) || fdp(i,j-1,pattern,text,dp); 
    }
    return dp[i][j]=false;

}

bool wildcardMatchingtabulation(string pattern, string text){
    int n=pattern.size();
    int m=text.size();

    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
    dp[0][0]=true;
    for(int j=1;j<=m;j++){
        dp[0][j]=false;
    }
    for(int i=1;i<=n;i++){
        int f1=true;
        for(int k=1;k<=i;k++){
            if(pattern[k-1]!='*') f1=false; break;

        }
        dp[i][0]=f1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(pattern[i]==text[j] || pattern[i]=='?'){
               dp[i][j]= dp[i-1][j-1];
            }else if(pattern[i]=='*'){
                 dp[i][j]= dp[i-1][j] || dp[i][j-1]; 
             }else dp[i][j]=false;
        }   
    }
   return dp[n][m];


}

bool wildcardMatching(string pattern, string text){
    int n=pattern.size();
    int m=text.size();

    vector<vector<int>>dp(n,vector<int>(m,-1));


}