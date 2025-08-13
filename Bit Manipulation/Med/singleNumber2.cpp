#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bitIndex=0;bitIndex<32;bitIndex++){
            int count=0;
            for(int i=0;i<nums.size();i++)
                if(nums[i] & 1<<bitIndex) count++;
            if(count%3)
                ans|=(1<<bitIndex);
        }
        return ans;
    }
};

int main(){

return 0;
}