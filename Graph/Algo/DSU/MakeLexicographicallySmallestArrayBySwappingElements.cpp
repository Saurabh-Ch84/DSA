#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vpint=vector<pair<int,int>>;
using minHeap=priority_queue<int,vint,greater<int>> ;

class Solution1 {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vpint arr;
        for(int i=0;i<n;i++)
            arr.push_back({nums[i],i});

        sort(arr.begin(),arr.end());
        int i=0;
        vint res(n,-1);
        while(i<n){
            int j=i;
            vint values, indices;
            while(j<n && (j==i || arr[j].first-arr[j-1].first<=limit)){
                values.push_back(arr[j].first);
                indices.push_back(arr[j].second);
                j++;
            }
            sort(indices.begin(),indices.end());
            // values are already sorted.
            int m=indices.size();
            for(int k=0;k<m;k++)
                res[indices[k]]=values[k];
            i=j;
        }
        return res;
    }
};

class Solution2 {
    // better.
    class DSU{
        int c;
        vint parent, size;
            public:
        DSU(int n):c(n){
            size.resize(n,1);
            parent.resize(n,-1);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        void unionBySize(int u,int v){
            int U=find(u), V=find(v);
            if(U==V) return;
            if(size[U]>=size[V]){
                size[U]+=size[V];
                parent[V]=U;
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
            }
            c--;
        }
        int find(int u){
            if(u==parent[u])
                return u;
            return parent[u]=find(parent[u]);
        }
    };
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vpint arr;
        for(int i=0;i<n;i++)
            arr.push_back({nums[i],i});

        sort(arr.begin(),arr.end());
        DSU ds(n);
        for(int i=0;i<n;i++){
            if(i<n-1 && abs(arr[i].first-arr[i+1].first)<=limit)
                ds.unionBySize(arr[i].second,arr[i+1].second);
        }

        unordered_map<int,minHeap> componentMinHeap;
        for(int i=0;i<n;i++){
            int parent=ds.find(i), val=nums[i];
            componentMinHeap[parent].push(val);
        }

        vint res(n,-1);
        for(int i=0;i<n;i++){
            int parent=ds.find(i);
            minHeap &component=componentMinHeap[parent];
            int minInComponent=component.top();
            component.pop();
            res[i]=minInComponent;
        }
        return res;
    }
};

int main(){

return 0;
}