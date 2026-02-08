#include<iostream>
#include<vector>
#include<queue>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <numeric> // for std::gcd

using namespace std;

using pii=pair<int,int>;
class SolutionBrute {
    bool DFS(int i,int j,int x,int y,int target,set<pii> &visited){
        if(i==target || j==target || i+j==target) return true;
        if(visited.count({i,j})) return false;
        visited.insert({i,j});
        if(i<x) {
            bool fillI=DFS(x,j,x,y,target,visited);
            if(fillI) return true;
        }
        if(j<y) {
            bool fillJ=DFS(i,y,x,y,target,visited);
            if(fillJ) return true;
        }
        if(i>0) {
            bool emptyI=DFS(0,j,x,y,target,visited);
            if(emptyI) return true;
        }
        if(j>0) {
            bool emptyJ=DFS(i,0,x,y,target,visited);
            if(emptyJ) return true;
        }
        if(i>0 && j<y){
            int c=y-j;
            int mini=min(c,i); 
            bool pourFromIToJ=DFS(i-mini,j+mini,x,y,target,visited);
            if(pourFromIToJ) return true;
        }
        if(j>0 && i<x){
            int c=x-i;
            int mini=min(c,j);
            bool pourFromJToI=DFS(i+mini,j-mini,x,y,target,visited);
            if(pourFromJToI) return true;
        }
        return false;
    }
public:
    bool canMeasureWater(int x, int y, int target) {
        set<pii> visited;
        return DFS(0,0,x,y,target,visited);
    }
};



using namespace std;

using pii = pair<int, int>;

class Solution {
    // Structure to store trace info: {previous_state, description_of_move}
    struct StateInfo {
        pii parent;
        string action;
    };

    void printPath(pii curr, map<pii, StateInfo>& parentMap) {
        vector<string> path;
        
        // Backtrack from target to start using parent pointers
        while (curr != make_pair(0, 0)) {
            path.push_back(parentMap[curr].action + " -> State (" + to_string(curr.first) + ", " + to_string(curr.second) + ")");
            curr = parentMap[curr].parent;
        }
        path.push_back("Start (0, 0)");
        
        // The path is currently backwards, so reverse it
        reverse(path.begin(), path.end());

        cout << "--- Shortest Path Found (" << path.size() - 1 << " steps) ---" << endl;
        for (const string& step : path) {
            cout << step << endl;
        }
    }

public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        
        queue<pii> q;
        q.push({0, 0});
        
        // Map stores: Current State -> {Parent State, Action String}
        // This also acts as our 'visited' set.
        map<pii, StateInfo> parentMap;
        parentMap[{0, 0}] = {{-1, -1}, "Start"}; // Root node

        while (!q.empty()) {
            pii curr = q.front();
            q.pop();
            
            int i = curr.first;
            int j = curr.second;

            // Check if we reached the target
            if (i == target || j == target || i + j == target) {
                printPath(curr, parentMap);
                return true;
            }

            // Define all 6 possible moves
            // {new_x, new_y, action_description}
            vector<pair<pii, string>> moves = {
                {{x, j}, "Fill Jug 1"},
                {{i, y}, "Fill Jug 2"},
                {{0, j}, "Empty Jug 1"},
                {{i, 0}, "Empty Jug 2"},
                {{i - min(i, y - j), j + min(i, y - j)}, "Pour Jug 1 -> 2"},
                {{i + min(j, x - i), j - min(j, x - i)}, "Pour Jug 2 -> 1"}
            };

            for (auto& move : moves) {
                pii nextState = move.first;
                string action = move.second;

                // If state not visited yet
                if (parentMap.find(nextState) == parentMap.end()) {
                    parentMap[nextState] = {curr, action}; // Point back to current
                    q.push(nextState);
                }
            }
        }
        
        cout << "No solution possible." << endl;
        return false;
    }
};


class SolutionOptimal {
public:
    bool canMeasureWater(int x, int y, int target) {
        // Case 1: Target is too big
        if (target > x + y) return false;
        
        // Case 2: Target is 0 (always possible)
        if (target == 0) return true;
        
        // Case 3: Bézout's Identity
        // Can we express target as A*x + B*y?
        // Yes, if target % gcd(x, y) == 0
        return target % __gcd(x, y) == 0;
    }
};

int main() {
    Solution sol;
    int jug1 = 3, jug2 = 5, target = 4;
    cout << "Solving for Jugs: " << jug1 << "L, " << jug2 << "L | Target: " << target << "L" << endl;
    sol.canMeasureWater(jug1, jug2, target);
    return 0;
}