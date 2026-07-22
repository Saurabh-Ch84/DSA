#include<bits/stdc++.h>
using namespace std;


class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    class SegmentTree{
        vint segmentTree;
        int n;
        void buildTree(int idx,int low,int high,vint &arr){
            if(low==high){
                segmentTree[idx]=arr[low];
                return ;
            }
            int mid=low+(high-low)/2;
            buildTree(2*idx+1,low,mid,arr);
            buildTree(2*idx+2,mid+1,high,arr);
            segmentTree[idx]=max(segmentTree[2*idx+1],segmentTree[2*idx+2]);
        }
        int query(int idx,int low,int high,int l,int r){
            if(low>r || high<l) return -1;
            if(low>=l && high<=r) return segmentTree[idx];
            int mid=low+(high-low)/2;
            int leftTreeQuery=query(2*idx+1,low,mid,l,r);
            int rightTreeQuery=query(2*idx+2,mid+1,high,l,r);
            return max(leftTreeQuery,rightTreeQuery);
        }
            public:
        SegmentTree(vint &arr){
            n=arr.size();
            // Edge case: if arr is empty, don't crash
            if (n == 0) return; 
            segmentTree.resize(4*n+1,-1);
            buildTree(0,0,n-1,arr);
        }

        int rangeQuery(int l,int r){
            if(l>r || n == 0) return -1;
            return query(0,0,n-1,l,r);
        }
    };
public:
    vint maxActiveSectionsAfterTrade(string s,vvint &queries) {
        int n=s.length(), activeSection=0, zero=0, ptr=0;
        vint blockStart, blockEnd, blockSize;
        while(ptr<n){
            if(s[ptr]=='1'){
                if(zero){
                    blockEnd.push_back(ptr-1);
                    blockSize.push_back(blockEnd.back()-blockStart.back()+1);
                    zero=0;
                }
                activeSection++;
            }
            else{
                if(!zero) blockStart.push_back(ptr);
                zero++;
            }
            ptr++;
        }

        if(zero){
            blockEnd.push_back(n-1);
            blockSize.push_back(blockEnd.back()-blockStart.back()+1);
        }

        int m=queries.size(), k=blockSize.size();
        if(k<2) return vint(m,activeSection);

        vint arr;
        for(int i=0;i<k-1;i++){
            int pairSum=blockSize[i]+blockSize[i+1];
            arr.push_back(pairSum);
        }

        SegmentTree sgt(arr);
        vint res(m,-1);
        for(int i=0;i<m;i++){
            int l=queries[i][0], r=queries[i][1];
            int low=lower_bound(blockEnd.begin(),blockEnd.end(),l)-blockEnd.begin();
            int high=upper_bound(blockStart.begin(),blockStart.end(),r)-blockStart.begin()-1;

            int maxPairSum=0;
            if(low<high){
                int firstBlockLength=blockEnd[low]-max(blockStart[low],l)+1;
                int lastBlockLength=min(blockEnd[high],r)-blockStart[high]+1;
                if(high-low+1==2)
                    maxPairSum=firstBlockLength+lastBlockLength;
                else{
                    int firstPairSum=firstBlockLength+blockSize[low+1];
                    int lastPairSum=blockSize[high-1]+lastBlockLength;
                    // FIX: Query up to high-2, because index x represents sum of block x and x+1
                    int remainingMaxPairSum=sgt.rangeQuery(low+1,high-2);
                    maxPairSum=max({firstPairSum, lastPairSum, remainingMaxPairSum});
                }
            }
            res[i]=activeSection+maxPairSum;
        }
        return res;
    }
};

int main(){

return 0;
}