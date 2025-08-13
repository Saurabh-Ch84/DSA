#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_set>
using namespace std;

//ooptimal approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int &num:nums)
            numSet.insert(num);
        int maxLen=0,len=0;
        for(const int &num:numSet){
            int number=num;
            if(numSet.count(number-1)) continue;
            else while(numSet.count(number++)) len++;
            maxLen=max(maxLen,len);
            len=0;
        }
        return maxLen;
    }
};

//Better solution
class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0) return 0;
        int lastSmall=INT_MIN,maxLen=1,len=0,left=0;
        while(left<n){
            int num=nums[left];
            if(num==lastSmall+1){
                len+=1;
                maxLen=max(len,maxLen);
            }
            else if(num!=lastSmall) len=1;    
            lastSmall=num;
            left++;
        }
        return maxLen;
    }
};

int main(){

return 0;
}