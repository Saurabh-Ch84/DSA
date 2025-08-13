#include<iostream>
#include<vector>
using namespace std;

class Solution {
    // void print(vector<vector<bool>> a){
    //  for(vector<bool> &v:a){
    //      for(bool val:v)
    //          cout<<val<<" ";
    //      cout<<endl;
    //  }
    // }
    bool recursion(string &s, string &p, int i, int j) {
    if (i < 0 && j < 0) return true;
    if (j < 0 && i >= 0) return false;
    if (i < 0 && j >= 0) {
        for (int k = 0; k <= j; k++)
            if (p[k] != '*') return false;
        return true;
    }
    if (p[j] == s[i] || p[j] == '?')
        return recursion(s, p, i - 1, j - 1);
    if (p[j] == '*')
        return recursion(s, p, i, j - 1) || recursion(s, p, i - 1, j);
    return false;
}
public:
    bool isMatch(string s, string p) {
        // return recursion(s,p,s.length()-1,p.length()-1);
        int m=s.size(),n=p.size();
        // vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        // dp[0][0]=true;
        // for(int j=1;j<=n;j++)
        //     if(p[j-1]=='*') dp[0][j]=dp[0][j]|dp[0][j-1];
        // for(int i=1;i<=m;i++){
        //     dp[i][0]=false;
        //     for(int j=1;j<=n;j++){
        //         if(p[j-1]=='*' && j-1==0) dp[i][j]=true;
        //         else if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
        //         else if(p[j-1]=='*') dp[i][j]=dp[i-1][j-1]|dp[i][j-1]|dp[i-1][j];
        //         else dp[i][j]=false;
        //     }
        // }
        // // print(dp);
        // return dp[m][n];
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int j=1;j<=n;j++)
            if(p[j-1]=='*') dp[j]=dp[j]|dp[j-1];
        for(int i=1;i<=m;i++){
            vector<bool> temp(n+1,false);
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*' && j-1==0) temp[j]=true;
                else if(s[i-1]==p[j-1] || p[j-1]=='?') temp[j]=dp[j-1];
                else if(p[j-1]=='*') temp[j]=temp[j-1]|dp[j];
                else temp[j]=false;
            }
            dp=temp;
        }
        return dp[n];
    }
};

int main(){

return 0;
}