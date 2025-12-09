#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int &num: nums) sum+=num;

        int count=0,leftSum=0;
        for(int i=0;i<n-1;i++){
            leftSum+=nums[i];
            int rightSum=sum-leftSum;
            if(abs(rightSum-leftSum) % 2 == 0)
                count++;
        }
        return count;
    }
};

int main(){

return 0;
}