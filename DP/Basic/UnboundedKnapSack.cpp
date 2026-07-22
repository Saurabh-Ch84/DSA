#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int> &cost, int w) {
        int n = cost.size();
        
        // dp[j] will store the minimum cost to exactly buy 'j' kg of oranges
        // We use 1e9 to represent "infinity" (impossible to reach this weight yet)
        vector<int> dp(w + 1, 1e9);
        
        // Base case: 0 kg of oranges costs exactly 0
        dp[0] = 0; 
        
        for (int i = 0; i < n; i++) {
            // Skip packets that are unavailable
            if (cost[i] == -1) continue; 
            
            int weight = i + 1;
            
            // Unbounded Knapsack: Iterate FORWARDS from 'weight' up to 'w'
            for (int j = weight; j <= w; j++) {
                // To avoid integer overflow, we only add if the previous state is reachable
                if (dp[j - weight] != 1e9) {
                    dp[j] = min(dp[j], cost[i] + dp[j - weight]);
                }
            }
        }
        
        // If dp[w] is still our "infinity" marker, it means it's impossible
        return dp[w] >= 1e9 ? -1 : dp[w];
    }
};

int main(){

return 0;
}