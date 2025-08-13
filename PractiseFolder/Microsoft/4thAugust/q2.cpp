#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
    int recursion(string &s,int i,int j,int n){
        if(i>=j) return i==j;
        int take=0,notTake=0;
        if(s[i]==s[j]) take=1+1+recursion(s,i+1,j-1,n);
        notTake=max(recursion(s,i+1,j,n),recursion(s,i,j-1,n));
        return max(take,notTake);
    }
    int memoization(string &s,int i,int j,vector<vector<int>> &dp){
        if(i>=j) return i==j;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,notTake=0;
        if(s[i]==s[j]) take=2+memoization(s,i+1,j-1,dp);
        notTake=max(memoization(s,i+1,j,dp),memoization(s,i,j+1,dp));
        return dp[i][j]=max(take,notTake);
    }
    int recursion2(string &s,string &r,int i,int j,int n){
        if(i>=n || j>=n) return 0;
        int take=0,notTake=0;
        if(s[i]==r[j]) take=1+recursion2(s,r,i+1,j+1,n);
        notTake=max(recursion2(s,r,i+1,j,n),recursion2(s,r,i,j+1,n));
        return max(take,notTake);
    }
    int memoization2(string &s,string &r,int i,int j,int n,vector<vector<int>> &dp){
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,notTake=0;
        if(s[i]==r[j]) take=1+memoization2(s,r,i+1,j+1,n,dp);
        notTake=max(memoization2(s,r,i+1,j,n,dp),memoization2(s,r,i,j+1,n,dp));
        return dp[i][j]=max(take,notTake);
    }
    int tabulation2(string &s,string &r,int n){
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            vector<int> temp(n+1,0);
            for(int j=1;j<=n;j++){
                if(r[i-1]==s[j-1]) temp[j]=1+dp[j-1];
                else temp[j]=max(temp[j-1],dp[j]);
            }
            dp=temp;
        }
        return dp[n];
    }
    
        public:
    int findLongestPalindromicSubsequence(string s){
        string r=s;
        int n=s.length();
        reverse(r.begin(),r.end());
        // return recursion2(s,r,0,0,n);
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return memoization2(s,r,0,0,n,dp);
        return tabulation2(s,r,n);
    }
};

int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    Solution s;
    cout<<s.findLongestPalindromicSubsequence(str);
return 0;
}