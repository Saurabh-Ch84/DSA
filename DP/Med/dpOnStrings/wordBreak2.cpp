#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    //better
    void recursion(string &s,vector<string> &res,string &sentence,int i,int n,
                    int maxLen,unordered_set<string> &hashSet)
    {
        if(i>=n){
            res.push_back(sentence);
            return ;
        }
        for(int len=1;len<=min(n-i,maxLen);len++){
            string str=s.substr(i,len);
            if(hashSet.count(str)){
                string temp=sentence;
                if(sentence.empty()==false) sentence.push_back(' ');
                sentence+=str;
                recursion(s,res,sentence,i+len,n,maxLen,hashSet);
                sentence=temp;
            }
        }
    }

    //optimal
    vector<string> memoization(string &s,unordered_set<string> &hashSet,
                            unordered_map<string,vector<string>> &dp,int maxLen)
    {
        if(s.empty()) return {""};
        if(dp.count(s)) return dp[s];
        vector<string> result;
        int currLen=s.length();
        for(int len=1;len<=min(currLen,maxLen);len++){
            string currWord=s.substr(0,len);
            if(hashSet.count(currWord)){
                string remWord=s.substr(len);
                vector<string> remResult=memoization(remWord,hashSet,dp,maxLen);
                for(string &word:remResult){
                    string toAdd=currWord+(word.empty()?"":" ")+word;
                    result.push_back(toAdd);
                }
            }
        }
        return dp[s]=result;
    }
public:
    vector<string> wordBreak1(string s, vector<string>& wordDict) {
        unordered_set<string> hashSet;
        int n=s.length(),maxLen=0;
        for(string &word:wordDict){
            int len=word.length();
            maxLen=max(maxLen,len);
            hashSet.insert(word);
        }
        string sentence="";
        vector<string> res;
        recursion(s,res,sentence,0,n,maxLen,hashSet);
        return res;
    }

    vector<string> wordBreak2(string s, vector<string>& wordDict) {
        unordered_set<string> hashSet;
        int maxLen=0;
        for(string &word:wordDict){
            int len=word.length();
            maxLen=max(maxLen,len);
            hashSet.insert(word);
        }
        unordered_map<string,vector<string>> dp;
        return memoization(s,hashSet,dp,maxLen);
    }
};

void print(vector<string> lines){
    for(string &line:lines)
        cout<<line<<endl;
}

int main(){
    Solution1 s;
    vector<string> wordDict1={"man","go","ice","cream","icecream","mango"};
    string word1="mangoicecream";
    print(s.wordBreak2(word1,wordDict1));
return 0;
}