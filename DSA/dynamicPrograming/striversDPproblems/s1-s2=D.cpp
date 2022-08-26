#include<iostream>
#include<vector>
using namespace std;


/**
 * @brief 
 * 
 * s1-s2=D
 * 
 *  an array is divided into two parts s1 and s2 
 * where s1>=s2 and s1-s2 =d
 * and count how many subsets we can divide into
 * 
 * arr={5   2   6   4}
 * D=3
 * 
 *  {6 4}   {5 2}
 *   10      7 = 3
 * s1-s2=D
 * s1= total sum-s2
 * totalsum-s2-s2=D
 * totalsum-2s2=D
 * totalsum-D=2s2
 * s2=totalsum-D/2
 * 
 *  count no of subsets with (totalsum-D)/2
 * 
 * total sum-D has to be greater than 0
 * totalsum-D has to be even as we dont have decimals
 * 
 * at index 0 if your sum is also 0 you have 2 cases
 * else at index 0 then you have only 1 case
 */


int countsubsetSumDP(int ind, int sum, vector<int> arr,vector<vector<int>>& dp){
  if(sum==0) return 1;
  if(ind==0){
    return (sum==arr[ind]);
  }
  if(dp[ind][sum]==-1) return dp[ind][sum];
  int pick=0;
  if(arr[ind]<=sum) pick=countsubsetSumDP(ind-1,sum-arr[ind],arr,dp);
  int notpick=countsubsetSumDP(ind-1,sum,arr,dp);
  return dp[ind][sum]= pick+notpick;
}
int findways(vector<int>& num, int tar){
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return countsubsetSumDP(n-1,tar,num,dp);
}


int countPartitions(int n, int d, vector<int>&arr){
    int totSum=0;
    for(auto & it: arr) totSum+=it;
    //totalsum-d has to be even as we cant have decimals and not less than 0
    if(totSum-d<0 || (totSum-d)%2 !=0) return 0;
    return findways(arr,(totSum-d)/2);
}