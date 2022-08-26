#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            if(i!=n/i) cnt+=2;
        }else cnt+=1;
    }
    cout<<cnt;

}