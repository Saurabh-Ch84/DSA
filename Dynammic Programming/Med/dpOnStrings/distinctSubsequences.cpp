#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int recursion(string &s, string &t,int idxS,int idxT,vector<vector<int>> &dp){
        if(idxT<0) return 1;
        if(idxS<0) return 0;
        if(dp[idxS][idxT]!=-1) return dp[idxS][idxT];
        int take=0,notTake=0;
        notTake=0+recursion(s,t,idxS-1,idxT,dp);
        if(s[idxS]==t[idxT]) take=recursion(s,t,idxS-1,idxT-1,dp);
        return dp[idxS][idxT]=take+notTake; 
    }
public:
    int numDistinct(string s, string t){
        // vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        // return recursion(s,t,s.size()-1,t.size()-1,dp);
        int m=s.length(),n=t.length();
        vector<double> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=m;i++)
        {
            vector<double> temp(n+1,0);
            temp[0]=1;
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1]) temp[j]=dp[j]+dp[j-1];
                else temp[j]=dp[j];
            }
            dp=temp;
        }
        return (int)dp[n];
    }
};

int main(){

return 0;
}