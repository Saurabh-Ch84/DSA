#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vll=vector<long long>;
    using vvint=vector<vint>;
    class DSU{
        vll parent,size;
            public:
        DSU(int n){
            parent.resize(n,-1);
            size.resize(n,1);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        long long find(int i){
            if(parent[i]==i) return i;
            return parent[i]=find(parent[i]);
        }
        void unionBySize(int u,int v){
            long long U=find(u), V=find(v);
            if(U==V) return ;
            if(size[U]>size[V]){
                parent[V]=U;
                size[U]+=V;
            }
            else{
                parent[U]=V;
                size[V]+=U;
            }
        }
    };
    int binarySearch(vvint &arr,int i){
        int j=-1, low=0, high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(i>arr[mid][2]) low=mid+1;
            else if(i<arr[mid][1]) high=mid-1;
            else if(i>=arr[mid][1] && i<=arr[mid][2]){
                j=arr[mid][0];
                break;
            }
        }
        return j;
    }
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        DSU ds(n);
        vvint arr;
        arr.push_back({0,minJump,maxJump});
        for(int i=1;i<n;i++){
            if(s[i]=='1') continue;
            int j=binarySearch(arr,i);
            if(j!=-1){
                ds.unionBySize(j,i);
                int left=i+minJump;
                int right=min(n-1,i+maxJump);
                if(left<=right) arr.push_back({i,left,right});
            }
        }
        return (ds.find(0)==ds.find(n-1));
    }
};

int main(){

return 0;
}