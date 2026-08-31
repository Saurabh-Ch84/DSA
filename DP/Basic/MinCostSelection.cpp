#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<int> dp(3,0);
        for(int i=0;i<n;i++){
            vector<int> temp(3,0);
            vector<int> choices={min(dp[1],dp[2]), 
                                min(dp[0],dp[2]), 
                                min(dp[0],dp[1])};
            for(int j=0;j<3;j++)
                temp[j]=mat[i][j]+choices[j];
            dp=temp;
        }
        return min({dp[0],dp[1],dp[2]}); 
    }
};

int main(){

return 0;
}