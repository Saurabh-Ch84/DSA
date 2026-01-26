#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
  public:
    int findWays(int n) {
        // code here
        if(n%2==1) return 0;
        vector<int> ans(n+1,0);
        ans[0]=1;
        for(int i=2;i<=n;i+=2){
            for(int j=0;j<=i-2;j+=2)
                ans[i]+=ans[j]*ans[i-2-j];
        }
        return ans[n];
    }
};

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minDiff=INT_MAX, n=nums.size(), left=0, right=0;
        while(right<n){
            if(right-left+1==k){
                int diff=nums[right]-nums[left];
                minDiff=min(minDiff,diff);
                left++;
            }
            right++;
        }
        return minDiff;
    }
};

int main(){

return 0;
}