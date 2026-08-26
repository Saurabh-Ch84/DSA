#include<iostream>
#include<vector>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    int minCut(string s) {
        int n=s.size();
        vvint isPalindrome(n,vint(n,0));
        for(int i=0;i<n;i++)
            isPalindrome[i][i]=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])
            isPalindrome[i][i+1]=1;
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(s[i]==s[j] && isPalindrome[i+1][j-1])
                    isPalindrome[i][j]=1;
            }
        }
        vint dp(n+1,n+1);
        dp[n]=0,dp[n-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(isPalindrome[i][j])
                    dp[i]=min(dp[i],1+dp[j+1]);
            }
        }
        return dp[0]-1;
    }
};

int main(){

return 0;
}