#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isVowel(char ch){
        return (ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || 
                ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U');
    }
public:
    string sortVowels(string s) {
        int n=s.length();
        unordered_map<char,int> hashMap;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])) hashMap[s[i]]++;
        }
        if(hashMap.empty()) 
            return s;

        string vowels="AEIOUaeiou";
        int left=0,right=0;
        while(left<n && right<10)
        {
            if(isVowel(s[left]))
            {
                while(right<10 && hashMap[vowels[right]]==0) 
                    right++;
                if(right<10)
                {
                    s[left]=vowels[right];
                    hashMap[vowels[right]]--;
                }
            }
            left++;
        }

        return s;
    }
};

int main(){
    Solution s;
    cout<<s.sortVowels("SaurAbh ChOwrasiA")<<endl;
return 0;
}