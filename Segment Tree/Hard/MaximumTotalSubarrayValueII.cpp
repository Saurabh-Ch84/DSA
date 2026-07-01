#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vll=vector<long long>;
    using piint=pair<int,int>;
    using vpiint=vector<piint>;
    
    class SegmentTree{
        void buildTree(int idx,int low,int high,vint &nums){
            if(low==high){
                sgt[idx]={nums[low],nums[low]};
                return ;
            }
            int mid=low+(high-low)/2;
            buildTree(2*idx+1,low,mid,nums);
            buildTree(2*idx+2,mid+1,high,nums);
            sgt[idx].first=max(sgt[2*idx+1].first,sgt[2*idx+2].first);
            sgt[idx].second=min(sgt[2*idx+1].second,sgt[2*idx+2].second);
        }
            public:
        vpiint sgt;
        int n;
        SegmentTree(vint &nums){
            n=nums.size();
            sgt.resize(4*n+1);
            buildTree(0,0,n-1,nums);
        }
        piint queryTree(int idx,int low,int high,int left,int right){
            if(right<low || left>high) return {-1e9,1e9};
            if(low>=left && high<=right) return sgt[idx];
            int mid=low+(high-low)/2;
            piint leftQuery=queryTree(2*idx+1,low,mid,left,right);
            piint rightQuery=queryTree(2*idx+2,mid+1,high,left,right);
            return {
                max(leftQuery.first,rightQuery.first),
                min(leftQuery.second,rightQuery.second)
            };
        }   
        long long query(int left,int right){
            piint ans=queryTree(0,0,n-1,left,right);
            return 1LL*(ans.first-ans.second);
        }
    };
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        SegmentTree sgt(nums);
        priority_queue<vll> pq;
        int n=nums.size();
        for(int l=0;l<n;l++)
            pq.push({sgt.query(l,n-1),l,n-1});
        
        long long value=0;
        while(k-- && !pq.empty()){
            vll entry=pq.top();
            pq.pop();
            value+=entry[0];
            if(entry[2]>entry[1])
                pq.push({sgt.query(entry[1],entry[2]-1),entry[1],entry[2]-1});
        }
        return value;
    }
};

int main(){

return 0;
}