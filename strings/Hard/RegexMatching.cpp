#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    bool memoization(string s,string p,unordered_map<string,bool> &dp){
        if(p.empty()) return s.empty();
        string key=s+'#'+p;
        if(dp.count(key)) return dp[key];
        bool firstMatch=false;
        firstMatch=!s.empty() && (s[0]==p[0] || p[0]=='.');
        if(p.length()>=2 && p[1]=='*'){
            bool notTake=memoization(s,p.substr(2),dp);
            bool take=(firstMatch && memoization(s.substr(1),p,dp));
            return dp[key]= notTake || take;
        }
        return dp[key]=(firstMatch && memoization(s.substr(1),p.substr(1),dp));
    }
public:
    bool isMatch(string s, string p) {
        unordered_map<string,bool> dp;
        return memoization(s,p,dp);
    }
};

class Solution2 {
    bool memoization(string &s,string &p,int i,int j,int n,int m,vector<vector<int>> &dp){
        if(j==m) return i==n;
        if(dp[i][j]!=-1) return dp[i][j];
        bool firstMatch=false;
        firstMatch= (i<n) && (s[i]==p[j] || p[j]=='.');
        if(j<m-1 && p[j+1]=='*'){
            bool notTake=memoization(s,p,i,j+2,n,m,dp);
            bool take= firstMatch && memoization(s,p,i+1,j,n,m,dp);
            return dp[i][j]= take || notTake;
        }
        return dp[i][j]= firstMatch && memoization(s,p,i+1,j+1,n,m,dp);
    }
public:
    bool isMatch(string s, string p){
        int n=s.length(),m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return memoization(s,p,0,0,n,m,dp);
    }
};

int main(){
    Solution1 s1;
    Solution2 s2;
    cout<<s1.isMatch("ab",".*b")<<endl;
    cout<<s2.isMatch("ab",".*b")<<endl;
return 0;
}