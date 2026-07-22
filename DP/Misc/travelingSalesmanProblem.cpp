#include <bits/stdc++.h>
using namespace std;

// Slowest but inefficient takes hell lot of time to provide optimal solution for larger inputs
//  T.C- O(n!)

int travllingSalesmanProblem(vector<vector<int>> &graph, int s, int V)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;
    do
    {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        min_path = min(min_path, current_pathweight);

    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main()
{
    int V, s;

    cout << "Enter the number of cities: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (" << V << "x" << V << "):" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the starting city (0 to " << V - 1 << "): ";
    cin >> s;

    cout << "The minimum cost of the tour is: " << travllingSalesmanProblem(graph, s, V) << endl;

    return 0;
}
