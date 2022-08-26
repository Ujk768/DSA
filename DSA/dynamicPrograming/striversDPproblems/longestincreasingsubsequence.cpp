#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * arr[]=>[10 9 2 5 3 7 101 18]
 * 
 * {10,101} len=2

 *2 3 7 101 len=4  max len=4

 all subsequece problems we solved with take and not take

    brute force exponential

    trying all ways hence we use recursion

    1. express evertyhing in terms of ind
    2. explore all possibliites
    3. get longest out of all


    if we previously took 10 we cant take 9 as the next subsequence hence we need to
    keep store of the prev ind value

    prev tells us if we can take the ind in subsequence or not

    f(0,-1) give len of LIs with no elements seleceted
    f(3,0) len of LIS staring at ind 3 with prev ind is 0
    
    
    f(ind,prev) {

        if(ind==n) return 0;

        //not take
        0+f(ind+1,prev)
        //take
        if(prev==-1 || arr[ind]>arr[prev]) 1+f(ind+1,ind)
        len= max(take,nottake)
        return len
    }

t.c: 2^n s.c:O(n)
    //dp

    we need to do a coordinate shoft as we cant store -1 index
    f(ind,prev) {

        if(ind==n) return 0;
        if(dp[ind][prev]!=-1) return dp[ind][prev]
        //not take
        0+f(ind+1,prev)
        //take
        if(prev==-1 || arr[ind]>arr[prev]) 1+f(ind+1,ind)
        len= max(take,nottake)
        return dp[ind][prev+1]=len
        //change coordinate of prev index
    }

dp[n][n+1]

t.c:O(n*n) s.c: O(n^2)+O(n)



tabulation


1. base case
2. ind= n-1 -> 0
//prev_ind will start from ind-1
    prev_ind= ind-1 -> -1

 */ 

int lisRecur(int ind, int prev_ind,int arr[],int n){
    if(ind==n) return 0;
    //nottake
    int len=lisRecur(ind+1,prev_ind,arr,n);
    // take
    if(prev_ind==-1|| arr[ind]>arr[prev_ind]){
        len=max(len,lisRecur(ind+1,ind,arr,n)+1);
    }
    return len;
}

int lisDp(int ind,int prev_ind,int arr[],int n, vector<vector<int>> & dp ){
    if(ind==n) return 0;
    if(dp[ind][prev_ind]!=-1) return dp[ind][prev_ind];
    //nottake
    int len=lisDp(ind+1,prev_ind,arr,n,dp);
    // take
    if(prev_ind==-1|| arr[ind]>arr[prev_ind]){
        len=max(len,lisDp(ind+1,ind,arr,n,dp)+1);
    }
    //ind +1 to shift the index
    return dp[ind][prev_ind+1]=len;
}

int lisTabulation(int arr[],int n){
     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//shifting ind hence second parsmeter will always have +1
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
             int len=dp[ind+1][prev_ind+1];
                // take
                if(prev_ind==-1|| arr[ind]>arr[prev_ind]){
                    len=max(len,dp[ind+1][ind+1]+1);
                    }
                 //ind +1 to shift the index
                 dp[ind][prev_ind+1]=len;
        }
    }
    return dp[0][-1+1];
}

int lisTabulationOptimized(int arr[],int n){
     vector<int>dp(n,1);
     int maxi=1; 
//shifting ind hence second parsmeter will always have +1
    for(int ind=0;ind<n;ind++){
        for(int prev=0;prev<ind;prev++){
            if(arr[prev]<arr[ind]){
                dp[ind]=max(dp[ind],1+dp[prev]);
            }
        }
        maxi=max(maxi,dp[ind]);
    }
    return maxi;
}



int main(int arr[],int n){
    vector<vector<int>>dp(n,vector<int>(n+1,-1));

    return lisDp(0,-1,arr,n,dp);

}
//this aproach wont work for larger arrays as we try to create a 10^5*a0^5 array which isnt possible

