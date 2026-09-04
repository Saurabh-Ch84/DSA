#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution1 {
    int dp[101][101];
    bool recursion(int i,int j,int n1,int n2,int m,string &s1,string &s2,string &s3){
        if(i==n1 && j==n2 && i+j==m) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        bool take1=0, take2=0;
        if(i<n1 && s1[i]==s3[i+j]) take1=recursion(i+1,j,n1,n2,m,s1,s2,s3);
        if(take1) return dp[i][j]=1;
        if(j<n2 && s2[j]==s3[i+j]) take2=recursion(i,j+1,n1,n2,m,s1,s2,s3);
        if(take2) return dp[i][j]=1;
        return dp[i][j]=0;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size(), m=s3.size();
        if(n1+n2!=m) return 0;
        memset(dp,-1,sizeof(dp));
        return recursion(0,0,n1,n2,m,s1,s2,s3);
    }
};

class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size(), m=s3.size();
        if(n1+n2!=m) return 0;
        int dp[101][101];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int j=1;j<=n2;j++){
            if(dp[0][j-1] && s2[j-1]==s3[j-1]) dp[0][j]=1;
            else break;
        }
        for(int i=1;i<=n1;i++){
            if(dp[i-1][0] && s1[i-1]==s3[i-1]) dp[i][0]=1;
            else break;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                bool take1=0, take2=0;
                if(s1[i-1]==s3[i+j-1]) take1=dp[i-1][j];
                if(s2[j-1]==s3[i+j-1]) take2=dp[i][j-1];
                dp[i][j]=take1|take2;
            }
        }
        return dp[n1][n2];
    }
};

int main(){

return 0;
}