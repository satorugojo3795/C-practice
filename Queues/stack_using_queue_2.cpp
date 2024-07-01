#include<iostream>
#include<queue>
#include<algorithm>

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
        q1.push(x);
        N++;
    }

    int pop(){
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front(); 
        q1.pop();
        swap(q1,q2);
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
    s.display();
    s.pop();
    s.display();
    s.size();
    return 0;
}