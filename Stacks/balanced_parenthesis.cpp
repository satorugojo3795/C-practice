#include<iostream>
#include<stack>

using namespace std;

bool isBalanced(string s){
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){

            if(st.empty()){
                return false;
            }
            else if((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[')){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";
    string expr3 = "{[}";

    cout << "Expression: " << expr1 << " is " << (isBalanced(expr1) ? "balanced" : "not balanced") << endl;
    cout << "Expression: " << expr2 << " is " << (isBalanced(expr2) ? "balanced" : "not balanced") << endl;
    cout << "Expression: " << expr3 << " is " << (isBalanced(expr3) ? "balanced" : "not balanced") << endl;

    return 0;
}