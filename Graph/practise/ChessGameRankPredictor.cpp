#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{

    void DFS1(unordered_set<int> &defeated, vector<vector<int>> &adjL, int u, int parent = -1)
    {   //this DFS will find out all the players defeated by player u directly or indirectly;
        for (int &v : adjL[u])
        {
            defeated.insert(v);
            DFS1(defeated, adjL, v, u);
        }
    }
    void DFS2(unordered_set<int> &defeatedBy, vector<vector<int>> &adjLRev, int u, int parent = -1)
    {   //this DFS will find out all the players who defeated player u directly or indirectly;
        for (int &v : adjLRev[u])
        {
            defeatedBy.insert(v);
            DFS2(defeatedBy, adjLRev, v, u);
        }
    }

    vector<int> findTopoSort(vector<int> &indegree, vector<vector<int>> &adjL, int n)
    {
        vector<int> topoSort = {0}; //for zero based-indexing
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            topoSort.push_back(node);
            q.pop();
            for (int &neighbor : adjL[node])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        //this topoSort ordering may or may not be unique depending on that a rank is predicted
        return topoSort;
    }

public:
    vector<pair<int, int>> findRank(vector<vector<int>> &edges, int n, int m)
    {
        // n--> number of players, m-->number of games played
        vector<vector<int>> adjList(n + 1);//to find out players that were defeated by player
        vector<vector<int>> adjListRev(n + 1);//to find out players that defeated player
        vector<int> indegree(n + 1, 0);//for toposort
        for (vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            indegree[v]++;
            adjList[u].push_back(v);
            adjListRev[v].push_back(u);
        }
        vector<int> topoSort = findTopoSort(indegree, adjList, n);
        if(topoSort.size()<n+1){
            //no answer possible as input is invalid
            cout << "Cycle detected. Invalid ranking.\n";
            return {};
        }

        vector<pair<int, int>> personRank; //container for all the valid player->rank
        for (int rank = 1; rank <= n; rank++)
        {
            int player = topoSort[rank];
            unordered_set<int> defeatedBy; //to prevent dups
            unordered_set<int> defeated; //to prevent dups
            DFS1(defeated, adjList, player); //for transitive and direct dependency of winning
            DFS2(defeatedBy, adjListRev, player); //for transitive and direct dependency of losing
            int playersDefeatedByHim = defeated.size();
            int playersThatDefeatedHim = defeatedBy.size();
            if (playersDefeatedByHim + playersThatDefeatedHim == n - 1) //this player has indirectly or directly played n-1 matches which confirms it's suspected rank to be true.
            {
                pair<int, int> p = {player, rank};
                personRank.push_back(p);
            }
        }
        return personRank;
    }
};

int main()
{
    vector<vector<int>> edges = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};

    int n1 = 4;
    int m1 = 6;
    vector<vector<int>> edges1 = {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {2, 4},
        {3, 4}};
    // Expected output: (1->1), (2->2), (3->3), (4->4)
    int n2 = 4;
    int m2 = 1;
    vector<vector<int>> edges2 = {
        {2, 3}};
    // Expected output: (empty)
    int n3 = 5;
    int m3 = 4;
    vector<vector<int>> edges3 = {
        {1, 2},
        {1, 3},
        {1, 4},
        {1, 5}};
    // Expected output: (1->1)
    int n4 = 4;
    int m4 = 4;
    vector<vector<int>> edges4 = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4}};
    // Expected output: (1->1), (4->4)

    int n5 = 4;
    int m5 = 2;
    vector<vector<int>> edges5 = {
        {2, 3},
        {3, 4}};
    // Expected output: (empty)

    int n6 = 3;
    int m6 = 3;
    vector<vector<int>> edges6 = {
        {1, 2},
        {2, 3},
        {3, 1}};
    // Expected output: (cycle detected, invalid ranking)

    Solution s;
    vector<pair<int, int>> ans = s.findRank(edges1, n1, m1);
    for (pair<int, int> p : ans)
    {
        int player = p.first;
        int rank = p.second;
        cout << "(" << player << "->" << rank << ")";
    }
    return 0;
}