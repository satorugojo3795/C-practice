#include<iostream>
#include<stack>

using namespace std;

int* stock_span(int arr[], int n){

    stack<int> prev_high;
    int* stock = new int[n];
    stock[0] = 1;
    prev_high.push(0);
    for(int i=1;i<n;i++){
        while(!prev_high.empty() && arr[prev_high.top()] < arr[i]){
            prev_high.pop();
        }
        if(prev_high.empty()){
            stock[i] = i+1;
        }
        else{

            stock[i] = i - prev_high.top();
        }
        prev_high.push(i);
    }

    return stock;

}
int main() {
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* result = stock_span(arr, n);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;
    return 0;
}