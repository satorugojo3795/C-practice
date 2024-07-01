#include<iostream>
#include<stack>

using namespace std;

int main(){
    int arr[] = {6, 8, 0, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int* nxtGreater = new int[size];

    stack<int> s;
    // while loop
    for(int i=size-1; i>=0; i--){
        //while loop
        while(!s.empty() && arr[s.top()] <= arr[i]){
        s.pop();
        }
        // if else
        if(s.empty()){
            nxtGreater[i] = -1;
        }
        else{
            nxtGreater[i] = arr[s.top()];
        }
        //push the element
        s.push(i);
    }
    for(int i=0;i<size;i++){
        cout<<endl<<nxtGreater[i]<<" ";
    }
    return 0;
}