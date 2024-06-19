#include<iostream>

using namespace std;

 string move_x_to_end(string s){

     /**
     * Recursively moves all occurrences of 'x' to the end of the string.
     *
     * @param s the input string
     *
     * @return the modified string with 'x' moved to the end
     *
     * @throws None
     */

    if(s.length() == 1){
        return s;
    }
    string replace = move_x_to_end(s.substr(1));
    if(s[0] == 'x'){
        return replace + s[0];
    }
    else{
        return s[0] + replace;
    }

 }

int main(){
    string s;
    s = "axaeinfxxiaoef";
    cout<<move_x_to_end(s);
    return 0;
}