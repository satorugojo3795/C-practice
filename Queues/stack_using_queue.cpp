#include<iostream>
#include<queue>
#include<algorithm>


// in thisimplementation the push operation is costlier than pop operation
using namespace std;

class stack{
    int N;
    queue<int> q1;
    queue<int> q2;

    
    public:

    stack(){
        N = 0;
    }

    void push(int x){
        if(q1.empty() && q2.empty()){
            q1.push(x);
            N++;
            // swap(q1,q2);
        }
        else{
            q2.push(x);
            N++;
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1,q2);
        }
    }

    int pop(){
        if(q1.empty() && q2.empty()){
            cout<<"empty stack"<<endl;
            return -1;
        }
        int x = q1.front();
        q1.pop();
        N--;
        return x;
    }

    int size(){
        return N;
    }

    void display(){
        while(!q1.empty()){
            cout<<q1.front()<<" ";
            int x = q1.front();
            q2.push(x);
            q1.pop();
        }
        swap(q1,q2);
        cout<<endl;
    }
};

int main(){

    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s.pop();
    s.display();
    cout<<s.size();
    return 0;
}