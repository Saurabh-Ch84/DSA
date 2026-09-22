#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[1001][1001];
    int inf=1e8;
    int recursion(int i,int j,int n,int m,int costS1,int costS2,string &s1,string &s2){
        if(i==n && j==m) return 0;
        if(i==n) return (m-j)*costS2;
        if(j==m) return (n-i)*costS1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            int skip=recursion(i+1,j+1,n,m,costS1,costS2,s1,s2);
            return dp[i][j]=skip;
        }
        int takeLeft=costS1+recursion(i+1,j,n,m,costS1,costS2,s1,s2);
        int takeRight=costS2+recursion(i,j+1,n,m,costS1,costS2,s1,s2);
        return dp[i][j]=min(takeLeft,takeRight);
    }
  public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        int n=s1.size(), m=s2.size();
        memset(dp,-1,sizeof(dp));
        return recursion(0,0,n,m,costS1,costS2,s1,s2);
    }
};

int main(){

return 0;
}