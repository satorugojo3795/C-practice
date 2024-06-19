#include<iostream>

using namespace std;

void reverse_string(string s){
    if(s.length() == 0){
        return;
    }   
    reverse_string(s.substr(1));
    cout<<s[0];
}
int main(){
    string s;
    s = "saksham";
    reverse_string(s);
}