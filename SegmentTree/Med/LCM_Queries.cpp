#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b){
    while(b){
        long long t=b;
        b=a%b;
        a=t;
    }
    return a;
}

long long lcm(long long a,long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

class Solution {
    using vint=vector<int>;
    using vll=vector<long long>;
    class SegmentTree{
        vll seg;
        int n;
        void buildTree(int idx,int low,int high,vint &arr){
            if(low==high){
                seg[idx]=arr[low];
                return ;
            }
            int mid=low+(high-low)/2;
            buildTree(2*idx+1,low,mid,arr);
            buildTree(2*idx+2,mid+1,high,arr);
            seg[idx]=lcm(seg[2*idx+1],seg[2*idx+2]);
        }
        
        void update(int idx,int low,int high,int i,int val){
            if(low==high){
                seg[idx]=val;
                return ;
            }
            int mid=low+(high-low)/2;
            if(i<=mid) update(2*idx+1,low,mid,i,val);
            else update(2*idx+2,mid+1,high,i,val);
            seg[idx]=lcm(seg[2*idx+1],seg[2*idx+2]);
        }
        
        long long query(int idx,int low,int high,int l,int r){
            if(r<low || high<l) return 1;
            if(l<=low && high<=r) return seg[idx];
            int mid=low+(high-low)/2;
            long long left=query(2*idx+1,low,mid,l,r);
            long long right=query(2*idx+2,mid+1,high,l,r);
            if(left==1) return right;
            if(right==1) return left;
            return lcm(left,right);
        }
            public:
        SegmentTree(vint &arr){
            n=arr.size();
            seg.resize(4*n+1);
            buildTree(0,0,n-1,arr);
        }
        
        
        void updateQuery(int i,int val){
            update(0,0,n-1,i,val);
        }
        
        long long lcmQuery(int l,int r){
            return query(0,0,n-1,l,r);
        }
    };
  public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        SegmentTree sgt(arr);
        vll res;
        for(vint &q: queries){
            if(q[0]==1) sgt.updateQuery(q[1],q[2]);
            else res.push_back(sgt.lcmQuery(q[1],q[2]));
        }
        return res;
    }
};

int main(){

return 0;
}