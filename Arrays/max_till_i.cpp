#include<iostream>
using namespace std;

int max_num(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max = arr[0];
    for(int i=0;i<n;i++){
        max = max_num(arr[i],max);
        cout<<max;
    }
    return 0;
}