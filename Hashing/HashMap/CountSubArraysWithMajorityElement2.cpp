#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        hashMap[0]=1;
        int n=nums.size();
        long long count=0, validLeftPoints=0, cumSum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                validLeftPoints+=hashMap[cumSum];
                cumSum+=1;
            }
            else{
                cumSum-=1;
                validLeftPoints-=hashMap[cumSum];
            }
            hashMap[cumSum]++;
            count+=validLeftPoints;
        }
        return count;
    }
};

int main(){

return 0;
}