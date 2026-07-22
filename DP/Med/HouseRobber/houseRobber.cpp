#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    void print(vector<int> array)
    {
        cout << "[";
        for (int j = 0; j < array.size(); j++)
        {
            if (j == array.size() - 1)
                cout << array[j];
            else
                cout << array[j] << ",";
        }
        cout << "] " << endl;
    }
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        print(nums);
        nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
            nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);
        print(nums);
        return nums[n - 1];
    }
};

class Solution {
    int recursion(int i,int n,vector<int> &nums,vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int notTake=recursion(i+1,n,nums,dp);
        int take=nums[i]+recursion(i+2,n,nums,dp);
        return dp[i]=max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return recursion(0,n,nums,dp);
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {2,1,5,6};
    cout << "The Max sum that can be robbed is Rs " << s->rob(v);
    return 0;
}