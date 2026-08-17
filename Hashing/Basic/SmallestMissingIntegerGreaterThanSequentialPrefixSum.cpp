#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();

        int maxLen=1, maxLenSum=nums[0];
        int currLen=1, currSum=nums[0];
        unordered_set<int> hashSet;
        hashSet.insert(nums[0]);

        bool flag=1;
        for(int i=1;i<n;i++){
            if(flag && nums[i]==nums[i-1]+1){
                currLen++;
                currSum+=nums[i];
            }
            else flag=0;
            if(flag && currLen>maxLen){
                maxLen=currLen;
                maxLenSum=currSum;
            }
            hashSet.insert(nums[i]);
        }

        int target=maxLenSum;
        while(hashSet.count(target))
            target++;

        return target;
    }
};

int main(){

return 0;
}