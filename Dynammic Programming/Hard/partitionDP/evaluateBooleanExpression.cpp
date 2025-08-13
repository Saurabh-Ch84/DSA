#include<iostream>
#include<vector>
using namespace std;

// User function Template for C++
class Solution {
    int recursion(string &s,int i,int j,int isTrue,vector<vector<vector<int>>> &dp)
    {
        if(i>j) return 0;
        if(i==j)
        {
            if(isTrue) return s[i]=='T';
            return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int ways=0;
        for(int k=i+1;k<=j-1;k+=2)
        {
            int leftTrue=recursion(s,i,k-1,1,dp);
            int leftFalse=recursion(s,i,k-1,0,dp);
            int rightTrue=recursion(s,k+1,j,1,dp);
            int rightFalse=recursion(s,k+1,j,0,dp);
            if(s[k]=='&')
            {
                if(isTrue) ways+=leftTrue*rightTrue;
                else ways+=leftFalse*rightFalse+leftFalse*rightTrue+leftTrue*rightFalse;
            }
            else if(s[k]=='|')
            {
                if(isTrue) ways+=leftTrue*rightTrue+leftFalse*rightTrue+leftTrue*rightFalse;
                else ways+=leftFalse*rightFalse;
            }
            else
            {
                if(isTrue) ways+=leftTrue*rightFalse+leftFalse*rightTrue;
                else ways+=leftFalse*rightFalse+leftTrue*rightTrue;
            }
        }
        return dp[i][j][isTrue]=ways;
    }
  public:
    int countWays(string &s) {
        // code here
        int n=s.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return recursion(s,0,n-1,true,dp);
    }
};

int main(){

return 0;
}