#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1),bitLastSeen(30,-1);
        for(int i=n-1;i>=0;i--){
            for(int bit=0;bit<30;bit++){
                if(nums[i] & (1<<bit))
                    bitLastSeen[bit]=i;
            }
            int maxDist=1;
            for(int bit=0;bit<30;bit++){
                if(bitLastSeen[bit]!=-1)
                    maxDist=max(maxDist,bitLastSeen[bit]-i+1);
            }
            ans[i]=maxDist;
        }
        return ans;
    }
};

void print(vector<int> nums){
    for(int &num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(){
    Solution s;
    vector<int> nums={9,8,1,6,2,7,0,5};
    print(s.smallestSubarrays(nums));
return 0;
}