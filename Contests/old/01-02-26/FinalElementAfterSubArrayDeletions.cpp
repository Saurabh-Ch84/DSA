#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(),nums.back());
    }
};

int main(){

return 0;
}