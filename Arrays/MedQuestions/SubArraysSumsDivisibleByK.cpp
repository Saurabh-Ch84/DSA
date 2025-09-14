#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByKBrute(vector<int>& nums, int k) {
        int count=0,n=nums.size();
        vector<int> prefixArr=nums;

        for(int i=1;i<n;i++)
            prefixArr[i]=prefixArr[i-1]+nums[i];

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=(i>0)?prefixArr[j]-prefixArr[i-1]:prefixArr[j];
                if(sum%k==0) count++;
            }
        }
        return count;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0,n=nums.size();
        unordered_map<int,int> hashMap;
        hashMap[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
            count+=hashMap[rem]++;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,6,3,4};
    int k=3;
    cout<<s.subarraysDivByK(nums,k);
return 0;
}