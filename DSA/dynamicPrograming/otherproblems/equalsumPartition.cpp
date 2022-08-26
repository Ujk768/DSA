/**
 * Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.
Examples:

arr[] = {1, 5, 11, 5}
Output: true 
The array can be partitioned as {1, 5, 5} and {11} 
 * 
 * 
 * Just return true or false 
 * 
 * firstly its possible to divide into equal sum only if
 * sum of all elements is even.
 * 
 * sum of all elements is 22.
 * 
 * we have to find a partition with sum 11(sum/2)
 * 
 * this is now equal to equal sum partition 
 * 
 * if sum== odd return false.
 *
 * 
 * subsetsumproblem(arr,sum/2);
 * 
 * 
 */

int sum=0;
for(int i=0; i<n;i++){
    if(sum%2!=0){
        return false;
    }else if(sum%2==0){
        return subsetsum(arr,sum/2);
}
}



