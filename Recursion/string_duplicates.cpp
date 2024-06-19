#include<iostream>

using namespace std;


string removeDuplicates(string s){
    if(s.length() == 1){
        return s;
    }
    string replace = removeDuplicates(s.substr(1));
    if(s[0] == replace[0]){
        return replace;
    }
    else{
        return s[0] + replace;
    }
}

int main(){

    string s;
    s = "fertddddw";
    cout<<removeDuplicates(s);
    return 0;
}

