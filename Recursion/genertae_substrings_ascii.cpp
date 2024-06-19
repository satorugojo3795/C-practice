#include<iostream>
#include<string>

using namespace std;

void generate_substrings(string s, string ans){

    if(s.length() == 0){
        cout<<endl<<ans<<endl;
        return;
    }

    string ros = s.substr(1);
    generate_substrings(ros,ans);
    generate_substrings(ros,ans+s[0]);
    generate_substrings(ros,ans+to_string(static_cast<int>(s[0])));
}

int main(){
    string str, ans;
    str = "AB";
    ans = "";
    generate_substrings(str,ans);
    return 0;
}