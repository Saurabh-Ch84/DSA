#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // using ordered map, better but not optimal
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> hashMap;
        int maxi=0, n=nums.size(), left=0, right=0;
        while(right<n){
            hashMap[nums[right]]++;
            while((hashMap.rbegin()->first)-(hashMap.begin()->first)>limit){
                hashMap[nums[left]]--;
                if(!hashMap[nums[left]])
                    hashMap.erase(nums[left]);
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};

class Solution2 {
    // using deque, optimal solution
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> dqMax, dqMin;
        int maxi=0, n=nums.size(), left=0, right=0;
        while(right<n){
            while(!dqMax.empty() && dqMax.front()<left) 
                dqMax.pop_front();
            while(!dqMax.empty() && nums[right]>nums[dqMax.back()])
                dqMax.pop_back();
            while(!dqMin.empty() && dqMin.front()<left) 
                dqMin.pop_front();
            while(!dqMin.empty() && nums[right]<nums[dqMin.back()])
                dqMin.pop_back();
            dqMax.push_back(right);
            dqMin.push_back(right);
            if(nums[dqMax.front()]-nums[dqMin.front()]<=limit)
                maxi=max(maxi,right-left+1);
            else left++;
            right++;
        }
        return maxi;
    }
};

int main(){

return 0;
}