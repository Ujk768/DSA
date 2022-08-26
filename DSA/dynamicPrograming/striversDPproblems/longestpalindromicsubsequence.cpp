#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

/**
 * @brief 
 * 
 * 
 * s="bbbab"  
 * subsequences
 * 
 * ab
 * bb
 * bbb
 * bbbb => ans longest palindrome len=4
 * bab
 * 
 * 
 * generate all subsequences check for palindeorme and pick the longest
 * 
 * it should match from the frontand from the back
 * 
 * write the string in the reverse order
 * 
 * take the string s1 and the reversed string then find the LCS
 * 
 * 
 * so if you find the longest commmon subsequence between both the strings then its a palindrome
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
            if(s[i-1]==t[j-1]) 1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
     }
    return dp[n][m];
}

int longestPalindromicSubsequence(string s){

    string t=s;
    reverse(t.begin(),t.end());
    return lcs(s,t);
}