#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();

        map<int,int> diffMap;
        unordered_map<int,int> freqMap;

        for(int i=0;i<n;i++){
            freqMap[nums[i]]++;
            int l=max(nums[i]-k,0);
            int r=nums[i]+k;

            diffMap[l]++;
            diffMap[r+1]--;
            diffMap[nums[i]]+=0;
        }

        int maxFreq=1,cumSum=0;
        for(auto it=diffMap.begin();it!=diffMap.end();it++){
            int target=it->first;
            it->second+=cumSum;
            
            int targetFreq=freqMap[target];
            int needConversion=it->second - targetFreq;
            int possible=min(numOperations,needConversion);

            maxFreq=max(maxFreq,targetFreq+possible);
            cumSum=it->second;
        }
        return maxFreq;
    }
};

int main(){

return 0;
}