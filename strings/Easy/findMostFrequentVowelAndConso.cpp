#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
public:
    int maxFreqSum(string s) {
        int vowelFreq=0,consoFreq=0,n=s.length();
        vector<int> alphabet(26,0);
        for(int i=0;i<n;i++){
            char letter=s[i];
            alphabet[letter-'a']++;
            if(isVowel(letter))
                vowelFreq=max(vowelFreq,alphabet[letter-'a']);
            else 
                consoFreq=max(consoFreq,alphabet[letter-'a']);
        }
        return vowelFreq+consoFreq;
    }
};

int main(){
    Solution s;
    cout<<s.maxFreqSum("saurabhchowrasiaishere");
return 0;
}