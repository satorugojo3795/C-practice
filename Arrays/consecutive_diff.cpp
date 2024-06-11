#include<iostream>
using namespace std;
int max(int a, int b){
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
    int diff = arr[1]-arr[0];
    int curr_len = 2;
    int max_len = 2;   //1 2 3 4 5
    for(int i=2;i<n;i++){
        if(arr[i]-arr[i-1] == diff){    
            curr_len++;
            max_len = max(max_len,curr_len);
        }
        else{
            diff = arr[i]-arr[i-1];
            curr_len = 2;
        }
    }
    cout<<"max_len \t"<<max_len;
    return 0;
}
