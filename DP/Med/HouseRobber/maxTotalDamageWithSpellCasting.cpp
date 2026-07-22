#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long memoization(vector<int> &power,unordered_map<int,int> &freqMap,
                        unordered_map<int, long long> &dp,int n,int i)
    {
        if(i>=n) return 0;
        if(dp.count(i)) return dp[i];
        int freq=freqMap[power[i]];
        long long notTake=memoization(power,freqMap,dp,n,i+freq);
        int j=i+freq;
        while(j<n && power[j]<=2+power[i]) 
            j+=freqMap[power[j]];
        long long take=(long long)power[i]*freq+memoization(power,freqMap,dp,n,j);
        return dp[i]=max(take,notTake);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int> freqMap;
        for(int &p:power) 
            freqMap[p]++;
        
        sort(power.begin(),power.end());
        int n=power.size();
        unordered_map<int,long long> dp;
        return memoization(power,freqMap,dp,n,0);
    }
};

int main(){

return 0;
}