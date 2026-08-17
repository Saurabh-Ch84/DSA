#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=0, dp[1]=nums[0];
        for(int i=1;i<n;i++)
            dp[i+1]=max(dp[i],dp[i-1]+nums[i]);
        return dp[n];
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {2,1,5,6};
    cout << "The Max sum that can be robbed is Rs " << s->rob(v);
    return 0;
}