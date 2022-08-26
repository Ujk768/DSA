/**
 *
        0/1 knapsack recursion code

 we will be given two arrays one of weight
  and another of value

  an item can only be included in the knapsack if its weight 
  is less than the weight of the knapsack.

    Choice diagram

    if w1<=W(capacity of the knapsack) => we have 2 choices either 
                include in the knap sack or dont include


        if(W[n-1]<=W){
            //include in the knapsack

        V[n-1] is selected ,then we have to select from the rest
        of the elements in the array.

        since weight is included in the knapsack ,reduce that 
        weight amount.


        // if not included in the knapsack dont reduce the weight
        // we have already made a decision hence choose from remaining elements

         return same values as before just reduce n value by one
        }

    else if w1> W => cant include as weight is greater than
                knapsack capacity.

        // dont include 

        return same values as before just reduce n value by one

    base condition => think of minimum valid input

    wt[] arrays size n=0
    v[] arrays size  n=0
    W: smallest valid =0

    recursion should always call a smaller input value

    we will check from the end if that element is to be included in the
    knapsack or not then reduce the array size.




 * 
 */
#include<iostream>
using namespace std;


int knapsack(int w[],int v[],int W,int n){

    //base condition
    if(n==0 || W== 0) return 0;

    //choice diagram

    if(w[n-1]<=W){
        return max(v[n-1]+knapsack(w,v,W-w[n-1],n-1),knapsack(w,v,W,n-1));
    }else{
        return knapsack(w,v,W,n-1);
    }

}