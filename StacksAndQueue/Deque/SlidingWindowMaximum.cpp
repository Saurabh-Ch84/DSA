#include<bits/stdc++.h>
using namespace std;

/*
5. The Ultimate Boss: Shortest Subarray with Sum at Least K (LeetCode 862)

Difficulty: Hard

Why it's crucial: This is arguably the hardest standard subarray problem. You cannot use a normal Sliding Window because the array contains negative numbers.

The Deque Logic: You combine Prefix Sums with a Monotonic Deque. You maintain a strictly increasing deque of prefix sums. It requires deep understanding of why elements are popped from the back (to keep it monotonic) and from the front (when a valid subarray is found).

*/


class Solution1 {
    // using priority queue, better but not optimal
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> res(n-k+1,-1);

        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            while(pq.top().second<=i-k)
                pq.pop();
            if(i>=k-1) res[i-k+1]=pq.top().first;
        }
        return res;
    }
};

class Solution2 {
    // using deque, optimal solution
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        vector<int> res(n-k+1,-1);

        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front()<=i-k)
                dq.pop_front();
            while(!dq.empty() && nums[i]>=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) res[i-k+1]=nums[dq.front()];
        }
        return res;
    }
};

int main(){

return 0;
}