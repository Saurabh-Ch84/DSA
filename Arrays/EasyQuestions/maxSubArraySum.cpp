#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN,sum=0;
        for(int &num: nums){
            sum+=num;
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
};

class Solution
{
public:
    int maxSubarraySum1(vector<int> &arr)
    {
        // Code here
        int sum = 0, maxSum = INT_MIN, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            maxSum = max(sum, maxSum);
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }
    vector<int> maxSubarraySum2(vector<int> &arr)
    {
        // Code here
        int sum = 0, maxSum = INT_MIN, n = arr.size();
        int startIdx = -1, endIdx = -1, idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (sum == 0)
                idx = i;
            sum += arr[i];
            if (sum > maxSum)
            {
                maxSum = sum;
                startIdx = idx;
                endIdx = i;
            }
            if (sum < 0)
                sum = 0;
        }
        if(startIdx==-1 || endIdx==-1) return {};
        vector<int> ans;
        ans.assign(arr.begin() + startIdx, arr.begin() + endIdx + 1);
        return ans;
    }
};

int main()
{

    return 0;
}