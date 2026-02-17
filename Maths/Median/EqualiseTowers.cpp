#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using pii=pair<int,int>;
using vpii=vector<pii>;
class Solution {
    int getCost(vpii &arr,int median,int n){
        int cost=0;
        for(auto &p: arr){
            int diff=abs(p.first-median);
            cost+=diff*p.second;
        }
        return cost;
    }
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        vpii arr;
        int sum=0, n=cost.size();
        for(int i=0;i<n;i++){
            arr.push_back({heights[i],cost[i]});
            sum+=cost[i];
        }
        sort(arr.begin(),arr.end());
        // weighted Median
        int median=0, halfSum=0, ptr=0;
        while(halfSum<(sum+1)/2 && ptr<n){
            halfSum+=arr[ptr].second;
            median=arr[ptr].first;
            ptr++;
        }
        
        return getCost(arr,median,n);
    }
};


int main(){

return 0;
}