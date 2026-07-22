#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<int> dp(m+1,0);
        for(int j=0;j<m;j++){
            dp[j+1]=j+1;
        }
        for(int i=1;i<=n;i++){
            vector<int> temp(m+1,0);
            temp[0]=1+dp[0];
            char ch1=word1[i-1];
            for(int j=1;j<=m;j++){
                char ch2=word2[j-1];
                if(ch1==ch2) temp[j]=dp[j-1];
                else temp[j]=1+min({temp[j-1],dp[j-1],dp[j]});
            }
            dp=temp;
        }
        return dp[m];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) dp[i][0]=i;

        for(int j=0;j<=n;j++) dp[0][j]=j;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word2[i - 1] == word1[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
        }
        return dp[m][n];
    }
};

int main(){

return 0;
}