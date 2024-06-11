#include<iostream>
using namespace std;
int main()
{
    int x,y;
    cin>>x;
    cin>>y;
    int arr[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
     //11 12 13 23 33 32 31 21 22
    int top=0,left=0,bottom=x-1,right=y-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            cout<<arr[top][i]<<"\t";
        }
        top++;
        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<<"\t";
        }
        right--;
        for(int i=right;i>=left;i--){
            cout<<arr[bottom][i]<<"\t";
        }
        bottom--;
        for(int i=bottom;i>=top;i--){
            cout<<arr[i][left]<<"\t";
        }
        left++;
    }
    return 0;
}