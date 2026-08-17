#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size(), i=0, mini=1e9;
        deque<int> dq;
        vector<long long> prefixSum(n,0);
        prefixSum[0]=nums[0];

        while(i<n){
            if(i) prefixSum[i]=nums[i]+prefixSum[i-1];
            if(prefixSum[i]>=k) mini=min(mini,i+1);
            // remove invalid prefix sums from the front of the deque by shrinking the window
            while(!dq.empty() && prefixSum[i]-prefixSum[dq.front()]>=k){
                mini=min(mini,i-dq.front());
                dq.pop_front();
            }
            // maintain monotonicity of the deque
            while(!dq.empty() && prefixSum[i]<=prefixSum[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            i++;
        }
        return (mini==1e9? -1: mini);
    }
};

int main(){

return 0;
}