#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int ways=0;
                for(int f=1;f<=k;f++){
                    if(j>=f) ways=(ways%MOD+dp[i-1][j-f]%MOD)%MOD;
                }
                dp[i][j]=ways;
            }
        }
        return dp[n][target];
    }
};

int main(){

return 0;
}