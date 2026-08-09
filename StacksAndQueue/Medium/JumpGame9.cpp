#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    class DSU{
            public:
        vint size, parent, maxim;
        DSU(int n,vint &nums){
            maxim.resize(n);
            size.resize(n,1);
            parent.resize(n,-1);
            for(int i=0;i<n;i++){
                parent[i]=i;
                maxim[i]=nums[i];
            }
        }
        int find(int u){
            if(parent[u]==u) return u;
            return parent[u]=find(parent[u]);
        }
        void unionBySize(int u,int v){
            int U=find(u), V=find(v);
            if(U==V) return;
            if(size[U]>size[V]){
                parent[V]=U;
                maxim[U]=max(maxim[U],maxim[V]);
                size[U]+=size[V];
            }
            else{
                parent[U]=V;
                maxim[V]=max(maxim[V],maxim[U]);
                size[V]+=size[U];
            }
        }
    };
public:
    vector<int> maxValue(vector<int>& nums){
        int n=nums.size();
        DSU ds(n,nums);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && ds.maxim[st.top()]>nums[i]){
                ds.unionBySize(st.top(),i);
                st.pop();
            }
            st.push(ds.find(i));
        }

        vint res;
        for(int i=0;i<n;i++){
            int r=ds.find(i);
            res.push_back(ds.maxim[r]);
        }
        return res;
    }
};

int main(){

return 0;
}