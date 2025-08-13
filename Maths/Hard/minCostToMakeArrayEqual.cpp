#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long findCost(vector<pair<int,int>> &numsAndCost,int target,int n){
        long long cost=0;
        for(int i=0;i<n;i++)
            cost+=1LL*abs(numsAndCost[i].first-target)*numsAndCost[i].second;
        return cost;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        vector<pair<int,int>> numsAndCost;
        for(int i=0;i<n;i++)
            numsAndCost.push_back({nums[i],cost[i]});
        
        sort(numsAndCost.begin(),numsAndCost.end());
        long long sumOfCosts=0;
        for(int i=0;i<n;i++)
            sumOfCosts+=cost[i];
        
        //weighted median
        int mid=0,median=0,i=0;
        while(mid<(sumOfCosts+1)/2 && i<n){
            mid+=numsAndCost[i].second;
            median=numsAndCost[i].first;
            i++;
        }
        return findCost(numsAndCost,median,n);
    }
};

int main(){

return 0;
}