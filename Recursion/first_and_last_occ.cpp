#include<iostream>

using namespace std;

int first_occ(int arr[], int n, int key, int i){
    if(arr[0] == key){
        return i;
    }
    first_occ(arr+1, n-1, key, i+1);
}

int last_occ(int arr[], int n, int key) {
    // Base case: If we have checked all elements
    if (n == 0) {
        return -1; // Key not found
    }

    // Recursive case: Check the last element first
    if (arr[n - 1] == key) {
        return n - 1; // Found the key at the current last position
    }

    // Recur for the remaining part of the array
    return last_occ(arr, n - 1, key);
}

int main(){
    int arr[6] = {1,4,2,4,2,5};
    cout<<first_occ(arr,6,2,0)<<endl;
    cout<<last_occ(arr,6,2);
}