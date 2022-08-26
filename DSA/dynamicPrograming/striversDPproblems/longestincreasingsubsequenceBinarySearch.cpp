#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * [1,7,8,4,5,6,-1,9]
 * 
 * go across all the elements and form subsequences
 * 
 * [1,7,8,4,5,6,-1,9]
 * 
 * stored arr
 * 
 * 1,7,8 
 * put 4 in its position
 * 
 * 1,4,8 
 * 
 * put 5 in its position
 * 1,4,5
 * 
 * put 6 in its postion
 * 1,4,6
 * 
 * put -1 in its postion in stored arr
 * -1,4,6
 * put 9 in ints postion 
 * -1,4,6,9
 * 
 * this does not give us the subsequnce but it does give us the correct length of the subsequence
 * 
 * binary search will beused to inser the lement at the correct position
 * 
 * lower_bound() function in c++ will give you the index of arr[i] if exist or ind of first elemnt greater than arr[i] 
 */

int longestIncresingSubsequnce(int arr[],int n){
    vector<int>temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        //.back() return reference to last elemnt of the vector
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }
        else{
            
            int ind=lower_bound(temp.begin(),temp.end(),arr[i]);
            
            temp[ind]=arr[ind];
        }
    }
    return temp.size();

}