#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * s1="abcde" s2="bdgek"  print bde
 * 
 * use the longest subsequence code and print the value in an array only if the value matches then move to the diagonal
 * else move to max of [i][j-1] or [i-1][j]
 * 
 * from the dp tabulaiton code
 * 
 * int i=n,j=m;
 * index=len-1;
 * string s=""';
 * len=dp[n][m];
 * for(i=0->len) s+="$";    
 * while(i>0 && j>0){
 *  if(s1[i-1]==s2[j-1]){
 *          s[index]=s1[i-1];
 * index--;i--;j--;
 *      }
 *  elseif(dp[i-1][j]>dp[i]][j-1]) {
 *          i=i-1;         
 *      }else{
 *          j=j-1;
 *          }
 * }
 * 
 * 
 */


int lcs(string s, string t){
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
            if(s[i-1]==t[j-1]) dp[i][j]= 1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
     }

     int len=dp[n][m];// gets the length of the array
     string ans="";
     for(int i=0;i<len;i++) ans+="$";

     int index=len-1;
     int i=n, j=m;
     while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans[index]=s[i-1];
            index--;
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
     }
    cout<<ans;
}