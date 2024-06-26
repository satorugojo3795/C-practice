#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> s1;

    public:
    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(s1.empty()){
            cout<<"empty queue"<<endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if(s1.empty()){
            return x; 
        }
        int item = pop();
        s1.push(x);
        return item;
        
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<endl<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    return 0;
}