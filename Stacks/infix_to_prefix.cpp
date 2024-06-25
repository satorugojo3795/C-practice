#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to reverse a string
string reverseString(const string &str) {
    string reversedStr;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversedStr += str[i];
    }
    return reversedStr;
}

// Function to get precedence of operators
int prec(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return -1;
    }
}

// Function to convert infix expression to prefix
string infix_to_prefix(string s) {
    stack<char> st;
    string res;

    // Reverse the infix expression
    s = reverseString(s);

    // Swap '(' with ')' and vice versa
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    // Convert the modified infix expression to postfix
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            res += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        } else {
            while (!st.empty() && prec(st.top()) > prec(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // Pop all the operators from the stack
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    // Reverse the postfix expression to get the prefix expression
    res = reverseString(res);
    return res;
}

int main() {
    string infix = "(a-b/c)*(a/k-l)";
    cout << "Infix: " << infix << endl;
    string prefix = infix_to_prefix(infix);
    cout << "Prefix: " << prefix << endl;
    return 0;
}
