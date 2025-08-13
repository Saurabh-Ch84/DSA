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

int main()
{
    Solution *s = new Solution();
    vector<int> v = {2,1,5,6};
    cout << "The Max sum that can be robbed is Rs " << s->rob(v);
    return 0;
}