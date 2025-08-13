#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1=0;
        for(int &num:nums)
            xor1=xor1^num;
        return xor1;
    }
};

int main(){

return 0;
}