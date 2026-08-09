#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<int> dp(n,0);
        map<int,int> maxSumMap;
        for(int j=0;j<n;j++){
            dp[j]=mat[0][j];
            maxSumMap[dp[j]]++;
        }
        
        for(int i=1;i<n;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                maxSumMap[dp[j]]--;
                if(!maxSumMap[dp[j]])
                    maxSumMap.erase(dp[j]);
                int maxi=maxSumMap.rbegin()->first;
                temp[j]=mat[i][j]+maxi;  
                maxSumMap[dp[j]]++;
            }
            maxSumMap.clear();
            for(int j=0;j<n;j++){
                dp[j]=temp[j];
                maxSumMap[dp[j]]++;
            }
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};

int main(){

return 0;
}