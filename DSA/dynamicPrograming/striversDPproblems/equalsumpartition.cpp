#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * you are given an array and your task is to find if you can partition the given array into two subsets
 * such that sum of both the subsets is equal
 * 
 * [2 3 3 4 5]  [2 3 5] [3 3 4] true
 * 
 * 
 * if entire subset sum =s then one subset will have sum s1 and other sum s2
 *  
 * s1=s2=s/2
 * 
 * so if s is odd the division is not possible
 * 
 * looking for a subset with sum = s/2
 * 
 * you just need to check for one subset because if you get for one subset you can get for the other subset as well
 * 
 * same as subset sum = target with target being s/2
 * 
 */

//space optimization
bool subsetSumToKTabulationSpaceOptmized(int n,int target,vector<int>& arr){
   vector<bool>prev(target+1,0),curr(target+1,0);
   //target is achieved hence mark as true
   prev[0]=curr[0]=true;
   //from index 0 target A[0] can be achieved hence marked as true
   if(arr[0]<target) prev[arr[0]]=true;
   for(int i=1;i<n;i++){
    for(int k=1;k<=target;k++){
                bool notTake=prev[target];
                bool take=false;
                if(arr[i]<=target){
                    take=prev[target-arr[i]];
                } 
                curr[k]=take | notTake;
        }
        prev=curr;
    }
    return prev[target];
}
bool canPartition(vector<int> & arr, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0) return false;
    int target=sum/2;

    return subsetSumToKTabulationSpaceOptmized(n,target,arr); 
}