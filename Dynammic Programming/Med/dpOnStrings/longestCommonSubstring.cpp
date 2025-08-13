#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int m=s1.length(),n=s2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int maxLen=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    if(dp[i][j]>maxLen) maxLen=dp[i][j];
                }
                else dp[i][j]=0;
            }
        }
        return maxLen;
    }
};

int main(){

return 0;
}