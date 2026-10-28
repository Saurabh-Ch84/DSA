#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    int negInf=-1e9;
    int dp[100000+1];
    int recursion(int i,int n,string &s){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int skipPair=1+recursion(i+1,n,s);
        int takePair=negInf;
        if(i+1<n){
            int take=negInf, skip=negInf;
            if(s[i]==s[i+1]) take=4+recursion(i+2,n,s)-1;
            else skip=4+recursion(i+2,n,s);
            takePair=max(take,skip);
        }
        return dp[i]=max(skipPair,takePair);
    }
  public:
    int getMaxWeight(string &s) {
        // code here
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return recursion(0,n,s);
    }
};

class Solution2 {
    int negInf=-1e9;
  public:
    int getMaxWeight(string &s) {
        // code here
        int n=s.size();
        vector<int> dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            int skipPair=1+dp[i+1], takePair=negInf;
            if(i+1<n){
                int take=negInf, skip=negInf;
                if(s[i]==s[i+1]) take=4+dp[i+2]-1;
                else skip=4+dp[i+2];
                takePair=max(take,skip);
            }
            dp[i]=max(skipPair,takePair);
        }
        return dp[0];
    }
};

class Solution3 {
    int negInf=-1e9;
  public:
    int getMaxWeight(string &s) {
        // code here
        int n=s.size();
        int next=0, nextnext=0;
        for(int i=n-1;i>=0;i--){
            int skipPair=1+next, takePair=negInf; 
            if(i+1<n){
                int take=negInf, skip=negInf;
                if(s[i]==s[i+1]) take=4+nextnext-1;
                else skip=4+nextnext;
                takePair=max(take,skip);
            }
            int curr=max(skipPair,takePair);
            nextnext=next;
            next=curr;
        }
        return next;
    }
};

int main(){

return 0;
}