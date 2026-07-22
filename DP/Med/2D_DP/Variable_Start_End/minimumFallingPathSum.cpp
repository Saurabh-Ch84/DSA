#include<iostream>
#include<vector>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void createPadding(vector<int> &dp,vector<int> m)
    {
        dp.push_back(INT_MAX);
        for(int &val:m) dp.push_back(val);
        dp.push_back(INT_MAX);
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> dp;
        int n=matrix.size();
        createPadding(dp,matrix[n-1]);
        for(int i=n-2;i>-1;i--){
            vector<int> temp;
            createPadding(temp,matrix[i]);
            for(int j=1;j<temp.size()-1;j++)
                temp[j]+=min({dp[j-1],dp[j],dp[j+1]});
            dp=temp;
        }
        return *min_element(dp.begin()+1,dp.end()-1);
    }
};

int main(){

return 0;
}