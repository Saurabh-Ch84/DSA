#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool recursion(string &s,string &p,int i,int j,int n,int m,vector<vector<int>> &dp){
        if(j==m) return i==n;
        if(dp[i][j]!=-1) return dp[i][j];
        bool firstMatch=false;
        firstMatch= (i<n) && (s[i]==p[j] || p[j]=='.');
        if(j<m-1 && p[j+1]=='*'){
            bool notTake=recursion(s,p,i,j+2,n,m,dp);
            bool take= firstMatch && recursion(s,p,i+1,j,n,m,dp);
            return dp[i][j]= take || notTake;
        }
        return dp[i][j]=firstMatch && recursion(s,p,i+1,j+1,n,m,dp);
    }
public:
    bool isMatch(string s, string p){
        int n=s.length(),m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return recursion(s,p,0,0,n,m,dp);
    }
};

int main(){

return 0;
}