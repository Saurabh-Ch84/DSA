#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    vvint getLCP(int n,string &word){
        vvint lcp(n,vint(n,0));
        // fill last-column and last-row
        for(int i=0;i<n;i++){
            lcp[i][n-1]=(word[i]==word[n-1]);
            lcp[n-1][i]=lcp[i][n-1];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(word[i]==word[j])
                    lcp[i][j]=1+lcp[i+1][j+1];
                lcp[j][i]=lcp[i][j];
            }
        }
        return lcp;
    }
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string str(n,'#');
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(lcp[j][i]){
                    str[i]=str[j];
                    break;
                }
            }
            if(str[i]=='#'){
                vint canUse(26,1);
                for(int j=0;j<i;j++){
                    if(!lcp[j][i]) canUse[str[j]-'a']=0;
                }
                bool flag=false;
                for(int k=0;k<26;k++){
                    if(canUse[k]){
                        str[i]=k+'a';
                        flag=true;
                        break;
                    }
                }
                if(!flag) return "";
            }
        }
        return (getLCP(n,str)==lcp? str: "");
    }
};

class Solution1 {
    void DFS(int node,vector<int> &tin,vector<int> &low,int &timer,
             vector<vector<int>> &adj,unordered_set<int> &cutVertices,int parent=-1){
                 tin[node]=low[node]=timer++;
                 int child=0;
                 for(int &neighbor:adj[node]){
                     if(neighbor==parent) continue;
                     if(tin[neighbor]==-1)
                     {
                         DFS(neighbor,tin,low,timer,adj,cutVertices,node);
                         low[node]=min(low[node],low[neighbor]);
                         child++;
                         if(parent!=-1 && low[neighbor]>=tin[node])
                             cutVertices.insert(node);
                     }
                         else low[node]=min(low[node],tin[neighbor]);
                 }
                 if(parent==-1 && child>1) cutVertices.insert(node);
             }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(vector<int> edge:edges){
            int u=edge[0],v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int> tin(V,-1),low(V,-1);
        int timer=0;
        unordered_set<int> cutVertexSet;
        for(int v=0;v<V;v++)
            if(tin[v]==-1) DFS(v,tin,low,timer,adjList,cutVertexSet);
        
        if(!cutVertexSet.size()) return {-1};
        vector<int> cutVertices;
        cutVertices.insert(cutVertices.begin(),cutVertexSet.begin(),cutVertexSet.end());
        return cutVertices;
    }
};

class Solution2 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using memo_t=unordered_set<int>;
    
    void DFS(int u,int parent,int &timer,vvint &adjList,vint &visitTime,vint &lowest,memo_t &hashSet){
        visitTime[u]=lowest[u]=timer++;
        int children=0;
        for(int &v: adjList[u]){
            if(v==parent) continue;
            if(visitTime[v]==-1){
                DFS(v,u,timer,adjList,visitTime,lowest,hashSet);
                lowest[u]=min(lowest[u],lowest[v]);
                children++;
                if(parent!=-1 && lowest[v]>=visitTime[u])
                    hashSet.insert(u);
            }
            else lowest[u]=min(lowest[u],visitTime[v]);
        }
        if(parent==-1 && children>1)
            hashSet.insert(u);
    }
    
  public:
    vint articulationPoints(int V,vvint &edges) {
        // Code here
        vvint adjList(V);
        for(vint &edge: edges){
            int u=edge[0], v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        int timer=0;
        memo_t hashSet;
        vint visitTime(V,-1), lowest(V,-1);
        for(int i=0;i<V;i++){
            if(visitTime[i]==-1){
                DFS(i,-1,timer,adjList,visitTime,lowest,hashSet);
            }
        }
        if(hashSet.empty()) return {-1};
    
        vint result;
        result.insert(result.begin(),hashSet.begin(),hashSet.end());
        return result;
    }
};

int main(){

return 0;
}