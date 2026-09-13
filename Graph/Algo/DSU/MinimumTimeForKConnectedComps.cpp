#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    class DSU{
        vint parent, size;
        int n;
            public:
        DSU(int n):n(n){
            size.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        int find(int u){
            if(u==parent[u]) return u;
            return parent[u]=find(parent[u]);
        }
        void unionBySize(int u,int v){
            if(u==-1 || v==-1) return ;
            int U=find(u), V=find(v);
            if(U==V) return ;
            n--;
            if(size[U]>size[V]){
                size[U]+=size[V];
                parent[V]=U;
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
            }
        }
        int getNoOfComps(){
            return n;
        }
    };
    struct Comp{
        bool operator()(const vint &a,const vint &b) const{
            return a[2]>b[2];
        }
    };
public:
    int minTime(int n,vvint &edges,int k) {
        sort(edges.begin(),edges.end(),Comp());
        int m=edges.size(), ans=edges[0][2];
        if(!m) return 0;
        if(n==k) return ans;
        
        DSU ds(n);
        int i=0;
        while(i<m){
            int u=edges[i][0], v=edges[i][1];
            ds.unionBySize(u,v);
            if(ds.getNoOfComps()>=k) ans=(i+1<m ? edges[i+1][2]: 0);
            else break;
            i++;
        }
        return ans;
    }
};

// 3613. Minimize Maximum Component Cost

class Solution2 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    class DSU{
        vint parent, size;
        int n;
            public:
        DSU(int n):n(n){
            size.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        int find(int u){
            if(u==parent[u]) return u;
            return parent[u]=find(parent[u]);
        }
        void unionBySize(int u,int v){
            int U=find(u), V=find(v);
            if(U==V) return ;
            n--;
            if(size[U]>size[V]){
                size[U]+=size[V];
                parent[V]=U;
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
            }
        }
        int getNoOfComps(){
            return n;
        }
    };
    struct Comp{
        bool operator()(const vint &a,const vint &b) const{
            return a[2]<b[2];
        }
    };
public:
    int minCost(int n,vvint &edges,int k) {
        sort(edges.begin(),edges.end(),Comp());
        DSU ds(n);
        int i=0, m=edges.size(), mini=0;
        while(ds.getNoOfComps()>k){
            int u=edges[i][0], v=edges[i][1], w=edges[i][2];
            ds.unionBySize(u,v);
            mini=max(mini,w);
            i++;
        }
        return mini;
    }
};

int main(){

return 0;
}