#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

string simplify_path(string s) {
    stack<string> st;
    stringstream ss(s);
    string token;
    
    // Split input string by '/'
    while (getline(ss, token, '/')) {
        if (token == "" || token == ".") {
            // Ignore empty tokens and "."
            continue;
        } else if (token == "..") {
            // Handle ".." by popping from stack if stack is not empty
            if (!st.empty()) {
                st.pop();
            }
        } else {
            // Otherwise, push valid directory names onto stack
            st.push(token);
        }
    }
    
    // Construct simplified path from stack
    vector<string> dirs;
    while (!st.empty()) {
        dirs.push_back(st.top());
        st.pop();
    }
    
    // If no directories found, return "/"
    if (dirs.empty()) {
        return "/";
    }
    
    // Build simplified path from directories
    stringstream result;
    for (int i = dirs.size() - 1; i >= 0; --i) {
        result << "/" << dirs[i];
    }
    
    return result.str();
}

int main() {
    string s = "/..//home/";
    cout << simplify_path(s) << endl;  // Output: "/home"
    
    s = "/a/./b/.../../c/";
    cout << simplify_path(s) << endl;  // Output: "/c"
    
    s = "/home//foo/";
    cout << simplify_path(s) << endl;  // Output: "/home/foo"
    
    s = "/../";
    cout << simplify_path(s) << endl;  // Output: "/"
    
    s = "/a/b/c";
    cout << simplify_path(s) << endl;  // Output: "/a/b/c"
    
    return 0;
}
