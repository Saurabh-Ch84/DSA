#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int n;
    vector<int> segTree, lazyTree;
    void buildTree(int i,int low,int high){
        if(low==high){
            segTree[i]=0;
            return;
        }
        int mid=low+(high-low)/2;
        buildTree(2*i+1,low,mid);
        buildTree(2*i+2,mid+1,high);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    int findSum(int i,int low,int high,int left,int right){
        propagate(i,low,high);
        if(low>right || high<left) return 0;
        if(low>=left && high<=right) return segTree[i];
        int mid=low+(high-low)/2;
        int leftSum=findSum(2*i+1,low,mid,left,right);
        int rightSum=findSum(2*i+2,mid+1,high,left,right);
        return leftSum+rightSum;
    }
    void propagate(int i,int low,int high){
        if(lazyTree[i]){
            segTree[i] = (high - low + 1) - segTree[i];
            if(low!=high){
                lazyTree[2*i+1] ^= 1;
                lazyTree[2*i+2] ^= 1;
            }
        }
        lazyTree[i]=0;
    }
    void makeUpdates(int i,int low,int high,int left,int right){
        propagate(i,low,high);
        if(low>right || high<left) return ;
        if(low>=left && high<=right){
            lazyTree[i]^=1;
            propagate(i,low,high);
            return ;
        }
        int mid=low+(high-low)/2;
        makeUpdates(2*i+1,low,mid,left,right);
        makeUpdates(2*i+2,mid+1,high,left,right);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
        public:
    SegmentTree(int n):n(n){
        segTree.resize(4*n+1,0);
        lazyTree.resize(4*n+1,0);
        buildTree(0,0,n-1);
    }
    void rangeUpdateQuery(int A,int B){
        makeUpdates(0,0,n-1,A,B);
    }
    int rangeSumQuery(int A,int B){
        return findSum(0,0,n-1,A,B);
    }
};

int main(){
    int N,Q;
    cin>>N>>Q;
    SegmentTree sgt(N);
    for(int i=0;i<Q;i++){
        int T, A, B;
        cin>>T>>A>>B;
        if(T) cout<<sgt.rangeSumQuery(A,B)<<endl;
        else sgt.rangeUpdateQuery(A,B);
    }
return 0;
}