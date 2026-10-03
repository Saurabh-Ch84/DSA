#include<bits/stdc++.h>
using namespace std;

int gcdEuclidean(int a,int b){
    while(b){
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

class Solution {
    class SegmentTree{
        vector<int> sgt;
        int n;
        void buildTree(int i,int low,int high,vector<int> &arr){
            if(low==high){
                sgt[i]=arr[low];
                return;
            }
            int mid=low+(high-low)/2;
            buildTree(2*i+1,low,mid,arr);
            buildTree(2*i+2,mid+1,high,arr);
            sgt[i]=gcdEuclidean(sgt[2*i+1],sgt[2*i+2]);
        }
        int query(int i,int low,int high,int left,int right){
            if(low>right || high<left) return 0;
            if(low>=left && high<=right) return sgt[i];
            int mid=low+(high-low)/2;
            int leftRes=query(2*i+1,low,mid,left,right);
            int rightRes=query(2*i+2,mid+1,high,left,right);
            return gcdEuclidean(leftRes,rightRes);
        }
        void update(int i,int low,int high,int index,int val){
            if(low==high && low==index){
                sgt[i]=val;
                return ;
            }
            int mid=low+(high-low)/2;
            if(index<=mid) update(2*i+1,low,mid,index,val);
            else update(2*i+2,mid+1,high,index,val);
            sgt[i]=gcdEuclidean(sgt[2*i+1],sgt[2*i+2]);
        }
            public:
        SegmentTree(vector<int> &arr){
            n=arr.size();
            sgt.resize(4*n+1,1);
            buildTree(0,0,n-1,arr);
        }
        int gcdQuery(int left,int right){
            return query(0,0,n-1,left,right);
        }
        void updateQuery(int index,int val){
            update(0,0,n-1,index,val);
        }
    };
  public:
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int q=queries.size();
        SegmentTree sgt(arr);
        vector<int> res;
        for(int i=0;i<q;i++){
            int type=queries[i][0];
            if(type==0){
                int left=queries[i][1], right=queries[i][2];
                int g=sgt.gcdQuery(left,right);
                res.push_back(g);
            } 
            else{
                int index=queries[i][1], val=queries[i][2];
                sgt.updateQuery(index,val);
            }
        }
        return res;
    }
};

int main(){

return 0;
}