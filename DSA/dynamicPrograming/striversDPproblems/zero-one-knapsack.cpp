#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 0/1 knapsack
 * 
 * thief goes to steal n items and each item has particluar wirght and value
 * 
 * n=3
 * 
 * wt=>     3    4   5
 * val=>    30  50  60
 * 
 * if bag weigth is 8 then the max value the thief can steal is 90
 *  steal with wiegth 3 => 30
 * steal with wiegth 5 => 60
 * total weight=> 90
 * 
 * greedy approach
 * => picking the most costly item
 * 
 * wt:  5   3   2
* val:  60  30  40

wt=6

val 60 weight=> 5 no more space

pick 30 then pick 40 => total value 70
total weight: 5 

hence greedy wont work as the values are not uniformity is not there

trying out all combinations and take best total value giving value

use recusion and take the max value obtained


rules:
1. express everything in terms on (index,W)

2. explore all possibilities=> pick and not pick
3. max of all possiblilties we can take

    3   2   4
 * 30   40  60


 f(2,6)=> till index 2 what is the max value we can generate
            with weight of bag as 6

        
        f(ind,W){
            //basecase
            if(ind==0){
                if(wt[0]<=W) return arr[0];
                return 0;
            }

            nottake=0+f(ind-1,W);

            take=INT_MIN;

            //check if weight in bag is less than thr weight bag can carry
            
            if(wt[ind]<=W) take=ar[ind]+f(ind,W-wt[ind]);

            return  max(take,nottake);
             
        }
            t.c:O(2^n) s.c:O(n)
 
 
 *      //memoization
        ind,W
        dp[n][w+1]

          f(ind,W){
            //basecase
            if(ind==0){
                if(wt[0]<=W) return arr[0];
                return 0;
            }
            if(dp[ind][w]!=-1) return dp[ind][w];
            nottake=0+f(ind-1,W);

            take=INT_MIN;

            //check if weight in bag is less than thr weight bag can carry
            
            if(wt[ind]<=W) take=ar[ind]+f(ind,W-wt[ind]);

            return dp[ind][w]= max(take,nottake);
             
        }

        t.c: O(n*w)
        sc : O(n*w)
 *
 *
 *      Tabulation
 * 
 *      1. base case
 *      2. changing parameter in nested loop
 *      3. copy the recurrence
 * 
 *     
 * 
 */

int knapsack01Recursive(int ind,int W,vector<int>& weight, vector<int>& value){
    if(ind=0){
        if(weight[0]<W){
            return weight[0];
        }else return 0;
    }
    int notpick=knapsack01Recursive(ind-1,W,weight,value);
    int pick=INT_MIN;
    if(weight[ind]<=W) pick=value[ind]+knapsack01Recursive(ind-1,W-weight[ind],weight,value);
    return max(pick,notpick);
}

int knapsack01DP(int ind,int W,vector<int>& weight, vector<int>& value, vector<vector<int>> & dp){
    if(ind=0){
        if(weight[0]<W){
            return weight[0];
        }else return 0;
    }
    if( dp[ind][W]!=-1) return  dp[ind][W]; 
    int notpick=knapsack01DP(ind-1,W,weight,value,dp);
    int pick=INT_MIN;
    if(weight[ind]<=W) pick=value[ind]+knapsack01DP(ind-1,W-weight[ind],weight,value,dp);
    return dp[ind][W]= max(pick,notpick);
}

int knapsackTabulation(vector<int>weight, vector<int>value,int n,int maxWeight){
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
    for(int W=weight[0];W<=maxWeight;W++) dp[0][W]=value[0];

    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
             int notpick=dp[ind-1][W];
            int pick=INT_MIN;
            if(weight[ind]<=W) pick=value[ind]+dp[ind-1][W-weight[ind]];
            return dp[ind][W]= max(pick,notpick);
        }
    }
    return dp[n-1][maxWeight];
}

int knapsackTabulationSpaceOptimized(vector<int>weight, vector<int>value,int n,int maxWeight){
    vector<int>prev(maxWeight+1,0),curr(maxWeight+1,0);
    

    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
             int notpick=prev[W];
            int pick=INT_MIN;
            if(weight[ind]<=W) pick=value[ind]+prev[W-weight[ind]];
            return curr[W]= max(pick,notpick);
        }
        prev=curr;
    }
    return prev[maxWeight];
}
//the elements only depend on the prev row values and the values on the right of W-weight[ind] are not used
//so we can fill the array from right to left and use only a single array element

int knapsackTabulationSpaceOptimizedFurther(vector<int>weight, vector<int>value,int n,int maxWeight){
    vector<int>prev(maxWeight+1,0);
    

    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
             int notpick=prev[W];
            int pick=INT_MIN;
            if(weight[ind]<=W) pick=value[ind]+prev[W-weight[ind]];
            return prev[W]= max(pick,notpick);
        }
    }
    return prev[maxWeight];
}

int knapsack(vector<int>weight, vector<int>value,int n,int maxWeight){
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
    return knapsack01DP(n-1,maxWeight,weight,value,dp);
}