#include<iostream>
#include<vector>
using namespace std;

using vi=vector<int>;
using vll=vector<long long>;
using vvll=vector<vll>;
class Solution {
    const long long negInf=-1e15;
    long long recursion(int i,int trend,int n,vi &nums,vvll &dp){
        if(i==n-1) return (trend==3 && nums[n-1]!=nums[n-2]? nums[n-1]: negInf);
        if(dp[i][trend]!=-1) return dp[i][trend];
        if(trend==0){
            long long start=negInf, skip=negInf;
            skip=recursion(i+1,0,n,nums,dp);
            if(nums[i]<nums[i+1])
                start=nums[i]+recursion(i+1,1,n,nums,dp);
            return dp[i][trend]=max(start,skip);
        }
        else if(trend==1){
            long long continued=negInf, changed=negInf;
            if(nums[i]>nums[i+1])
                changed=nums[i]+recursion(i+1,2,n,nums,dp);
            else if(nums[i]<nums[i+1])
                continued=nums[i]+recursion(i+1,1,n,nums,dp);
            return dp[i][trend]=max(continued,changed);
        }
        else if(trend==2){
            long long continued=negInf, changed=negInf;
            if(nums[i]<nums[i+1])
                changed=nums[i]+recursion(i+1,3,n,nums,dp);
            else if(nums[i]>nums[i+1])
                continued=nums[i]+recursion(i+1,2,n,nums,dp);
            return dp[i][trend]=max(continued,changed);
        }
        else{
            long long continued=negInf, stopped=negInf;
            stopped=nums[i];
            if(nums[i]<nums[i+1])
                continued=nums[i]+recursion(i+1,3,n,nums,dp);
            return dp[i][trend]=max(continued,stopped);
        }
        return -1;
    }
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size(), t=4;
        vvll dp(n,vll(t,-1));
        return recursion(0,0,n,nums,dp);
    }
};

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int maxi=0;
        for(int &l: left){
            int t=l;
            maxi=max(maxi,t);
        }
        for(int &r: right){
            int t=n-r;
            maxi=max(maxi,t);
        }
        return maxi;
    }
};

int main(){

return 0;
}