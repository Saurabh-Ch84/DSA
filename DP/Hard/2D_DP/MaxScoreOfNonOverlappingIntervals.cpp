#include<bits/stdc++.h>
using namespace std;

struct Selected{
    long long weightSum=0;
    vector<int> indices;
};
class Solution {
    vector<vector<Selected>> memo;
    int customBinarySearch(vector<vector<int>>& intervals,int x,int low,int high){
        int ansIdx=high+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(intervals[mid][0]>x){
                ansIdx=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ansIdx;
    }
    Selected recursion(int i,int k,int n,vector<vector<int>>& intervals,vector<int> &nextIdx){
        if(i==n || !k) return memo[i][k]={0,{}};
        if(memo[i][k].weightSum!=-1) return memo[i][k];
        Selected skip=recursion(i+1,k,n,intervals,nextIdx);
        int j=nextIdx[i];
        Selected take=recursion(j,k-1,n,intervals,nextIdx);
        take.weightSum+=intervals[i][2];
        take.indices.push_back(intervals[i][3]);
        sort(take.indices.begin(),take.indices.end());
        if(skip.weightSum!=take.weightSum)
            return memo[i][k]=(take.weightSum>skip.weightSum? take: skip);
        else
            return memo[i][k]=(take.indices<skip.indices? take: skip);
    }
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        for(int i=0;i<n;i++)
            intervals[i].push_back(i);
        sort(intervals.begin(),intervals.end());
        vector<int> nextIdx(n,n);
        for(int i=0;i<n;i++){
            int endTime=intervals[i][1];
            int k=customBinarySearch(intervals,endTime,i+1,n-1);
            nextIdx[i]=k;
        }
        memo.assign(n+1,vector<Selected>(4+1,{-1,{}}));
        return recursion(0,4,n,intervals,nextIdx).indices;
    }
};

int main(){

return 0;
}