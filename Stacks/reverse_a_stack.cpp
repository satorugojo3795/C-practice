#include<iostream>
#include<stack>

using namespace std;

void insert_at_bottom(stack<int>& st, int x){
    if(st.empty()){
        st.push(x);
    }
    else{
        int a = st.top();
        st.pop();
        insert_at_bottom(st,x);
        st.push(a);
        return;
    }
}
void reverse_stack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int x = st.top();
    st.pop();
    reverse_stack(st);
    insert_at_bottom(st, x);
    return;
}


int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse_stack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}