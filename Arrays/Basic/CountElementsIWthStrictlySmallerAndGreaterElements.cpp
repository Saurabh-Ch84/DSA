#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=1, right=n-2;
        while(left<n && nums[left]==nums.front()) left++;
        while(right>=0 && nums[right]==nums.back()) right--;
        return max(0,right-left+1);
    }
};

class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN, mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=maxi && nums[i]!=mini)
                count++;
        }
        return count;
    }
};

int main(){

return 0;
}