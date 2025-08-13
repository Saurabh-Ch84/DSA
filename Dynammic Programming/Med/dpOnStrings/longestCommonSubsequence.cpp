#include<iostream>
#include<vector>
using namespace std;

class Solution {

public:
    int longestCommonSubsequence1(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<int> dp(n+1,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n+1,0);
            for(int j=1;j<=n;j++){
                if(text2[i]==text1[j-1]) temp[j]=1+dp[j-1];
                else temp[j]=max(temp[j-1],dp[j]);
            }
            dp=temp;
        }
        return dp.back();
    }
    int recursion(string &text1, string &text2,int i1,int i2){
        if(i1<0 || i2<0) return 0;
        if(text1[i1]==text2[i2]) return 1+recursion(text1,text2,i1-1,i2-1);
        return 0+max(recursion(text1,text2,i1,i2-1),recursion(text1,text2,i1-1,i2));
    }
    int longestCommonSubsequence2(string text1, string text2) {
        return recursion(text1,text2,text1.size()-1,text2.size()-1);
    }
    int memo(string &text1, string &text2,int i1,int i2,vector<vector<int>> &dp){
        if(i1<0 || i2<0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(text1[i1]==text2[i2]) return dp[i1][i2]=1+memo(text1,text2,i1-1,i2-1,dp);
        return dp[i1][i2]=0+max(memo(text1,text2,i1,i2-1,dp),memo(text1,text2,i1-1,i2,dp));
    }
    int longestCommonSubsequence3(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return memo(text1,text2,text1.size()-1,text2.size()-1,dp);
    }
    int longestCommonSubsequence4(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int size=dp[n][m];
        string lcs(size,' ');
        cout<<lcs<<endl;
        while(n && m){
            if(text1[n-1]==text2[m-1])
            {
                lcs[size-1]=text1[n-1];
                m--;
                n--;
                size--;
            }
            else{
                if(dp[n][m-1]>=dp[n-1][m]) m--;
                else n--;
            }
        }
        cout<<lcs<<endl;
        return dp.back().back();
    }
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