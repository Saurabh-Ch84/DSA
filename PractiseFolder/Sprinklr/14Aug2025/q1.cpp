#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
LeetCode 2378: Choose Edges to Maximize Score in a Tree
Problem Statement:

You are given a weighted tree with n nodes labeled from 0 to n−1, with node 0 as the root. 
The tree is described by an array edges, where each edges[i] = [parent_i, weight_i] indicates that node parent_i is the parent of node i, and the edge between them has weight weight_i. For the root node, edges = [-1, -1].

Your task is to choose a subset of edges from the tree such that no two selected edges share a common node (i.e., no two edges are adjacent), and the sum of the weights of the selected edges is maximized.

Return the maximum sum of the selected edges' weights.
*/


class Solution {
    pair<long long,long long> dfs(vector<vector<pair<int,int>>>& adj, int u, int parent) {
        long long exclude = 0;
        vector<long long> incVals, excVals, weights; // store per-child values

        for (auto it : adj[u]) {
            int v = it.first, w = it.second;
            if (v == parent) continue;
            auto childRes = dfs(adj, v, u);
            long long incChild = childRes.first;
            long long excChild = childRes.second;

            exclude += max(incChild, excChild);

            incVals.push_back(incChild);
            excVals.push_back(excChild);
            weights.push_back(w);
        }

        long long include = LLONG_MIN;
        for (int i = 0; i < (int)incVals.size(); i++) {
            long long score = weights[i] + excVals[i] + (exclude - max(incVals[i], excVals[i]));
            include = max(include, score);
        }

        if (include == LLONG_MIN) include = 0; // leaf node
        return {include, exclude};
    }

public:
    long long maxScore(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < n; i++) {
            if (edges[i][0] == -1) continue;
            int p = edges[i][0], w = edges[i][1];
            adj[p].push_back({i, w});
            adj[i].push_back({p, w});
        }
        auto res = dfs(adj, 0, -1);
        return max(res.first, res.second);
    }
};

int main() {
    Solution sol;

    vector<vector<int>> edges1 = {{-1, -1}, {0, 5}, {0, 10}, {2, 6}, {2, 4}};
    cout << sol.maxScore(edges1) << endl; // 11

    vector<vector<int>> edges2 = {{-1, -1}, {0, -2}, {0, 3}};
    cout << sol.maxScore(edges2) << endl; // 3

    vector<vector<int>> edges3 = {{-1, -1}, {0, 7}, {1, -1}, {1, 5}};
    cout << sol.maxScore(edges3) << endl; // 12

    vector<vector<int>> edges4 = {{-1, -1}, {0, 0}};
    cout << sol.maxScore(edges4) << endl; // 0

    vector<vector<int>> edges5 = {{-1, -1}, {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};
    cout << sol.maxScore(edges5) << endl; // 9

    return 0;
}