#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
        public:
    int minSubArrayLen(int target, vector<int>& nums) {
	    int n = nums.size();
	    int left = 0, right = 0;
	    int len = INT_MAX, currSum = 0;
	    while (right < n) {
    		currSum += nums[right];
		    while (currSum >= target) {
    			len = min(len, right - left + 1);
	    		currSum -= nums[left++];
    		}
	    	right++;
	    }
	    return (len == INT_MAX) ? 0 : len;
    }
};

int main(){
    Solution s;
    vector<int> nums={3,0,1,0,4,0,3};
    cout<<s.minSubArrayLen(5,nums);
return 0;
}