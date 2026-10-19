#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod=1e9+7;
public:
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> bitCount(31,0);
        for(int i=0;i<n;i++){
            for(int bit=0;bit<31;bit++){
                if((nums[i]>>bit) & 1) 
                    bitCount[bit]++;
            }
        }
        int maxSum=0;
        while(k){
            int number=0;
            for(int bit=0;bit<31;bit++){
                if(bitCount[bit]){
                    bitCount[bit]--;
                    number=number|(1<<bit);
                }
            }
            maxSum=(1LL*maxSum+1LL*number*number%mod)%mod;
            k--;
        }   
        return maxSum;
    }
};

int main(){

return 0;
}