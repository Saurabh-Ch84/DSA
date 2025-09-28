#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // brute-force
    int largestPerimeter1(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size(),maxPeri=0;

        for(int i=n-1;i>=0;i--){
            int j=i-1,k=0;
            while(k<j){
                if(nums[j]+nums[k]>nums[i]){
                    int peri=nums[i]+nums[j]+nums[k];
                    maxPeri=max(maxPeri,peri);
                }
                k++;
            }
        }
        return maxPeri;
    }
    //optimal
    int largestPerimeter2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size(),maxPeri=0;

        for(int i=n-1;i>=0;i--){
            int j=i-1,k=i-2;
            if(j>=0 && k>=0 && nums[k]+nums[j]>nums[i]){
                int peri=nums[k]+nums[j]+nums[i];
                maxPeri=max(maxPeri,peri);
                break;
            }
        }
        
        return maxPeri;
    }
};


int main(){
    Solution s;
    vector<int> nums={9,8,3,1,5,3,3,7,3,6};
    cout<<s.largestPerimeter2(nums)<<endl;
return 0;
}