#include<iostream>
using namespace std;

class Solution {
    bool isVowel(string s){
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                return true;
        }
        return false;
    }
public:
    bool doesAliceWin(string s) {
        return isVowel(s);
    }
};

int main(){
    Solution s;
    cout<<s.doesAliceWin("saurabh");
return 0;
}