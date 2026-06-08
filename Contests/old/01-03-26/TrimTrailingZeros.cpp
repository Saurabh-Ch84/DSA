#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
public:
    string trimTrailingVowels(string s) {
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(isVowel(s[i])) s.pop_back();
            else break;
        }
        return s;
    }
};

int main(){

return 0;
}