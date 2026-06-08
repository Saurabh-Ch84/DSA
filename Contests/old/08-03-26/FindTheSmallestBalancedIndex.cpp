#include<iostream>
#include<vector>
using namespace std;

using vll=vector<long long>;
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size(), idx=-1;
        vll prefixSum(n,0), prefixMul(n,1);
        prefixSum[0]=nums[0], prefixMul[0]=nums[0];

        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
            prefixMul[i]=prefixMul[i-1]*nums[i];
        }

        for(int i=0;i<n;i++){
            long long leftSum=(i? prefixSum[i-1]: 0);
            long long rightProduct=prefixMul[n-1]/prefixMul[i];
            if(leftSum==rightProduct){
                idx=i;
                break;
            }
        }
        return idx;
    }
};

int main(){

return 0;
}