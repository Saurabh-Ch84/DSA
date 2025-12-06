#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++)
            sum=(sum%p+nums[i]%p)%p;
        if(sum==0) return 0;

        int target=sum;
        unordered_map<int,int> hashMap;
        hashMap[0]=-1;
        int currSum=0,mini=n;

        for(int i=0;i<n;i++){
            currSum=(currSum%p+nums[i]%p)%p;
            int rem=(currSum-target+p)%p;
            if(hashMap.count(rem))
                mini=min(mini,i-hashMap[rem]);
            hashMap[currSum]=i;
        }

        return (mini==n)? -1: mini;
    }
};

int main(){

return 0;
}