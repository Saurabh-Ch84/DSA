#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Optimal
    long long maximumValueSum1(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int count=0,minDiff=INT_MAX;
        long long sum=0;
        for(int &num:nums){
            int num_=num^k;
            int diff=num_-num;
            if(diff>0){
                count++;
                sum+=num_;
            }
            else sum+=num;
            minDiff=min(minDiff,abs(diff));
        }
        if(count%2==1)
            sum-=minDiff;
        return sum;
    }
    //Better
    long long maximumValueSum2(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> ans;
        long long sum=0;
        for(int &num:nums){
            sum+=num;
            int num_=num^k;
            ans.push_back(num_-num);
        }
        sort(rbegin(ans),rend(ans));
        int n=ans.size();
        for(int i=0;i<n-1;i+=2){
            long long pairSum=ans[i]+ans[i+1];
            if(pairSum>0) sum+=pairSum;
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,1};
    int k=3;
    vector<vector<int>> edges={{0,1},{1,2},{0,2}};
    cout<<s.maximumValueSum1(nums,k,edges);
return 0;
}