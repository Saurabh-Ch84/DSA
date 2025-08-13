#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//strivers approach
class Solution1 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!st.empty() && st.top() <= nums[idx])
                st.pop();
            if (i < n && !st.empty())
                res[idx] = st.top();
            st.push(nums[idx]);
        }
        return res;
    }
};


//My Approach
class Solution2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> mDStack;
        vector<int> res(n,-1);
        for(int i=n-1;i>-1;i--){
            while(!mDStack.empty() && nums[i]>=mDStack.top())
                mDStack.pop();
            mDStack.push(nums[i]);
        }
        for(int i=n-1;i>-1;i--){
            while(!mDStack.empty() && nums[i]>=mDStack.top())
                mDStack.pop();
            if(!mDStack.empty()) res[i]=mDStack.top();
            mDStack.push(nums[i]);
        }
        return res;
    }
};

int main(){

return 0;
}