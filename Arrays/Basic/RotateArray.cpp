#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> nums_=nums;
        for(int i=0;i<n;i++){
            int val=nums_[i];
            int i_=(i+k)%n;
            nums[i_]=val;
        }
    }
};

int main(){

return 0;
}