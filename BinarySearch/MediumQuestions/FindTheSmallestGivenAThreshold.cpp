#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    bool check(vector<int> &nums,int threshold,int mid){
        int sum=0;
        for(int &num:nums){
            int currSum=(num+mid-1)/mid;
            sum+=currSum;
            if(sum>threshold) return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int high=INT_MIN,low=1;
        for(int &num:nums)
            high=max(high,num);
        while(low<=high){
            int mid=low+(high-low)/2;
            bool response=check(nums,threshold,mid);
            if(response) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

int main(){

return 0;
}