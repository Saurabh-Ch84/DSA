#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        int n=t.length();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            vector<int> temp(n+1,0);
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]) temp[j]=1+dp[j-1];
                else temp[j]=max(temp[j-1],dp[j]);
            }
            dp=temp;
        }
        return dp.back();
    }
};

int main(){

return 0;
}