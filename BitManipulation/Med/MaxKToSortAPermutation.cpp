#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int mask=INT_MAX, n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=i) mask=mask&nums[i];
        }
        return (mask==INT_MAX? 0:mask);
    }
};

int main(){

return 0;
}