#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size(), zeros=0, xorNums=0;
        for(int i=0;i<n;i++){
            if(!nums[i]) zeros++;
            xorNums=xorNums^nums[i];
        }
        if(zeros==n) return 0;
        if(xorNums) return n;
        return n-1;
    }
};

int main(){

return 0;
}