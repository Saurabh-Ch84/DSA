#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int m=s1.length(),n=s2.length();
        vector<int> dp(n+1,0);
        
        for(int i=1;i<=m;i++)
        {
            vector<int> temp(n+1,0);
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) temp[j]=1+dp[j-1];
                else temp[j]=max(temp[j-1],dp[j]);
            }
            dp=temp;
        }
        int minOperations=(m+n)-2*dp[n];
        return minOperations;
    }
};

int main(){

return 0;
}