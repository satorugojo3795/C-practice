#include<iostream>

using namespace std;

void decreasing(int n){
    if(n==0){
        cout<<0<<endl;
        return;
    }
    cout<<n<<" ";
    decreasing(n-1);
}

void increasing(int n){
    
    if(n==0){
        cout<<n<<" ";
        return;
    }
    increasing(n-1);
    cout<<n<<" ";
}

int main(){
    int n;
    cout<<"enter a number";
    cin>>n;
    decreasing(n);
    increasing(n);
}