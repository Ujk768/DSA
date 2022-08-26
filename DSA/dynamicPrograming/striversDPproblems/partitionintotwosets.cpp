#include<iostream>
#include<vector>
using namespace std;
/**
 * @brief 
 * 
 * partion the subsets onto two sets such that the difference of the subsets is minimum
 * 
 * array has all non negative integers
 * 
 * [1 2 3 4 ]
 * 
 * {1,2} {3,4}  |3-7|=>4 
 * {1 3} {2 4} |4-6|=>2  ans=0;
 * {1 4} {2 3} |5-5| =0 
 *  
 * 
 * subset sum = k problem recurrence
 * 
 *      f(ind,target){
 *          if(target ==0s) return true;
 *          if(ind==0) return (arr[0]==target);
 *          nottake=f(ind-1,target)
 *          if(arr[ind]<=target) take=f(ind-1,target-arr[ind]);
 *          return take| nottake;
 * 
 *      }
 * 
 * n=5 target=7 
 * dp[5][8] 
 * once the array gets filled you can tell yes or no for every target value is possible form 1-> 7
 * if we check for a target = k  we can derive if every possible target between  1 & k is possible or not
 * 
 * you only need to solve for one half of the array
 * [3 2 7] total sum=12
 * s1=3 s2=abs(12-3)=9 => no need ot call function to find value of s2
 * 
 * looking for |s1-s2| to be as minimal as possible
 * 
 * min summation for s1=0
 * max sumation fro s1= sum of all elements
 * 
 * check for all possible sum values to get value of s1
 * 
 * 0 1 2 3 4 5 6 7 8 9 10 11 12
 * 
 * dp[3][12+1] 
 * 
 * using this row we can check what values are possible to get that particular target sum
 * 
 * the values which return true are valid for s1 // if we get a subset sum 
 * s2 =sum-s1
 * 
 * return the min value from the absolute differences of s1 and s2
 * 
 * 
 * ind dp[n][sum+1];
 * //call subset sum code
 * 
 * min=1e9
 * for(int i=0;i<totsum;i++){
 *  if(dp[n-1][i]) s1=i; s2=totsum-i; mini=min(mini,|s2-s1|);
 * 
 * } 
 * 
 * return mini
 * 
 * 
 * if you check fro half of the sum you will still get the full element
 * 
 * so we can use totalsum/2 also 
 * 
 * 
 * 
 */


int minSubsetSumDifference(vector<int>& arr, int n){
    int totSum=0;
    for(int i=0;i<n;i++) totSum+=arr[i];

   int target=totSum;
   vector<vector<bool>> dp (n,vector<bool> (target+1,0));
   //targetis achieb=ved hence mark as true
   for(int i=0;i<n;i++) dp[i][0]=true;
   //from index 0 target A[0] can be achieved hence marked as true
   if(arr[0]<=target) dp[0][arr[0]]=true;
   for(int i=1;i<n;i++){
    for(int k=1;k<=target;k++){
                bool notTake=dp[i-1][target];
                bool take=false;
                if(arr[i]<=target){
                    take=dp[i-1][target-arr[i]];
                } 
                dp[i][k]=take | notTake;
        }
    }
   //dp[n-1][col->0-m-1] will tell ans
   int mini=1e9;
   for(int s1=0;s1<n;s1++){
    if(dp[n-1][s1]){        //s2 if that sum is possible then rest of subset will contain the other min sum
        mini=min(mini,abs((totSum-s1)-s1));
    }
   }
   return mini;
}



