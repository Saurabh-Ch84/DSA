#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//more optimal
class Solution1 {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left=0,right=0,n=nums.size();
        int maxi=0,sum=0;
        unordered_set<int> hashSet;
        while(right<n){
            int num=nums[right];
            while(left<n && hashSet.count(num)){
                hashSet.erase(nums[left]);
                sum-=nums[left++];
            }
            sum+=num;
            hashSet.insert(num);
            maxi=max(maxi,sum);
            right++;
        }
        return maxi;
    }
};

//optimal
class Solution2 {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left=0,right=0,n=nums.size();
        int maxSum=0,currSum=0;
        unordered_map<int,int> hashMap;
        while(right<n){
            int num=nums[right];
            while(left<n && hashMap.find(num)!=hashMap.end()){
                hashMap.erase(nums[left]);
                currSum-=nums[left++];
            }
            currSum+=num;
            hashMap[num]=right++;
            maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }
};

int main(){

return 0;
}