#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
    bool isBalanced(map<int,long long> &map_,long long k,int right,int left){
        if(map_.empty()) return true;
        long long mini=map_.begin()->first;
        long long maxi=map_.rbegin()->first;
        return (maxi-mini)*(right-left+1)<=k;
    }
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count=0;
        int left=0, right=0, n=nums.size();
        map<int,long long> map_;
        while(right<n){
            int in=nums[right];
            map_[in]++;
            while(!isBalanced(map_,k,right,left)){
                int out=nums[left];
                map_[out]--;
                if(!map_[out])
                    map_.erase(out);
                left++;
            }
            count+=1LL*(right-left+1);
            right++;
        }
        return count;
    }
};

int main(){

return 0;
}