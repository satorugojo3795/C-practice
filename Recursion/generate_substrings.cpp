#include<iostream>

using namespace std;

void generate_substrings(string s, string ans){

    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }

    string ros = s.substr(1);
    generate_substrings(ros,ans);
    generate_substrings(ros,ans+s[0]);

}

int main(){
    string str, ans;
    str = "ABC";
    ans = "";
    generate_substrings(str,ans);
    return 0;
}