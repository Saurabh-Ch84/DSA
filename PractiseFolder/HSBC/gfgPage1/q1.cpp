#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    q2. You have given string str containing 0 and 1. You have to remove either of the substrings 
    01 or 10 and print the minimum length of the resultant string.eg input-1010 output-0.
*/

class Solution {
    int memoization(int N,vector<int> &dp){
        if(N==1) return 0;
        if(dp[N]!=-1) return dp[N];
        int divBy2=1e9,divBy3=1e9;
        int minus1=1+memoization(N-1,dp);
        if(N%2 == 0) divBy2=1+memoization(N/2,dp);
        if(N%3 == 0) divBy3=1+memoization(N/3,dp);
        return dp[N]=min({minus1,divBy2,divBy3});
    }
  public:
    int minSteps(int N){
        // Your code goes here
        vector<int> dp(N+1,-1);
        return memoization(N,dp);
    }
    //q2
    int countFinalStringLength(string str){
        int count0=count(str.begin(),str.end(),'0');
        int count1=count(str.begin(),str.end(),'1');
        return abs(count0-count1);
    }
};


int main(){
    Solution s;
    cout<<s.minSteps(101)<<endl;
    cout<<s.countFinalStringLength("10100011");
return 0;
}