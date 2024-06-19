#include<iostream>

using namespace std;

string replacePi(string s){
    if(s.length()==1){
        return s;
    }
    if(s[0]=='p' && s[1]=='i'){
        s =  s.replace(0,2,"3.14");
    }
    return s[0]+replacePi(s.substr(1));
}

int main(){
    string s = "pippppafepiadee";
    cout<<replacePi(s);
    return 0;
}