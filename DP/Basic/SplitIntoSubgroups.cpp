#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int recursion(int i,int sum,int n,string &s,vvint &dp){
        if(i>=n) return 1;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans=0, temp=0;
        for(int j=i;j<n;j++){
            temp+=s[j]-'0';
            if(temp>=sum){
                int next=recursion(j+1,temp,n,s,dp);
                ans+=next;
            }
        }
        return dp[i][sum]=ans;
    }
  public:
    int validGroups(string &s) {
        // code here
        int n=s.size();
        vvint dp(n,vint(901,-1));
        return recursion(0,0,n,s,dp);
    }
};

int main(){

return 0;
}