#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Comp{
        bool operator()(const int &a,const int &b){
            return abs(a)<abs(b);
        }
    };
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),Comp());
        int n=nums.size();
        long long maxSum=0;
        for(int i=0;i<n;i++){
            if(i<n/2) maxSum=maxSum-1LL*nums[i]*nums[i];
            else maxSum=maxSum+1LL*nums[i]*nums[i];
        }
        return maxSum;
    }
};

int main(){

return 0;
}