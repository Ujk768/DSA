/***
 *  input array given and sum value given.
 *  find if such a subset is present in the input array 
 *  which is equal to the given sum
 * 
 * 
 *  Similarity to knapsack
 * 
 *  in knapsack we have a choice whether to include a particular
 *  element in the knapsack or not.
 * 
 *  Similarly here we also get to choose whether a number should
 * be included in the subset or not.
 * 
 * 
 * e.g arr: 2 3 7 8 10
 *      sum: 11 
 *  answer:{8,3} True
 * 
 *  whenever we are given numbers with a choice of
 *  including it or not and we are given a max choice
 * W then its a knapsack problem.
 * 
 * Initialization 
 * 
 *  t[size+1][sum+1]
 * 
 * t[6][12]
 * 
*   i=> i is the array size
    j=> j is the Sum to be found.


    each subproblem states that for a given number of elements
    is the given subset sum possible or not.

    if sum is 0 then its always possible to form a subset because
    nullset will always have sum 0. hence TRUE

    for the rows we have to find sum of a particular value but we are 
    given no array elements hence its all initialized to false.


    in knapsack we only consider weight array if only one array is given

    in this we arestoring true false so we use OR instead of max


    if(arr[i-1]<=j){
 
        t[i][j]= t[i][j-ar[i-1]] || t[i-1][j]

    }else t[i][j] = t[i-1][j];
 * 
 * 
 * **/


int t[size+1][sum+1];

for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
        if(i==0) t[i][j]=false;
        if(j==0) t[i][j]=true;
    }
}

for(int i=1;i<n;i++) {
    for(int j=1; j<n; j++) {
         if(arr[i-1]<=j)t[i][j]= t[i][j-ar[i-1]] || t[i-1][j]
         else t[i][j] = t[i-1][j];
    }
}

return t[size][sum]; //this will be the final answer