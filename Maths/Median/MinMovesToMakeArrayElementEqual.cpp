#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int median=(n&1? nums[n/2]:(nums[n/2-1]+nums[n/2])/2);
        int cost=0;
        for(int &num: nums){
            cost+=abs(num-median);
        }
        return cost;
    }
};

int main(){

return 0;
}