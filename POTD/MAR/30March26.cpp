#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
    using vint=vector<int>;
public:
    bool checkStrings(string s1, string s2) {
        vint even(26,0), odd(26,0);
        int n=s1.length();

        for(int i=0;i<n;i++){
            if(i&1){
                odd[s1[i]-'a']++;
                odd[s2[i]-'a']--;
            }
            else{
                even[s1[i]-'a']++;
                even[s2[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++){
            if(odd[i] || even[i])
                return false;
        }
        return true;
    }
};

class Solution2 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    class DSU{
        vint size, parent;
            public:
        DSU(int n){
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
            int U=find(u), V=find(v);
            if(U==V) return false;
            if(size[U]>=size[V]){
                size[U]+=size[V];
                parent[V]=U;
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
            }
            return true;
        }
    };
    
    int manhattanDistance(int x1,int y1,int x2,int y2){
        return abs(x2-x1)+abs(y2-y1);
    }
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n=houses.size(), minCostSum=0;
        vvint edges;
        for(int i=0;i<n;i++){
            vint &u=houses[i];
            for(int j=0;j<i;j++){
                vint &v=houses[j];
                int w=manhattanDistance(u[0],u[1],v[0],v[1]);
                edges.push_back({w,i,j});
            }
        }
        
        DSU ds(n);
        sort(edges.begin(),edges.end());
        for(vint &edge: edges){
            int w=edge[0], u=edge[1], v=edge[2];
            if(ds.unionBySize(u,v)) minCostSum+=w;
        }
        
        return minCostSum;
    }
};

int main(){

return 0;
}