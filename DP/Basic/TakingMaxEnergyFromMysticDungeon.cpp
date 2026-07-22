#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    int memoization(vector<int>& energy,vector<int> &dp,int i,int n,int k){
        if(i>=n) return 0;
        if(dp[i]!=INT_MIN) return dp[i];
        return dp[i]=memoization(energy,dp,i+k,n,k)+energy[i];
    }
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size(),maxi=INT_MIN;
        vector<int> dp(n,INT_MIN);
        for(int i=0;i<n;i++){
            int val=memoization(energy,dp,i,n,k);
            maxi=max(maxi,val);
        }
        return maxi;
    }
};

int main(){

return 0;
}