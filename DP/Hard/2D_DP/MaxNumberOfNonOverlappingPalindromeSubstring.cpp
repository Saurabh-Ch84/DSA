#include<bits/stdc++.h>
using namespace std;

class Solution1{
    vector<vector<bool>> isPalindrome;
    int dp[2001][2001];
    int recursion(int j,int i,int k,int n){
        if(i==n) return 0;
        if(dp[j][i]!=-1) return dp[j][i];
        int skipChar=0, keepChar=0, makePartition=0;
        skipChar=recursion(i+1,i+1,k,n);
        keepChar=recursion(j,i+1,k,n);
        if(i-j+1>=k && isPalindrome[j][i])
            makePartition=1+recursion(i+1,i+1,k,n);
        return dp[j][i]=max({skipChar,keepChar,makePartition});
    }
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        isPalindrome.resize(n,vector<bool>(n,0));
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(len==1) isPalindrome[i][j]=1;
                else if(len==2 && s[i]==s[j]) isPalindrome[i][j]=1;
                else if(s[i]==s[j] && isPalindrome[i+1][j-1]) isPalindrome[i][j]=1;
            }
        }
        memset(dp,-1,sizeof(dp));
        return recursion(0,0,k,n);
    }
};

class Solution2{
    vector<vector<bool>> isPalindrome;
    int dp[2001];
    int recursion(int n,int k){
        if(n<k) return 0;
        if(dp[n]!=-1) return dp[n];
        int skip=recursion(n-1,k), take=0;
        int j=n-1;
        for(int i=0;j-i+1>=k;i++){
            if(isPalindrome[i][j]){
                int nextTake=1+recursion(i,k);
                take=max(take,nextTake);
            }
        }
        return dp[n]=max(skip,take);
    }
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        isPalindrome.resize(n,vector<bool>(n,0));
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(len==1) isPalindrome[i][j]=1;
                else if(len==2 && s[i]==s[j]) isPalindrome[i][j]=1;
                else if(s[i]==s[j] && isPalindrome[i+1][j-1]) isPalindrome[i][j]=1;
            }
        }
        memset(dp,-1,sizeof(dp));
        return recursion(n,k);
    }
};

int main(){

return 0;
}