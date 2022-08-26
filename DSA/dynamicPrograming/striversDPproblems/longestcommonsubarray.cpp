#include<iostream>
#include<vector>
using namespace std;


/**
 * @brief 
 * 
 * 
 * s1="abcjklp"  s2="acjkp"  ans=cjk
 * 
 * //matching 1+dp[i-1][j-1]
 * 
 * else dp[i][j]=max(dp[i-1][j],dp[i][j-1])
 * 
 * this else line wont work because you hae tp be consecutive in nature
 *
 * dp[i][j]= max number of items that match till i-1,j-1
 * 
 * since its consecutive we are not dependent on any of them 
 * whenever they are matching we can take the prev guy
 * 
 *                a   b   z   d
 *             0   1   2   3   4   
 *      0      0   0   0   0   0  
 *   a  1      0   1   0   0   0
 *   b  2      0   0   2   0   0
 *   c  3      0   0   0   0   0
 *   d  4      0   0   0   0   1
 * 
 * 
 * max value in the matrix is the answer
 * 
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
    int ans=0;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++ ){
            if(s[i-1]==t[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1]; ans=max(ans,dp[i][j]);
            } 
            else dp[i][j]=0;
        }
     }

   
}