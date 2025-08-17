#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
    Given a tree and a number k, find the number of nodes with
    left subtree all nodes sum greater than equal to k.
*/

class Solution
{
    int DFS(unordered_map<int, vector<pair<int, int>>> &tree, int root, int k, int &count)
    {
        int leftSum = 0, rightSum = 0;
        for (auto &nodes : tree[root])
        {
            int child = nodes.first;
            bool isRight = nodes.second;
            if (isRight)
                rightSum = DFS(tree, child, k, count);
            else
                leftSum = DFS(tree, child, k, count);
        }
        if (leftSum >= k)
            count++;
        return root + leftSum + rightSum;
    }

public:
    int countNodesWithLeftSubTreeSumGreaterThanEqualK(unordered_map<int, vector<pair<int, int>>> &tree, int root, int k)
    {
        int count = 0;
        DFS(tree, root, k, count);
        return count;
    }
};

int main()
{
    Solution s;
    unordered_map<int, vector<pair<int, int>>> tree;


    int root1 = 7;
    int k1 = 5;
    vector<vector<int>> edges1 = {{7, 3, 0}, {7, 12, 1}, {3, 2, 0}, {3, 4, 1}};

    for (vector<int> &edge : edges1)
    {
        int parent = edge[0], child = edge[1], isRight = edge[2];
        tree[parent].push_back({child, isRight});
    }
    cout << s.countNodesWithLeftSubTreeSumGreaterThanEqualK(tree, root1, k1) << endl;

    tree.clear();


    int root2 = 7;
    int k2 = 10;
    vector<vector<int>> edges2 = {
        {7, 5, 0},  // 7 -> 5 (left)
        {7, 15, 1}, // 7 -> 15 (right)
        {5, 3, 0}   // 5 -> 3 (left)
    };
    // Expected count: 1 (node 7 left subtree sum = 5+3+7=15 ≥10)
    for (vector<int> &edge : edges2)
    {
        int parent = edge[0], child = edge[1], isRight = edge[2];
        tree[parent].push_back({child, isRight});
    }

    cout << s.countNodesWithLeftSubTreeSumGreaterThanEqualK(tree, root2, k2) << endl;

    tree.clear();

    int root3 = 5;
    int k3 = 7;
    vector<vector<int>> edges3 = {
        {5, 2, 0}, // 5 -> 2 (left)
        {5, 8, 1}, // 5 -> 8 (right)
        {8, 6, 0}, // 8 -> 6 (left)
        {8, 10, 1} // 8 -> 10 (right)
    };

    // Expected count: 0 (no node has left subtree sum ≥7)
    for (vector<int> &edge : edges3)
    {
        int parent = edge[0], child = edge[1], isRight = edge[2];
        tree[parent].push_back({child, isRight});
    }

    cout << s.countNodesWithLeftSubTreeSumGreaterThanEqualK(tree, root3, k3) << endl;
    tree.clear();
    return 0;
}