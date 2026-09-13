#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Position this line where user code will be pasted.
class Solution {
    void print(vector<vector<int>> &array){
        for(vector<int> &a:array){
            for(int &ele:a){
                cout<<ele<<" ";
            }
            cout<<" ";
        }
        cout<<endl;
    }

    void DFS1(vector<vector<int>> &adj,int node,
            vector<bool> &visited,stack<int>& finishTime){
        
        visited[node]=true;
        for(int &neighbor:adj[node]){
            if(!visited[neighbor]) 
                DFS1(adj,neighbor,visited,finishTime);
        }
        finishTime.push(node);
    }
    
    void DFS2(vector<vector<int>> &adj,int node,
            vector<bool> &visited,vector<int> &SCC){
        
        visited[node]=true;
        for(int &neighbor:adj[node]){
            if(!visited[neighbor]) 
                DFS2(adj,neighbor,visited,SCC);
        }
        SCC.push_back(node);
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        stack<int> finishTime;
        vector<bool> visited(n,false);
        for(int u=0;u<n;u++){
            if(!visited[u]) DFS1(adj,u,visited,finishTime);
        }
        
        vector<vector<int>> adj_Trans(n);
        for(int v=0;v<n;v++){
            visited[v]=false;
            for(int &neighbor:adj[v])
                adj_Trans[neighbor].push_back(v);
        }
        
        vector<vector<int>> SCCs;
        while(!finishTime.empty()){
            int u=finishTime.top();
            finishTime.pop();
            if(!visited[u])
            {
                vector<int> SCC;
                DFS2(adj_Trans,u,visited,SCC);
                SCCs.push_back(SCC);
            }
        }
        int numberOfSCCs=SCCs.size();
        print(SCCs);
        return numberOfSCCs;
    }
};

int main(){

return 0;
}