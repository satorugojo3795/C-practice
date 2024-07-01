#include <iostream>
#include <stack>

using namespace std;

int* next_smaller_right(int arr[], int n) {
    int* nxtSmallerRight = new int[n];
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            nxtSmallerRight[i] = n;
        } else {
            nxtSmallerRight[i] = s.top();
        }
        s.push(i);
    }

    return nxtSmallerRight;
}

int* next_smaller_left(int arr[], int n) {
    int* nxtSmallerLeft = new int[n];
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            nxtSmallerLeft[i] = -1;
        } else {
            nxtSmallerLeft[i] = s.top();
        }
        s.push(i);
    }

    return nxtSmallerLeft;
}

int max_rectangular_area(int arr[], int n) {
    int* nxtSmallerRight = next_smaller_right(arr, n);
    int* nxtSmallerLeft = next_smaller_left(arr, n);
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int width = nxtSmallerRight[i] - nxtSmallerLeft[i] - 1;
        int area = arr[i] * width;
        if (area > maxArea) {
            maxArea = area;
        }
    }

    delete[] nxtSmallerRight;
    delete[] nxtSmallerLeft;

    return maxArea;
}

int main() {
    int arr[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Max Rectangular Area: " << max_rectangular_area(arr, n) << endl;
    return 0;
}
