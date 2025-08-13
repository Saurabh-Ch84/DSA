#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int recursion(int i,int n,vector<int> &nums,int maxOR,int currOR=0){
        if(i>=n) return maxOR==currOR;
        int notTake=recursion(i+1,n,nums,maxOR,currOR);
        int take=recursion(i+1,n,nums,maxOR,currOR|nums[i]);
        return take+notTake;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxBitWiseOR=0,n=nums.size();
        for(int &num:nums) maxBitWiseOR=maxBitWiseOR|num;
        return recursion(0,n,nums,maxBitWiseOR);
    }
};

int main(){

return 0;
}