#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool recursion(unordered_set<string> &hashSet,string word,unordered_map<string,bool> &dp){
        if(dp.count(word)) return dp[word];
        int n=word.length();
        for(int i=0;i<n;i++){
            string prefix=word.substr(0,i+1);
            if(hashSet.count(prefix)){
                string suffix=word.substr(i+1);
                if(hashSet.count(suffix) || recursion(hashSet,suffix,dp))
                    return dp[word]=true;
            }
        }
        return dp[word]=false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> hashSet;
        for(string &word:words)
            hashSet.insert(word);
            
        unordered_map<string,bool> dp;
        vector<string> ans;
        for(string &word:words){
            if(recursion(hashSet,word,dp))
                ans.push_back(word);
        }
        return ans;
    }
};

int main(){

return 0;
}