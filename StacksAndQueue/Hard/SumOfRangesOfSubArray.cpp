#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    void getNextGreaterElementIndex(vector<int> &nums,vector<int> &nge,int n){
        stack<int> mDStack;
        for(int i=n-1;i>-1;i--){
            while(!mDStack.empty() && nums[i]>=nums[mDStack.top()]) mDStack.pop();
            if(!mDStack.empty()) nge[i]=mDStack.top();
            mDStack.push(i);
        }
    }
    void getPrevGreaterOrEqualElementIndex(vector<int> &nums,vector<int> &pgee,int n){
        stack<int> mDStack;
        for(int i=0;i<n;i++){
            while(!mDStack.empty() && nums[i]>nums[mDStack.top()]) mDStack.pop();
            if(!mDStack.empty()) pgee[i]=mDStack.top();
            mDStack.push(i);
        }
    }
    void getNextSmallerElementIndex(vector<int> &nums,vector<int> &nse,int n){
        stack<int> mIStack;
        for(int i=n-1;i>-1;i--){
            while(!mIStack.empty() && nums[i]<=nums[mIStack.top()]) mIStack.pop();
            if(!mIStack.empty()) nse[i]=mIStack.top();
            mIStack.push(i);
        }
    }
    void getPrevSmallerEqualElementIndex(vector<int> &nums,vector<int> &psee,int n){
        stack<int> mIStack;
        for(int i=0;i<n;i++){
            while(!mIStack.empty() && nums[i]<nums[mIStack.top()]) mIStack.pop();
            if(!mIStack.empty()) psee[i]=mIStack.top();
            mIStack.push(i);
        }
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> ngeIdx(n,n),nseIdx(n,n),pgeeIdx(n,-1),pseeIdx(n,-1);
        getNextGreaterElementIndex(nums,ngeIdx,n);
        getPrevGreaterOrEqualElementIndex(nums,pgeeIdx,n);
        getNextSmallerElementIndex(nums,nseIdx,n);
        getPrevSmallerEqualElementIndex(nums,pseeIdx,n);
        long long rangeSum=0;
        for(int i=0;i<n;i++)
        {
            int leftMin=i-pseeIdx[i],rightMin=nseIdx[i]-i;
            long long minSum=1LL*leftMin*rightMin*nums[i];
            int leftMax=i-pgeeIdx[i],rightMax=ngeIdx[i]-i;
            long long maxSum=1LL*leftMax*rightMax*nums[i];
            rangeSum+=(maxSum-minSum);
        }
        return rangeSum;
    }
};

int main(){

return 0;
}