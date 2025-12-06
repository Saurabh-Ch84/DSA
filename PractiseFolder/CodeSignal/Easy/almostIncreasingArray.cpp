#include <iostream>
#include <vector>
#include <climits>
#include <map>
using namespace std;

/*
**Strictly Increasing Sequence**

**Given a sequence of integers as an array, determine whether it is possible to obtain a
strictly increasing sequence by removing no more than one element from the array.**

**Note:**
A sequence `a₀, a₁, ..., aₙ` is considered to be strictly increasing if `a₀ < a₁ < ... < aₙ`.
A sequence containing only one element is also considered to be strictly increasing.

**Example**
- For `sequence = [1, 3, 2, 1]`, the output should be
  `solution(sequence) = false`.
  There is no one element in this array that can be removed in order to get a strictly increasing sequence.

- For `sequence = [1, 3, 2]`, the output should be
  `solution(sequence) = true`.
  You can remove `3` from the array to get the strictly increasing sequence `[1, 2]`.
  Alternately, you can remove `2` to get the strictly increasing sequence `[1, 3]`.
*/

class Solution
{
    int recursion(int i, int n, vector<int> &nums, int prev, int count)
    {
        if (i >= n)
            return true;
        if (count > 1)
            return false;
        int curr = nums[i];
        bool notRemove = false, removePrev = false, removeCurr = false;
        if (curr > prev)
        {
            notRemove = recursion(i + 1, n, nums, curr, count);
            removePrev = recursion(i + 1, n, nums, curr, count + 1); // remove previous
        }
        removeCurr = recursion(i + 1, n, nums, prev, count + 1); // remove current
        return notRemove || removePrev || removeCurr;
    }
    map<tuple<int, int, int>, bool> dp; // (i, prev, count)

        bool memoization(int i, int n, vector<int> &nums, int prev, int count)
        {
            if (i >= n)
                return true;
            if (count > 1)
                return false;

            auto key = make_tuple(i, prev, count);
            if (dp.count(key))
                return dp[key];

            int curr = nums[i];
            bool notRemove = false, removePrev = false, removeCurr = false;

            if (curr > prev)
            {
                notRemove = memoization(i + 1, n, nums, curr, count);
                removePrev = memoization(i + 1, n, nums, curr, count + 1);
            }
            removeCurr = memoization(i + 1, n, nums, prev, count + 1);

            return dp[key] = (notRemove || removePrev || removeCurr);
        }
public:
    bool canBe_A_LIS_Brute(vector<int> nums)
    {
        int n = nums.size();
        if (!n) return true;
        return memoization(1, n, nums, nums[0], 0);
    }
    bool canBe_A_LIS(vector<int> nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] >= nums[i+1]) {
                count++;
                if(count > 1) return false;
                // Check if removing nums[i] or nums[i+1] can fix the sequence
                if(i > 0 && nums[i-1] >= nums[i+1] && i+2 < n && nums[i] >= nums[i+2]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.canBe_A_LIS({1, 3, 2, 1}) << endl;
    cout << s.canBe_A_LIS({1, 3, 2}) << endl;
    cout << s.canBe_A_LIS({1, 2, 5, 3, 4}) << endl;
    return 0;
}