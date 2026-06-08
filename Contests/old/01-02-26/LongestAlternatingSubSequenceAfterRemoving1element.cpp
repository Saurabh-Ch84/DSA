#include<iostream>
#include<vector>
using namespace std;

using vi=vector<int> ;
using vvi=vector<vi>;

class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n=nums.size();
        vvi left(n,vi(2,1));
        vvi right(n,vi(2,1));
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])
                left[i][0]=left[i-1][1]+1;
            else if(nums[i]<nums[i-1])
                left[i][1]=left[i-1][0]+1;
            ans=max(ans,left[i][1]);
            ans=max(ans,left[i][0]);
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1])
                right[i][0]=right[i+1][1]+1;
            else if(nums[i]<nums[i+1])
                right[i][1]=right[i+1][0]+1;
        }
        for(int i=1;i<n-1;i++){
            if(nums[i-1]>nums[i+1])
                ans=max(ans,left[i-1][0]+right[i+1][1]);
            else if(nums[i-1]<nums[i+1])
                ans=max(ans,left[i-1][1]+right[i+1][0]);
        }
        return ans;
    }
};

int main(){

return 0;
}