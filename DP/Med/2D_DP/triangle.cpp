#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    int recursion(vector<vector<int>> &t,int end,int row=0,int col=0){
        if(row==end) return t[end][col];
        if(col>row) return 100000;
        int answer=INT_MAX;
        for(int j=col;j<=col+1;j++)
        {
            int ans=t[row][col]+recursion(t,end,row+1,j);
            if(ans<answer) answer=ans;
        }
        return answer;
    }

    int memoization(vector<vector<int>> &t,int end,vector<vector<int>> &dp,int row=0,int col=0){
        if(row==end) return t[end][col];
        if(col>row) return 100000;
        if(dp[row][col]!=-1) return dp[row][col];
        int answer=INT_MAX;
        for(int j=col;j<=col+1;j++)
        {
            int ans=t[row][col]+memoization(t,end,dp,row+1,j);
            if(ans<answer) answer=ans;
        }
        return dp[row][col]=answer;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // return recursion(triangle,triangle.size()-1);
        // int m=triangle.size(),n=triangle.back().size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return memoization(triangle,triangle.size()-1,dp);
        //this is space-optimised tabulation
        // vector<int> dp(triangle.size()+1,INT_MAX);
        // dp[1]=triangle[0][0];
        // for(int i=1;i<triangle.size();i++){
        //     vector<int> temp(triangle.size()+1,INT_MAX);
        //     for(int j=0;j<triangle[i].size();j++)
        //         temp[j+1]=triangle[i][j]+min(dp[j],dp[j+1]);
        //     dp=temp;
        // }
        // return *min_element(dp.begin(),dp.end());

        int n=triangle.size();
        vector<int> dp=triangle[n-1];
        for(int i=n-2;i>-1;i--){
            vector<int> temp;
            temp=triangle[i];
            for(int j=0;j<temp.size();j++)
                temp[j]+=min(dp[j],dp[j+1]);
            dp=temp;
        }
        return dp[0];
    }
};

int main(){

return 0;
}