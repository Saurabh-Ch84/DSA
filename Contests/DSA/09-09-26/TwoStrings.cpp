#include<bits/stdc++.h>
using namespace std;

string twoStrings(string s1, string s2) {
    vector<int> letters(26,0);
    for(const char &letter: s1){
        int idx=letter-'a';
        letters[idx]++;
    }
    for(const char &letter: s2){
        int idx=letter-'a';
        if(letters[idx]) return "YES";
    }
    return "NO";
}

int main(){

return 0;
}