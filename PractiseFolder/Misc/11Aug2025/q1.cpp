#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Problem:
    You are given two bags containing p1 and p2 balls respectively. Your goal is to make the number of balls in both bags equal using the minimum number of operations.

You can perform the following operations:
1.Remove one ball from any bag.
2.Add one ball to any bag.
3.Move one ball from one bag to the other.

Task:
    Write a function minOperations(p1: int, p2: int) -> int that returns the minimum number of operations required to make the number of balls in both bags equal.
*/


class Solution{
    int recursion(int a,int b,vector<vector<int>> &dp){
        if(a==b) return 0;
        if(dp[a][b]!=-1) return dp[a][b];
        bool A=(a>b);
        
        int remA=1e7,remB=1e7;
        if(A) remA=1+recursion(a-1,b,dp);
        else remB=1+recursion(a,b-1,dp);
        
        int addA=1e7,addB=1e7;
        if(!A) addA=1+recursion(a+1,b,dp);
        else addB=1+recursion(a,b+1,dp);
        
        int movAB=1e7,movBA=1e7;
        if(abs(a-b)!=1){
            if(A) movAB=1+recursion(a-1,b+1,dp);
            else movBA=1+recursion(a+1,b-1,dp);
        }
        return dp[a][b]=min({remA,remB,addA,addB,movAB,movBA});
    }
        public:
    int findMinStepsToMakeBagsEqual(int a,int b){
        // vector<vector<int>> dp(10001,vector<int>(10001,-1));
        // return recursion(a,b,dp);
        return (abs(a-b)+1)/2;
    }
};

int main(){
    int p1,p2;
    cout<<"Enter p1 and p2 respectively: ";
    cin>>p1>>p2;
    Solution s;
    cout<<s.findMinStepsToMakeBagsEqual(p1,p2)<<endl;
return 0;
}