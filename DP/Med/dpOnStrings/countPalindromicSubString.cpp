#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int> ;
using vvi = vector<vi> ;

class Solution {
    int countPalindrome(string &s,int i,int j,int n){
        int count=0;
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
            count++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int n=s.length(),count=0;
        for(int i=0;i<n;i++){
            int odd = countPalindrome(s,i,i,n);
            int even = countPalindrome(s,i,i+1,n);
            count=count+odd+even;
        }
        return count;
    }
};

class Solution {
    bool isPalindrome(int i,int j,string &s,vvi &dp){
        if(i>=j) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=isPalindrome(i+1,j-1,s,dp);
        return dp[i][j]=0;
    }
public:
    int countSubstrings(string s) {
        int n=s.length(),count=0;
        vvi dp(n,vi(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s,dp))
                    count++;
            }
        }
        return count;
    }
};

int main(){

return 0;
}