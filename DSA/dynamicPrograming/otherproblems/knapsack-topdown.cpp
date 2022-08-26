/***
 *  
 *  in recusrion the values which are changing only those varialbes
 *     will be used to make the matrix.
 * 
 *  step 1: initialization. 
 *    
 * step 2:  change recusrive calls to iterative
 * 
 *   
 *  t[n+1][w+1] 
 *  i->n
 * j-> w 
 *  
 * t[i][j]=> when given i items whats the max profit we can fill 
 *      in the knapsack with capacity j. 
 * 
 * t[3][4]=> max value when given 3 elements for weight and value 
 *           with capacity of knapsack 4
 * 
 * our array will start to map from index 1 as 0th index is used for \
 * indexing
 * 
 * ans we will get at t[n][w]
 * 
 * recusive function base condition is
 *  used for top down initialization
 * 
 * n==0 and w==0 return 0.
 * 
 * 
 * n=>i
 * w=>j  
 * 
 * **/

#include<iostream>
using namespace std;

int t[n][w] ;

int w[];
int v[];
//initialization all 0th row and 0th column with 0s
for(int i=0;i<n;i++){
    for(int j=0;j<w;j++){
        if(i==0 || j==0) t[i][j] = 0;
    }
}

//choice diagram
for(int i=1;i<n+1;i++){
    for(int j=1;j<w;j++){
        if(w[i-1]<=j){
            t[i][j]=max(v[i-1]+t[i-1][j-w[i-1]],t[i-1[j]]);
        }else{
            t[i][j]=t[i-1][j];
        }
    }   
}



