#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowPtr=nums[0],fastPtr=nums[nums[0]];
        while(slowPtr!=fastPtr){
            slowPtr=nums[slowPtr];
            fastPtr=nums[nums[fastPtr]];
        }
        slowPtr=0;
        while(slowPtr!=fastPtr){
            slowPtr=nums[slowPtr];
            fastPtr=nums[fastPtr];
        }
        return slowPtr;
    }
};

int main(){

return 0;
}