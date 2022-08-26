#include<iostream>

#include<vector>

using namespace std;

void swap(int &a,int &b){
    int tmp=a;
    a=b;
    b=tmp;

}

vector<int>bubblesort(vector<int>&A){
    int n=A.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n-i+1;j++){
            if(A[i]>A[j]){
                swap(A[i],A[j]);
            }
        }
    }

}