#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(), count=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n])
                count++;
        }
        return count<2;
    }
};

int main(){

return 0;
}
