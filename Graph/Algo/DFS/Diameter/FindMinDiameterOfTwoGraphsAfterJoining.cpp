#include<iostream>
#include<vector>
using namespace std;

using vvi = vector<vector<int>> ;
using vb = vector<bool> ;
using pii = pair<int,int> ;

class Solution {
    int combinedDiameter(int dia1,int dia2){
        return (dia1+1)/2+(dia2+1)/2+1;
    }

    pii DFS(int u,vvi &adjMatrix,vb &visited){
        visited[u]=true;
        pii ans={0,u};
        for(int &v:adjMatrix[u]){
            if(visited[v]) continue;
            pii nextAns=DFS(v,adjMatrix,visited);
            nextAns.first+=1;
            if(nextAns.first>ans.first){
                ans.first=nextAns.first;
                ans.second=nextAns.second;
            }
        }
        return ans;
    }

    void initAdj(vvi &edges,vvi &adjMatrix){
        for(vector<int> &edge: edges){
            int u=edge[0],v=edge[1];
            adjMatrix[u].push_back(v);
            adjMatrix[v].push_back(u);
        }
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size(),m=edges2.size();
        vvi adjMatrix1(n+1),adjMatrix2(m+1);
        vb visited1(n+1,false),visited2(m+1,false);

        initAdj(edges1,adjMatrix1);
        initAdj(edges2,adjMatrix2);

        int end1=DFS(0,adjMatrix1,visited1).second;
        int end2=DFS(0,adjMatrix2,visited2).second;

        visited1.assign(n+1,false);
        visited2.assign(m+1,false);

        int dia1=DFS(end1,adjMatrix1,visited1).first;
        int dia2=DFS(end2,adjMatrix2,visited2).first;
        
        int dia=combinedDiameter(dia1,dia2);
        return max(dia,max(dia1,dia2));
    }
};

int main(){

return 0;
}