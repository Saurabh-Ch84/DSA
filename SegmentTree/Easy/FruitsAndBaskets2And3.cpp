#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    class SegmentTree{
        vector<int> segTree;
        void build(int idx,int low,int high,vector<int> &arr){
            if(low==high){
                segTree[idx]=arr[low];
                return ;
            }
            int mid=(low+high)/2;
            build(2*idx+1,low,mid,arr);
            build(2*idx+2,mid+1,high,arr);
            segTree[idx]=max(segTree[2*idx+1],segTree[2*idx+2]);
        }
            public:
        SegmentTree(vector<int> &arr){
            int n=arr.size();
            segTree.resize(4*n+1);
            build(0,0,n-1,arr);
        }
        
        int queryUpdate(int idx,int low,int high,int num){
            if(segTree[idx]<num || segTree[idx]==-1) return -1;
            if(low==high){
                segTree[idx]=-1;
                return low;
            }
            int mid=(low+high)/2;
            int pos=(segTree[2*idx+1]>=num)?queryUpdate(2*idx+1,low,mid,num):queryUpdate(2*idx+2,mid+1,high,num);
            segTree[idx]=max(segTree[2*idx+1],segTree[2*idx+2]);
            return pos;
        }
    };
            public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree sgt(baskets);
        int n=baskets.size(),unPlaced=0;
        for(int &fruit:fruits){
            int basketIndx=sgt.queryUpdate(0,0,n-1,fruit);
            if(basketIndx==-1) unPlaced++;
        }
        return unPlaced;
    }
};

int main(){

return 0;
}