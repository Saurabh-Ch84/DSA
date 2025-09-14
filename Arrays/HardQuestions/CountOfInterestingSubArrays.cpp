#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        unordered_map<int,long long> hashMap;
        hashMap[0]=1;

        long long count=0,sum=0;
        for(int i=0;i<n;i++){
            if(nums[i] % modulo == k) 
                sum+=1;
            long long r1 = sum % modulo;
            long long r2 = (r1-k+modulo) % modulo;
            count+=hashMap[r2];
            hashMap[r1]++;
        }
        
        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums={9,3,1,3,6};
    int mod=2,k=1;
    cout<<s.countInterestingSubarrays(nums,mod,k);
return 0;
}