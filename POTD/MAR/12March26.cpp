#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

using vint=vector<int>;
class Solution1 {
    class DSU{
        vint size, parent;
        int n;
            public:
        DSU(int n){
            this->n=n;
            size.resize(n,1);
            parent.resize(n,-1);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }

        int find(int node){
            if(node==parent[node])
                return node;
            return parent[node]=find(parent[node]);
        }

        bool unionBySize(int u,int v){
            int U=find(u);
            int V=find(v);
            if(U==V) return false;
            if(size[U]>=size[V]){
                parent[V]=U;
                size[U]+=size[V];
            }
            else{
                parent[U]=V;
                size[V]+=size[U];
            }
            n--;
            return true;
        }

        int noOfComponents(){
            return n;
        }
    };

    struct Comp{
        bool operator()(const vint &a,const vint &b) const{
            if(a[2]==b[2]) return a[3]>b[3];
            return a[2]>b[2];
        }
    };
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int m=edges.size();
        if(m<n-1) return -1;

        DSU ds(n);
        for(int i=0;i<m;i++){
            int u=edges[i][0], v=edges[i][1], s=edges[i][2], m=edges[i][3];
            if(m && !ds.unionBySize(u,v)) return -1;
        }

        sort(edges.begin(),edges.end(),Comp());
        multiset<pair<int,int>> hashSet;

        for(int i=0;i<m;i++){
            int u=edges[i][0], v=edges[i][1], s=edges[i][2], m=edges[i][3];
            if(!m && !ds.unionBySize(u,v)) continue;
            hashSet.insert({s,m});
        }

        if(ds.noOfComponents()!=1) return -1;

        for(auto itr=hashSet.begin();itr!=hashSet.end() && k;){
            if(!itr->second){
                int s=itr->first;
                hashSet.insert({2*s,1});
                itr=hashSet.erase(itr);
                k--;
            }
            else itr++;
        }

        return hashSet.begin()->first;
    }
};

int main(){

return 0;
}