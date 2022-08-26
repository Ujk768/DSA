#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief
 *
 * you are given an array and you have to find the maximum sum given no adjascent elements are picked
 *
 * approach 1 : try out all subsequnces
 *  pick the one with the maximum sum
 *
 * since we are trying out all subsequences we use recursion
 *
 * print all subsequences using recursion =>take\not-take method
 *
 *  for a subsequence the order should be maintained.
 *  arr=[3,1,2];
 *
 * subsequences :
 * {}
 * 3
 * 1
 * 2
 * 3 1
 * 1 2
 * 3 2
 * 3 1 2
 * 2^3 =8
 * 3 2 1 is not a subsequence as its not in order
 *
 *    f(ind,[]){
 * // you need to traverse till ending index n-1
 *      if(ind>=n){
 *          print([]);
 *          return;
 *       }
 * //take this particular index
 *      [].add(arr[i]);
 *      f(ind+1,[]);=>take case
 * // remove the prev selceted index
 *      [].remove(arr[i]);
 *      f(ind+1,[]);=> not take case
 * }
 *
 * main(){
 *  arr=>[3,1,2]
 * f(0,[])
 * }
 *

 print all subarrays

void printSubarrays(vector<int>arr, int start, int end){
if(end==arr.size()) return;
else if(start>end){
printSubarrays(arr,start,end+1);
}else{
for(int i=start;i<=end;i++){
  cout<<arr[i];
}
cout<<endl;
printSubarrays(arr,start+1,end);
}
}


 *
 * //analogy
 *
 * e.g youre in a trial room of a clothes shop
 * when you take the new cloth you have to remove your current cloth then
 * wear new ones
 *
 * after that to try the next one you have to remove the worn cloth
 * to try on the new cloth
 *
 *
 *
 *
 *                                             f(0,[])
 *
 *                  f(1,[3])                                         f(1,[]) => this function call is executed later hence the prev 3 added has to be removed from the array
 *
 *             f(2,[3,1])     f(2,[3])                        f(2,[1])        f(2,[])
 *
 *f(3,[3,1,2])  f(3,[3,1])  f(3,[3,2]) f(3,[3])         f(3,[1,2]) f(3,[1])    f(3,[2,3]) f(3,[])
 *
 *
 * all last function calls are printed
 *
 * actual code
 *
 * void printAll(int ind,vector<int>&ds,int arr[],int n){
 *      if(ind==n){
 *          for(int i-0;i<ds.length();i++) cout<<ds[i]<<" "
 *
 *      if(ds.size()==0) cout<<{}<<" "   => prints out null set
 *      cout<<endl;
 *      return;
 *    }
 *      //take or pick the particular index into the subsequence
 *
 *      ds.push_back(arr[ind]);
 *
 *      printAll(ind+1,ds,arr,n);
 *
 *  //not pick the particular index into the subequence
 *
 *      ds.pop_back();
 *
 *       printAll(ind+1,ds,arr,n)
 *
 *
 *      T.C: 2^n * n   S.c: O(n)
 *
 *
 *
 *      f(3): max sum you can get if you pick a subsequence with no adjacent from 0-3
 *
 *
 * f(1) max sum you can get if you pick a subsequence from 0-1
 * you can only pick one element so max will be max(A[0],A[1])
 *
 *                      f(3)
 *
 *              f(1)                f(2)
 *
 *          f(-1)   f(0)        f(0)      f(1)
 *
 *
 *
 * f(0)=A[0]    f(1)=A[1]
 *
 */

int maxsumrecursive(int ind,vector<int>&arr){
    if(ind==0|| ind==1) return arr[ind];
    if(ind<0) return 0;
    int pick=maxsumrecursive(ind-2,arr)+arr[ind];
    int notpick=maxsumrecursive(ind-1,arr)+0;
    return max(pick,notpick);
}

//memoization=> top down approach
int maxsumrDP(int ind,vector<int>&arr,vector<int> &dp){
    if(ind==0|| ind==1) return arr[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=maxsumrDP(ind-2,arr,dp)+arr[ind];
    int notpick=maxsumrDP(ind-1,arr,dp)+0;
    return dp[ind] =max(pick,notpick);
}

//tabulation => bottom up approach

int maxsumTabulation(vector<int>&arr){
    int n=arr.size();
    int dp[100]={0};
    //innitializing base conditions
    dp[0]=arr[0];

    for(int i=1;i<n;i++){

        int take=arr[i];
        if(i>1) take+=dp[i-2];
        int nontake=0+dp[i-1];
        dp[i]=max(take,nontake);
    }
}

    //t.c:o(n)  s.c:o(n)

//space optimization

int maxSumSpaceOptimized(vector<int>&arr){
    int n=arr.size();
    int prev=arr[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=arr[i];

        if(i>1) take+=prev2;

        int nottake=0+prev;
        int curri=max(take,nottake);
        prev2=prev;
        prev=curri;
    }
    return prev;
}
