#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int n;
    vector<int> segTree,nums;
    void buildTree(int low,int high,int idx){
        if(low==high){
            segTree[idx]=low;
            return ;
        }
        int mid=low+(high-low)/2;
        buildTree(low,mid,2*idx+1);
        buildTree(mid+1,high,2*idx+2);
        if(nums[segTree[2*idx+1]]>=nums[segTree[2*idx+2]])
            segTree[idx]=segTree[2*idx+1];
        else segTree[idx]=segTree[2*idx+2];
    }
    int queryTree(int low,int high,int idx,int left,int right){
        if(low>right || high<left) return -1;
        if(low>=left && high<=right) return segTree[idx];
        int mid=low+(high-low)/2;
        int leftAns=queryTree(low,mid,2*idx+1,left,right);
        int rightAns=queryTree(mid+1,high,2*idx+2,left,right);
        if(leftAns==-1) return rightAns;
        if(rightAns==-1) return leftAns;
        if(nums[leftAns]>=nums[rightAns]) return leftAns;
        return rightAns;
    }
        public:
    SegmentTree(vector<int> &nums){
        this->nums=nums;
        n=nums.size();
        segTree.resize(4*n,0);
        buildTree(0,n-1,0);
    }

    int query(int maxE,int maxI){
        int ans=INT_MAX;
        int left=maxI+1,right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int ansIndx=queryTree(0,n-1,0,left,mid);
            if(ansIndx!=-1 && nums[ansIndx]>maxE){
                ans=min(ans,ansIndx);
                right=mid-1;
            }
            else left=mid+1;
        }
        return (ans==INT_MAX)?-1:ans;
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        SegmentTree sgt(heights);
        vector<int> ans;
        for(vector<int> &query:queries){
            sort(query.begin(),query.end());
            int aliceIdx=query[0],bobIdx=query[1];
            int maxBuilding=max(heights[aliceIdx],heights[bobIdx]);
            if(aliceIdx==bobIdx || maxBuilding>heights[aliceIdx]){
                ans.push_back(bobIdx);
                continue;
            }
            ans.push_back(sgt.query(maxBuilding,bobIdx));
        }
        return ans;
    }
};

int main(){

return 0;
}