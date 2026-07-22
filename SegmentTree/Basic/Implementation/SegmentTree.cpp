#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class SegmentTree{
    vector<int> segTree;
    int n;

    void build(int indx,int low,int high,vector<int> &arr){
        if(low==high){
            segTree[indx]=arr[low];
            return ;
        }
        int mid=low+(high-low)/2;
        build(2*indx+1,low,mid,arr);
        build(2*indx+2,mid+1,high,arr);
        segTree[indx]=min(segTree[2*indx+1],segTree[2*indx+2]);
    }

    int query(int indx,int low,int high,int left,int right){
        // no-overlap 
        if(right<low || left>high) return INT_MAX;
        if(low>=left && high<=right) return segTree[indx];
        int mid=low+(high-low)/2;
        int leftQuery=query(2*indx+1,low,mid,left,right);
        int rightQuery=query(2*indx+2,mid+1,high,left,right);
        return min(leftQuery,rightQuery);
    }

    void updateTree(int indx,int low,int high,int i,int value){
        if(low==high){
            segTree[indx]=value;
            return ;
        }
        int mid=low+(high-low)/2;
        if(i<=mid) updateTree(2*indx+1,low,mid,i,value);
        else updateTree(2*indx+2,mid+1,high,i,value);
        segTree[indx]=min(segTree[2*indx+1],segTree[2*indx+2]);
    }
        public:
    SegmentTree(vector<int> &arr){
        n=arr.size();
        segTree.resize(4*n+1);
        build(0,0,n-1,arr);
    }

    //point updates
    void update(int index,int value){
        updateTree(0,0,n-1,index,value);
    }

    int getMinQuery(int left,int right){
        return query(0,0,n-1,left,right);
    }
};


int main(){

return 0;
}