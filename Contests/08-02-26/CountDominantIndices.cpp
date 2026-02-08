#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int dominantIndices(vector<int>& nums){
        int total=accumulate(nums.begin(),nums.end(),0);
        int count=0, n=nums.size();
        for(int i=0;i<n-1;i++){
            total-=nums[i];
            if(nums[i]*(n-i-1)>total) count++;
        }
        return count;
    }
};

int main(){

return 0;
}