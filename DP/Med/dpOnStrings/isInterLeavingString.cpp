#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vector<int>> ;
class Solution1 {
    bool recursion(int i,int j,int x,int sz,string &s,string &s3,vvi &dp){
        if(i>=x) return true;
        if(j>=sz) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool take=false,notTake=false;
        if(s[i]==s3[j]) take=recursion(i+1,j+1,x,sz,s,s3,dp);
        else notTake=recursion(i,j+1,x,sz,s,s3,dp);
        return dp[i][j]=take|notTake;
    }
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int n=s1.length(),m=s2.length(),sz=s3.length();
        if(m+n != sz) return false;
        vvi dp1(n,vi(sz,-1)),dp2(m,vi(sz,-1));
        return recursion(0,0,n,sz,s1,s3,dp1) && recursion(0,0,m,sz,s2,s3,dp2);
    }
};

class Solution2 {
    bool recursion(int i,int j,int n1,int n2,int m,string &s1,string &s2,string &s3,vvi &dp){
        if(i>=n1 && j>=n2) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        int k=i+j;
        bool str1Take=false,str2Take=false;
        if(i<n1 && s1[i]==s3[k])
            str1Take=recursion(i+1,j,n1,n2,m,s1,s2,s3,dp);
        if(j<n2 && s2[j]==s3[k])
            str2Take=recursion(i,j+1,n1,n2,m,s1,s2,s3,dp);
        return dp[i][j]=str1Take|str2Take;
    }
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int n1=s1.length(),n2=s2.length(),m=s3.length();
        if(n1+n2!=m) return false;
        vvi dp(n1+1,vi(n2+1,-1));
        return recursion(0,0,n1,n2,m,s1,s2,s3,dp);
    }
};

int main(){

return 0;
}