#include<stdio.h>
#include<vector>
#include<string>
using namespace std;


/**
 * @brief 
 * 
 * s="abcaa"
 * 
 * you can insert any char anywhere
 * 
 * if you add the reversed string to the original string then it will become palindromic
 * 
 * max operations = len(S);
 * 
 * 
 * abcaa=> aabcbaa palindrome 2 insertions
 * 
 * how to approach 
 * 
 * keep the longest palindrome portion intact
 * 
 * abcaa => aa or a is a palindrome portion
 * 
 * abcaa=>keep aaa intact
 * 
 * a bc a cb a
 * 
 * the strings which are not palindrome we put the reverse of it
 * 
 * 
 *      codingninjas
 * 
 * longest palindrome=>  ingini
 * 
 *         codi  sajn   ingini  njas  idoc
 * 
 *      mininsetions: n- longest palindromic subsequence
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

int minInsertion(string & str){
    return str.size()-longestPalindromicSubsequence(str);
}