#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution1{
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int>(3,0)) ;
        for(int i=0;i<3;i++)
            dp[0][i]=arr[0][i];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                int runPoints=INT_MIN,fightPoints=INT_MIN,learnPoints=INT_MIN;
                if(j!=0) runPoints=dp[i-1][0];
                if(j!=1) fightPoints=dp[i-1][1];
                if(j!=2) learnPoints=dp[i-1][2];
                dp[i][j]=arr[i][j]+max({runPoints,fightPoints,learnPoints});
            }
        }
        return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    }
};

class Solution2{
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(3,0);
        for(int i=0;i<3;i++)
            dp[i]=arr[0][i];
        
        for(int i=1;i<n;i++){
            vector<int> temp(3,0);
            for (int j = 0; j < 3; j++) {
                int maxPrev = INT_MIN;
                for (int k = 0; k < 3; k++)
                    if (k != j) maxPrev = max(maxPrev, dp[k]);
                temp[j] = arr[i][j] + maxPrev;
            }
            dp=temp;
        }
        return max({dp[0],dp[1],dp[2]});
    }
};

int main(){

return 0;
}