#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool frequencyBalanced(unordered_map<int,int> &hashMap,map<int,int> &freqMap){
        if(hashMap.size()==1) return true;
        if(freqMap.size()!=2) return false;
        return (freqMap.begin()->first*2==freqMap.rbegin()->first);
    }
public:
    int getLength(vector<int>& nums) {
        int maxi=1, n=nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int> hashMap;
            map<int,int> freqMap;
            freqMap[1]++;
            hashMap[nums[i]]++;
            for(int j=i+1;j<n;j++){
                int oldF=hashMap[nums[j]];
                if(oldF){
                    freqMap[oldF]--;
                    if(!freqMap[oldF]) freqMap.erase(oldF);
                }
                hashMap[nums[j]]++;
                int newF=hashMap[nums[j]];
                freqMap[newF]++;
                if(frequencyBalanced(hashMap,freqMap))
                    maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};

int main(){

return 0;
}