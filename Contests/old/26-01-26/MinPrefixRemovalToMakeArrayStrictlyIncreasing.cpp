#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1])
                return i+1;
        }
        return 0;
    }
};

int main(){

return 0;
}