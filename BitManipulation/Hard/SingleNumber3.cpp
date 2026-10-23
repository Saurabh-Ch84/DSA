#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==2) return nums;
        long x_o_r=0;
        for(int &num:nums)
            x_o_r=x_o_r^num;

        long lastSetBit=(x_o_r&(x_o_r-1))^(x_o_r);
        int lastBitSetBucket=0,lastBitUnsetBucket=0;
        for(int &num:nums)
        {
            if(num & lastSetBit)
                lastBitSetBucket^=num;
            else
                lastBitUnsetBucket^=num;
        }
        return {lastBitSetBucket,lastBitUnsetBucket};
    }
};

int main(){

return 0;
}