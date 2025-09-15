#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> hashSet;
        for(char letter: brokenLetters)
            hashSet.insert(letter);

        stringstream ss(text);
        string token;
        int count=0;

        while(getline(ss,token,' ')){
            bool isTypable=true;
            for(char letter:token){
                if(hashSet.count(letter)){
                    isTypable=false;
                    break;
                }
            }
            if(isTypable) count++;
        }
        return count;
    }
};

int main(){
    Solution s;
    cout<<s.canBeTypedWords("hello ji kaise ho saare","seyxuo");
return 0;
}