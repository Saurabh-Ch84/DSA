#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool check(vector<int> &nums,int k,int mid,int n){
        int divisions=1,sum=0;
        for(int &num:nums){
            if(sum+num>mid){
                divisions++;
                sum=0;
            }
            sum+=num;
            if(divisions>k) return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0,high=0;
        for(int &num:nums){
            low=max(low,num);
            high+=num;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            bool response=check(nums,k,mid,n);
            if(response) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

int main(){

return 0;
}