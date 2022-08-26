#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

/**
 * @brief min operations to convert s1 to s2
 * 
 * 
 * str1="abcd"  str2="anc"
 * 
 * delete in string 1 and 
 * insert anywhere in string1
 * 
 * convert string 1 to string 2 using the min chars
 * 
 * its alaways possible to cinvert as we can delete everything in s1 and insert into s2
 * 
 * 
 * max opeartions n+m
 * 
 * what cant i touch
 * 
 * if you touch minimal items number of operations will be minimal
 * 
 * abcd=>anc
 * 
 * delete b and d
 * 
 * ac then insert n
 * 
 * 2 deletions + 1 insertion => 3 operartions
 *  
 * delete anyone and insert anywhere
 * 
 * abcd anc
 * 
 * longest common portion  ac
 * 
 * 
 * longest common subsequence
 * 
 * deletions=n-len(lcs)
 * insertions m-len(lcs) 
 * 
 * so n+m -2*lcs will give our final ans
 * 
 * 
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

     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++ ){
            if(s[i-1]==t[j-1]) 1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
     }
    return dp[n][m];
}

int canYouMake(string &str,string & ptr){
    return str.size()+ptr.size()-2*lcs(str,ptr);
}