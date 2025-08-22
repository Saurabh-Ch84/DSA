#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int n;
    vector<long long> segTree;
    void updateTree(int low,int high,int idx,int i){
        if(low==high){
            segTree[idx]+=1;
            return ;
        }
        int mid=low+(high-low)/2;
        if(i<=mid) updateTree(low,mid,2*idx+1,i);
        else updateTree(mid+1,high,2*idx+2,i);
        segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
    }
    long long queryTree(int low,int high,int idx,int left,int right){
        if(low>right || high<left) return 0LL;
        if(low>=left && high<=right) return segTree[idx];
        int mid=low+(high-low)/2;
        long long leftAns=queryTree(low,mid,2*idx+1,left,right);
        long long rightAns=queryTree(mid+1,high,2*idx+2,left,right);
        return leftAns+rightAns;
    }
        public:
    SegmentTree(int n){
        this->n=n;
        segTree.resize(4*n,0);
    }
    long long query(int lb,int ub){
        long long ans=queryTree(0,n-1,0,lb,ub);
        updateTree(0,n-1,0,ub);
        return ans;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        SegmentTree sgt(n);
        unordered_map<int,int> hashMap;
        
        for(int i=0;i<n;i++)
            hashMap[nums2[i]]=i;
        
        long long count=0;
        for(int i=0;i<n;i++){
            int idx=hashMap[nums1[i]];
            int leftCommonCount=sgt.query(0,idx);
            int leftUncommonCount=i-leftCommonCount;
            int numsAfterIndxNums2=(n-1)-idx;
            int rightCommonCount=numsAfterIndxNums2-leftUncommonCount;
            count+=max(0LL,1LL*leftCommonCount*rightCommonCount);
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> v1={2,0,1,3},v2={0,1,2,3};
    cout<<s.goodTriplets(v1,v2);
return 0;
}