#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ops=0,n=nums.size();
        for(int i=0;i<n;i++)
            ops=(ops+nums[i])%k;
        return ops;
    }
};

int main(){

return 0;
}