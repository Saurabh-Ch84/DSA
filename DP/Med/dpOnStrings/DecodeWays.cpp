#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int recursion(int i,int n,string &s,vector<int> &dp){
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];
        int take1=0,take2=0;
        if(s[i]!='0') 
            take1=recursion(i+1,n,s,dp);
        if(s[i]!='0' && i<n-1 && s.substr(i,2)<="26") 
            take2=recursion(i+2,n,s,dp);
        return dp[i]=take1+take2;
    }
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,-1);
        return recursion(0,n,s,dp);
    }
};

class Solution {
    int recursion(string &num,int i,int n){
        if(i==n) return 1;
        if(num[i]=='0') return 0;
        int count=0;
        count+=recursion(num,i+1,n);
        if(i+1<n){
            int number=stoi(num.substr(i,2));
            if(number>=10 && number<=26)
                count+=recursion(num,i+2,n);
        }
        return count;
    }

    int memoization(string &num,int i,int n,vector<int> &dp){
        if(i==n) return 1;
        if(num[i]=='0') return dp[i]=0;
        if(dp[i]!=-1) return dp[i];
        int count=0;
        count+=memoization(num,i+1,n,dp);
        if(i+1<n){
            int number=stoi(num.substr(i,2));
            if(number>=10 && number<=26)
                count+=memoization(num,i+2,n,dp);
        }
        return dp[i]=count;
    }

public:
    int numDecodings(string s){
        int n=s.size();
        vector<int> dp(n,-1);
        return memoization(s,0,n,dp);
    }
};

int main(){

return 0;
}