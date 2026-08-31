#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod=1e9+7;
    using vint=vector<int>;
  public:
    int countSubsequences(string& s, int n) {
        // code here
        int m=s.size();
        vint dp(n+1,0);
        dp[0]=1;
        for(int i=m-1;i>=0;i--){
            vint temp(n+1,0);
            for(int j=0;j<=n;j++){
                long long skip=dp[j];
                int j_=(1LL*j*10+(s[i]-'0'))%n;
                long long take=dp[j_];
                temp[j]=(skip+take)%mod; 
            }
            dp=temp;
        }
        return dp[0]-1;
    }
};

int main(){

return 0;
}