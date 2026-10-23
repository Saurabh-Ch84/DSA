#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        vector<int> bitsArr(31,0);
        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int j=30;j>=0;j--){
                if(num & (1<<j)) bitsArr[j]++;
            }
        }
        int ans=0;
        for(int i=0;i<31;i++)
            ans=ans+(n-bitsArr[i])*(bitsArr[i]);
        return ans;
    }
};

int main(){

return 0;
}