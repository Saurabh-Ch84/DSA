#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int recursion(int prev,int sz,int n,int m,vvint &dp){
        if(sz==n) return 1;
        if(dp[prev][sz]!=-1) return dp[prev][sz];
        int count=0;
        for(int i=1;i<=m;i++){
            if(!prev || (prev%i==0) || (i%prev==0))
                count=count+recursion(i,sz+1,n,m,dp);
        }
        return dp[prev][sz]=count;
    }
  public:
    int count(int n, int m) {
        // code here
        vvint dp(m+1,vint(n,-1));
        return recursion(0,0,n,m,dp);
    }
};

int main(){

return 0;
}