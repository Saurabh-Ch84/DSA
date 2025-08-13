#include<iostream>
#include<vector>
using namespace std;

class NumArray {
    vector<int> segTree;
    int n;
    void buildTree(vector<int> &nums,int low,int high,int indx){
        if(low==high){
            segTree[indx]=nums[low];
            return ;
        }
        int mid=low+(high-low)/2;
        buildTree(nums,low,mid,2*indx+1);
        buildTree(nums,mid+1,high,2*indx+2);
        segTree[indx]=segTree[2*indx+1]+segTree[2*indx+2];
    }
    
    void updateTree(int low,int high,int indx,int i,int value){
        if(low==high){
            segTree[indx]=value;
            return ;
        }
        int mid=low+(high-low)/2;
        if(i<=mid) updateTree(low,mid,2*indx+1,i,value);
        else updateTree(mid+1,high,2*indx+2,i,value);
        segTree[indx]=segTree[2*indx+1]+segTree[2*indx+2];
    }
    
    int query(int low,int high,int l,int r,int indx){
        //noOverlap
        if(low>r || high<l) return 0;
        //totalOverlap
        if(low>=l && high<=r) return segTree[indx];
        //partialOverlap
        int mid=low+(high-low)/2;
        int left=query(low,mid,l,r,2*indx+1);
        int right=query(mid+1,high,l,r,2*indx+2);
        return left+right;
    }
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        segTree.resize(4*n+1);
        buildTree(nums,0,n-1,0);
    }
    
    void update(int index, int val) {
        updateTree(0,n-1,0,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,n-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(){

return 0;
}