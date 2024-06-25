#include<iostream>

using namespace std;

#define n 20
class queue{
    int* arr;
    int front;
    int back;

    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x){
        if(back==n-1){
            cout<<"queue is full!"<<endl;
        }
        else{
            back++;
            arr[back] = x;
            if(front==-1){
                front++;
            }
        }
    }

    int pop(){
        if(front == -1 || front>back){
            cout<<"queue is empty!"<<endl;
        }
        else{
            int x = arr[front];
            front++;
            return x;
        }
    }

    bool isEmpty(){
        if(front == -1 || front>back){
            return true;
        }
        return false;
    }

    int peek(){
        if(front == -1 || front>back){
            cout<<"queue is empty!"<<endl;
            return -1;
        }
        return arr[front];
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<endl<<q.peek()<<endl;
    return 0;
}