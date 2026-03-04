#include<iostream>
#include<vector>
using namespace std;

string returnHandMaid(string s){
    if(!s.length()) return "";
    s[0]='a'+(s[0]-'A');
    return "Of"+s;
}

int main(){
    cout<<returnHandMaid("Saurabh");
return 0;
}