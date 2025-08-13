#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool check(vector<vector<int>> &adj,int vertex,int c,vector<int> &color){
        for(int &neighbour:adj[vertex])
            if(color[neighbour]==c) return false;
        return true;
    }
    bool recursion(int v,vector<vector<int>> &adj,vector<int> &color,int m){
        if(v==color.size()) return true;
        for(int c=1;c<=m;c++)
        {
            if(check(adj,v,c,color))
            {
                color[v]=c;
                if(recursion(v+1,adj,color,m)) return true;
                color[v]=0;
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        vector<int> color(v,0);
        for(vector<int> &vec:edges)
        {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        return recursion(0,adj,color,m);
    }
};

int main(){

return 0;
}