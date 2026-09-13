#include<iostream>
#include<bits/stdc++.h>
using namespace std;

using vvi = vector<vector<int>> ;
using vi = vector<int> ;
using si = set<int> ;

class Solution {
    void init(vvi &connections,vvi &adjMatrix){
        for(vi &connection: connections){
            // 0-based indexing.
            int u=connection[0]-1,v=connection[1]-1;
            adjMatrix[u].push_back(v);
            adjMatrix[v].push_back(u);
        }
    }

    void DFS(int u,int comp,vi &component,unordered_map<int,si> &hashMap,vvi &adjMatrix){
        component[u]=comp;
        hashMap[comp].insert(u);
        for(int &v: adjMatrix[u]){
            if(component[v]!=-1) continue;
            DFS(v,comp,component,hashMap,adjMatrix);
        }
    }
    
public:
    vector<int> processQueries(int c, vvi &connections, vvi &queries) {
        vvi adjMatrix(c);
        init(connections,adjMatrix);

        vi component(c,-1);
        unordered_map<int,si> hashMap;
        int comp=0;

        for(int i=0;i<c;i++){
            if(component[i]==-1){
                DFS(i,comp,component,hashMap,adjMatrix);
                comp++;
            }
        }

        vi result;
        for(vi &query: queries){
            int type=query[0],u=query[1]-1;
            int compo=component[u];
            si &hashSet=hashMap[compo];
            if(type==1){
                if(hashSet.empty()) result.push_back(-1);
                else if(hashSet.count(u)) result.push_back(u+1);
                else result.push_back(*hashSet.begin()+1);
            }
            else hashSet.erase(u);
        }

        return result;
    }
};

int main(){

return 0;
}