#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];
    
    cout<<"enter elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max,min;
 
    int i;

    if(n%2==0){
        //we can compare 2 elements by taking first two elements as max and min
        if(arr[0]>arr[1]){
            max=arr[0];
            min=arr[1];
        }else{
            max=arr[1];
            min=arr[0];
        }
        i=2;
    }else{
        max=arr[0];
        min=arr[0];
        i=1;
    }

    while(i<n-1){
        if(arr[i]>arr[i+1]){
            if(arr[i]>max){
                max=arr[i];
            }
            if(arr[i+1]<min){
                min=arr[i+1];
            }
        }else{
              if(arr[i+1]>max){
                max=arr[i+1];
            }
            if(arr[i]<min){
                min=arr[i];
            }
        }
        i+=2;
    }
    cout<<"max element is:"<<max<<endl;
    cout<<"min element is:"<<min<<endl;

    return 0;
}