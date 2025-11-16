#include<iostream>
#include<vector>
using namespace std;

using vvi = vector<vector<int>> ;
class Solution {
    int recursion(int i,int j,int n,int m,string &s1,string &s2,vvi &dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,notTake=0;
        if(s1[i]==s2[j])
            take=1+recursion(i+1,j+1,n,m,s1,s2,dp);
        else{
            int one=recursion(i+1,j,n,m,s1,s2,dp);
            int two=recursion(i,j+1,n,m,s1,s2,dp);
            notTake=max(one,two);
        }
        return dp[i][j]=max(take,notTake);
    }
  public:
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n=s1.length(),m=s2.length();
        vvi dp(n,vector<int>(m,-1));
        int lcs=recursion(0,0,n,m,s1,s2,dp);
        int mss=n+m-lcs;
        return mss;
    }
};

int main(){

return 0;
}