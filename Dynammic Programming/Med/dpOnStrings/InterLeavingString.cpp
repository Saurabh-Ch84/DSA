#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool memoization(string &s1, string &s2, string &s3,vector<vector<int>> &dp,int i,int j,int n,int m){
        if(i==n && j==m) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool take1=false,take2=false;
        if(i<n && s1[i]==s3[i+j])
            take1=memoization(s1,s2,s3,dp,i+1,j,n,m);
        if(take1) return dp[i][j]=true;
        if(j<m && s2[j]==s3[i+j])
            take2=memoization(s1,s2,s3,dp,i,j+1,n,m);
        return dp[i][j]=take1|take2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length();
        if(n+m != s3.length())
            return false;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return memoization(s1,s2,s3,dp,0,0,n,m);
    }
};

int main(){

return 0;
}