#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n+1,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            dp[arr[i]]=dp[arr[i]-1]+1;
            maxi=max(maxi,dp[arr[i]]);
        }
        return n-maxi;
    }
};

int main(){

return 0;
}