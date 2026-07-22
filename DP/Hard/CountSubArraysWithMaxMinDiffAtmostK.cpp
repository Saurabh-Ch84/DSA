#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        const int MOD=1e9+7;

        multiset<int> hashSet;
        vector<int> dp(n+1,0),prefixArr(n+1,0);
        dp[0]=prefixArr[0]=1;

        int left=0;
        for(int right=1;right<=n;right++){
            hashSet.insert(nums[right-1]);
            while(*hashSet.rbegin()-*hashSet.begin()>k){
                hashSet.erase(hashSet.find(nums[left]));
                left++;
            }
            dp[right]=(prefixArr[right-1]-((left>0) ? prefixArr[left-1]:0)+MOD)%MOD;
            prefixArr[right]=(prefixArr[right-1]+dp[right]) % MOD;
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    vector<int> nums={9,8,3,1,5,3,3,7,3,6};
    cout<<s.countPartitions(nums,2);
return 0;
}