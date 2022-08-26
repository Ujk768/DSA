#include<iostream>
#include<vector>

using namespace std;

/**
 * @brief 
 * given two strings s1 and s2 find the longest common subsequence
 * s1=adebc   s2=dcadb  => longest common subsequence is adb=>len 3
 * 
 * 
 * brute force: generate all the subsequences of both and linerally iterate and find the largest common subsequence
 * 
 * t.c: exponential hence not followed
 * 
 * generate all subsequences and compare on the go
 * 
 * some recurrence to give the ans through the way
 * 
 *  1.express everythong in terms of indexess
 *  2. explore all possiblities ion that ionedx
 *  3. take the best among them
 * 
 *  f(2) the string till index 2
 * 
 * A single index cant express both the strings hence we need to represent by two inedxes ind1 and ind2
 * 
 * f(2,5) longest common subsequence s1(0-2) and s2(0-5)
 * 
 * explore all possibilities
 * 
 * do comparisions character wise
 * 
 * acd | ced
 * 
 * if both indexes are the ending index then they are both matching
 *  do comparisions char wise
 * 
 * subsequence of len 1 then shrink the string ac and ce then find an ans
 * 
 * //match
 * if(s1[ind1]==s2[ind2]) 1+f(ind1-1,ind2-1)
 * 
 * here we consider the cases of match and not match
 * //non match
 * 
 * ac  ce  ind2 will have to be moved to get a match
 * 
 * ec  ce  ind1 will have to be moved to get a match
 * 
 * in this case we have to explore both the possibilities
 * 
 * 1. move ind1 and keep ind2 as it is
 * 2. move ind2 and keep ind1 as it is
 * 
 * if not match 0+ max((ind-1,ind2),(ind1,ind2-1))
 * 
 * negative means end of the string
 *  
 * 
 *  f(ind1,ind2){
 *         if(ind1<0 || ind2<0) return 0;    
 *      
 *      if(s1[ind1]==s2[ind2]) return 1+f(ind-1,ind2-1);
 *      return max(f(ind1-1,ind2),f(ind1,ind2-1)); 
 *      
 *  }
 * 
 * t.c: 2^n * 2^m 
 * 
 * f(i,j) lcs of a string 0-i and 0-j
 * 
 * i-> ranges from 0-n 
 * j-> ranges from 0-m
 * 
 * hence dp vector of size n*m is required
 * 
 *
 */


int f(int ind1,int ind2, string& s1, string& s2){

    if(ind1<0||ind2<0) return 0;
    if(s1[ind1]==s2[ind2]) return 1+f(ind1-1,ind2-1,s1,s2);

    return max(f(ind1-1,ind2,s1,s2),f(ind1,ind2-1,s1,s2));

}
int fDp(int ind1,int ind2, string& s1, string& s2, vector<vector<int>>& dp){

    if(ind1<0||ind2<0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]= 1+fDp(ind1-1,ind2-1,s1,s2,dp);

    return dp[ind1][ind2]=max(fDp(ind1-1,ind2,s1,s2,dp),fDp(ind1,ind2-1,s1,s2,dp));

}
//t.c for memoization O(n*m) s.c:O(n+m)
int lcsTabulation(string s, string t){
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));


}

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