#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    void computePrefix(vector<long long> &prefixArr,vector<int> &nums,int n){
        prefixArr[0]=nums[0];
        for(int i=1;i<n;i++)
            prefixArr[i]=nums[i]*1LL+prefixArr[i-1];
    }
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefixArr(n,0);
        computePrefix(prefixArr,nums,n);
        int idx=0;
        long long maxSubSum=LLONG_MIN;
        while(idx<k){
            int i=idx;
            long long currSum=0;
            while(i<n && i+k-1<n){
                int j=i+k-1;
                long long subArrSum=prefixArr[j]-(i<1 ? 0: prefixArr[i-1]);
                currSum=max(subArrSum,currSum+subArrSum);
                maxSubSum=max(maxSubSum,currSum);
                i+=k;
            }
            idx++;
        }
        return maxSubSum;
    }
};

int main(){

return 0;
}