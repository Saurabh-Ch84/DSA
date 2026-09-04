#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> suffixMin(n);
        suffixMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            suffixMin[i]=min(nums[i],suffixMin[i+1]);
        int prefixMax=0, ans=-1;
        for(int i=0;i<n;i++){
            prefixMax=max(prefixMax,nums[i]);
            if(prefixMax-suffixMin[i]<=k){
                ans=i;
                break;
            }
        }
        return ans;
    }
};

int main(){

return 0;
}