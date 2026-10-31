#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<unordered_map>
using namespace std;

using vi = vector<int> ;
using vc = vector<char> ;
using vvi = vector<vi> ;
using vvc = vector<vc> ;

class Solution {
public:
    long long minCost(string &s, string &t, vvc &transform, vi &cost) {
        int n = s.length();
        
        // 1. Initialize Distance Matrix
        vvi dist(26, vi(26, INT_MAX));
        
        // Distance to self is always 0
        for(int i=0; i<26; i++) 
            dist[i][i] = 0;
        
        // 2. Build initial edges
        for(int i=0; i<transform.size(); i++){
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            // Handle multiple edges between same chars: take min
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        
        // 3. Floyd-Warshall Algorithm (All-Pairs Shortest Path)
        // Computes min cost to get from any char 'i' to any char 'j'
        for (int via = 0; via < 26; via++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
        
        long long totalCost = 0;
        
        // 4. Iterate through the string
        for(int i=0; i<n; i++){
            if(s[i] == t[i]) continue;
            int u = s[i] - 'a';
            int v = t[i] - 'a';
            int minOp = INT_MAX;
            // CHECK ALL 26 POSSIBLE TARGETS
            // We try transforming both u -> char_k AND v -> char_k
            for(int k=0; k<26; k++){
                if(dist[u][k] != INT_MAX && dist[v][k] != INT_MAX){
                    minOp = min(minOp, dist[u][k] + dist[v][k]);
                }
            }
            // If no character 'k' exists that both can turn into:
            if(minOp == INT_MAX) return -1;
            totalCost += minOp;
        }
        
        return totalCost;
    }
};

int main(){

return 0;
}