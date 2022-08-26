#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief shortest coommon supersequence
 * 
 * s1="brute"  s2="groot"
 * 
 *  final string: "brute groot" len=10
 * 
 * "bgruoote " len =8
 * 
 * 
 * bleed blue  => bleued len=6
 * 
 * 
 * 
 * brute  groot
 * 
 * 
 * take both chars if not same
 * 
 * if both are same only take a single char
 * 
 * common guys should be taken once => lcs
 * 
 *  in s1 take everyone except the lcs
 *  in s2 take everyne except the lcs
 * 
 n+m-len(lcs)=>len of shortest common subsequence


 print the string

            g   r   o   o   t
        0   1   2   3   4   5
        0   0   0   0   0   0
   b    1   0   0   0   0   0
   r    2   0   0   1   1   1
   u    3   0   0   1   1   1
   t    4   0   0   1   1   2   
   e    5   0   0   1   1   2
 * 

    at each point in the matrix the value is formed by
    one at the top and one to the left of that element

    shortest common subsequence

    check from ending index

    does e match with t ??
    we  move upwards so
     no so add e to the subsequence
    as its cut off from the string
    the string that exists is now

   the common char gets added once

 */

   int scs(string s, string t){
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //since our base case was -1 we cant write tabulation hence we shift the index

    // f(n) means f(n-1) f(1) means f(0) f(0) means f(-1)
    //f(i,j) every i should be i-1 and evry j should mean j-1
    //base case now if i==0 and j==0 return 0
    for(int j=0;j<=m;j++) dp[0][j]=0;
     for(int i=0;i<=n;i++) dp[i][0]=0;

     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++ ){
            if(s[i-1]==t[j-1]) 1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
     }
    //dp array created
   int i=n,j=m;
   string ans="";
      while(i>0 && j>0){
      if(s[i-1]==t[j-1]){
         i--;j--;
      }else if(dp[i-1][j]>dp[i][j-1]){
         ans+=t[j-1];
         j--;
      }
   }
   while(i>0){
      ans+=t[j-1];
      j--;
   }
   reverse(ans.begin(),ans.end());
}







