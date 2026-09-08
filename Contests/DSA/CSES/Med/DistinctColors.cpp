#include<bits/stdc++.h>
using namespace std;

int dp[2 * (int)1e5 + 1];
void DFS(int p, int u, vector<vector<int>> &adjList, vector<int> &colors, vector<set<int>> &subTreeColorSet) {
    subTreeColorSet[u].insert(colors[u]);
    for (int &v : adjList[u]) {
        if (v == p) continue;
        DFS(u, v, adjList, colors, subTreeColorSet);
        if (subTreeColorSet[u].size() < subTreeColorSet[v].size()) {
            subTreeColorSet[u].swap(subTreeColorSet[v]); // O(1) pointer swap
        }
        // C++17 merge moves nodes in O(small.size() * log N) without copying
        subTreeColorSet[u].merge(subTreeColorSet[v]);
    }
    dp[u] = subTreeColorSet[u].size();
}
void solve(int n,vector<vector<int>> &edges,vector<int> &colors){
    vector<vector<int>> adjList(n);
    for(auto &edge: edges){
        int u=edge[0]-1, v=edge[1]-1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<set<int>> subTreeColorSet(n);
    DFS(-1, 0, adjList, colors,subTreeColorSet);
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> colors(n);
    for(int i=0;i<n;i++)
        cin>>colors[i];
    vector<vector<int>> edges(n-1,vector<int>(2));
    for(int i=0;i<n-1;i++){
        for(int j=0;j<2;j++)
            cin>>edges[i][j];
    }
    solve(n,edges,colors);
return 0;
}