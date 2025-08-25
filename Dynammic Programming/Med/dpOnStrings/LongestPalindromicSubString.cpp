#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int isPalindrome(string &s,int i,int j,vector<vector<int>> &dp){
        if(i>=j) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=isPalindrome(s,i+1,j-1,dp);
        else return dp[i][j]=0;
    }
    
    string memoizationApproach(string &s){
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int maxLen=1,st=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j,dp))
                {
                    if(j-i+1>maxLen)
                    {
                        maxLen=j-i+1;
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,maxLen);
    }
    
    string palindromicExpansion(string &s,int i,int j,int n){
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    
    string expansionApproach(string &s){
        int n=s.length();
        string maxLenSubStr=s.substr(0,1);
        for(int i=0;i<n;i++){
            string oddSubStr=palindromicExpansion(s,i,i,n);
            string evenSubStr=palindromicExpansion(s,i,i+1,n);
            if(oddSubStr.length()>maxLenSubStr.length()) 
                maxLenSubStr=oddSubStr;
            if(evenSubStr.length()>maxLenSubStr.length()) 
                maxLenSubStr=evenSubStr;
        }
        return maxLenSubStr;
    }
  public:
    string longestPalindrome(string s,bool useMemo=false) {
        return (useMemo)?memoizationApproach(s): expansionApproach(s);
    }
};
int main(){
    Solution s;

    cout<<s.longestPalindrome("saurabhishappybecauseheisenjoyingtheprocessverymuchthankyouforpatienceandcalmletshopefjbwbdwniwqjfbdsfsdfbsdfdfpsjeoifbewflasnfdiuefoesjfdmsabfuedufldsfesbfesdfefneiofuedfiueorhappinessandlove",false)<<endl;
    
    cout<<s.longestPalindrome("saurabhishappybecauseheisenjoyingtheprocessverymuchthankyouforpatienceandcalmletshopefjbwbdwniwqjfbdsfsdfbsdfdfpsjeoifbewflasnfdiuefoesjfdmsabfuedufldsfesbfesdfefneiofuedfiueorhappinessandlove",true)<<endl;
    
return 0;
}