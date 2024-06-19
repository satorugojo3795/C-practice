#include<iostream>

using namespace std;

int n_power_p(int n,int p){
    if(p==0){
        return 1;
    }
    return n*n_power_p(n,p-1);
}
int main(){
    int n,p;
    cout<<"enter a number"<<endl;
    cin>>n;
    cout<<"enter power"<<endl;
    cin>>p;
    cout<<n_power_p(n,p);
    return 0;
}