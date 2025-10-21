#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void buildFreqArr(vector<int> &nums,vector<int> &freqArr,int maxi){
        for(int &num: nums) freqArr[num]++;
        for(int i=1;i<=maxi;i++)
            freqArr[i]+=freqArr[i-1];
    }
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi=*max_element(nums.begin(),nums.end())+k;
        vector<int> freqArr(maxi+1,0);
        buildFreqArr(nums,freqArr,maxi);

        int maxFreq=1;
        for(int target=0;target<=maxi;target++){
            if(freqArr[target]==0) continue;

            int lb=max(0,target-k);
            int ub=min(maxi,target+k);

            int totalCount=freqArr[ub]-(lb>0 ? freqArr[lb-1] : 0);
            int targetCount=freqArr[target]-(target>0 ? freqArr[target-1] : 0);

            int needConversion=totalCount-targetCount;
            int maxPossibleFreq=targetCount+min(needConversion,numOperations);

            maxFreq=max(maxFreq,maxPossibleFreq);
        }
        return maxFreq;
    }
};

int main(){

return 0;
}