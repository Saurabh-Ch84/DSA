#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

//Slower but inefficient takes hell lot of time to provide optimal solution for larger inputs
//T.C:- O(2^n * n^2)

int tsp(vector<vector<int>>& graph, vector<vector<int>>& dp, int mask, int pos) {
    int n = graph.size();
    if (mask == (1 << n) - 1)
        return graph[pos][0] > 0 ? graph[pos][0] : INF;
    
    if (dp[pos][mask] != -1)
        return dp[pos][mask];
    
    int ans = INF;
    for (int city = 0; city < n; ++city) {
        if ((mask & (1 << city)) == 0 && graph[pos][city] > 0) {
            int new_ans = graph[pos][city] + tsp(graph, dp, mask | (1 << city), city);
            ans = min(ans, new_ans);
        }
    }
    
    return dp[pos][mask] = ans;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix (enter 0 if there is no direct path):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int>((1 << n), -1));
    cout << "Minimum cost: " << tsp(graph, dp, 1, 0) << endl;

    return 0;
}
