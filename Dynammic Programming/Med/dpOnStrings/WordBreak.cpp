#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool memoization(string &s,int i,int j,unordered_set<string> &hashSet,
                    int n,vector<vector<int>> &dp)
    {
        if(j>=n && i>=n) return true;
        if(j>=n || i>=n ) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        string str=s.substr(i,j-i+1);
        bool take=false,notTake=false;
        notTake=memoization(s,i,j+1,hashSet,n,dp);
        if(hashSet.count(str))
            take=memoization(s,j+1,j+1,hashSet,n,dp);
        return dp[i][j]=take|notTake;
    }
        public:
    bool wordBreak2(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> hashSet;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(string &word:wordDict)
            hashSet.insert(word);
        return memoization(s,0,0,hashSet,n,dp);
    }

    bool recursion(string &s,int i,int n,unordered_set<string> &hashSet,vector<int> &dp){
        if(i>=n) return true;
        if(dp[i]!=-1) return dp[i];
        for(int len=1;len<=n-i;len++){
            if(hashSet.count(s.substr(i,len)) && recursion(s,i+len,n,hashSet,dp))
                return dp[i]=true;
        }
        return dp[i]=false;
    } 
    
    bool wordBreak3(string s, vector<string>& wordDict) {
        unordered_set<string> hashSet(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<int> dp(n,-1);
        return recursion(s,0,n,hashSet,dp);
    }

    bool wordBreak1(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[n]=true;
        for(int i=n-1;i>-1;i--){
            int len=n-i;
            for(string &word:wordDict){
                int wordLen=word.length();
                if(len>=wordLen){
                    if(s.substr(i,wordLen)==word && dp[i+wordLen]){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};

int main(){
    Solution s;
    vector<string> words1={"leet","code"};
    cout<<s.wordBreak2("leetcode",words1);
return 0;
}