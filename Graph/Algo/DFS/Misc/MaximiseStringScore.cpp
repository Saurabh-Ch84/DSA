#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

using vc = vector<char>;
using vi = vector<int>;
using pii = pair<int,int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vvi = vector<vi>;
using vvc = vector<vc>;


class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.length();
        
        // 1. Valid Moves Map (Adjacency)
        // Stores valid next character indices (0-25) for each character (0-25)
        vector<vector<int>> nextChars(26);
        for(int i=0; i<26; ++i) nextChars[i].push_back(i); // Always allowed to jump to same char
        for(auto &j : jumps) nextChars[j[0]-'a'].push_back(j[1]-'a'); // Allowed custom jumps
        
        // maxPrev[c] stores the maximum value of the "source term" for a target character 'c'.
        // Derived from the score formula:
        // Score(j -> i) = (Prefix[i-1] - Prefix[j-1]) - (Count[s[i]][i-1] - Count[s[i]][j-1]) * s[i]
        // DP[i] = (Prefix[i-1] - Count[s[i]][i-1]*s[i]) + max_j( DP[j] - Prefix[j-1] + Count[s[i]][j-1]*s[i] )
        // The second part depends only on 'j' and the target character 's[i]'.
        vector<long long> maxPrev(26, -1e18);
        
        // 2. Initialize for Source Index 0
        // DP[0] = 0.
        // For j=0, Prefix[-1] = 0, Count[-1] = 0.
        // Source Term = 0 - 0 + 0 = 0.
        int startChar = s[0] - 'a';
        for(int nextC : nextChars[startChar]) {
            maxPrev[nextC] = max(maxPrev[nextC], 0LL);
        }
        
        // Running Prefix Stats (Corresponds to index i-1 in the loop)
        vector<int> counts(26, 0);
        long long currentPrefixSum = 0;
        
        long long ans = 0;
        
        // 3. Iterative DP from 1 to N-1
        for(int i = 1; i < n; ++i) {
            // Update running stats to include s[i-1], effectively moving from i-1 to i state
            int prevChar = s[i-1] - 'a';
            counts[prevChar]++;
            currentPrefixSum += s[i-1];
            
            int u = s[i] - 'a';
            
            // If this character is reachable (i.e., we have a valid previous jump to 'u')
            if(maxPrev[u] > -1e17) {
                // Calculate DP[i]
                // Term dependent on destination i: Prefix[i-1] - Count[u][i-1] * u
                long long currentTerm = currentPrefixSum - (long long)counts[u] * (u + 'a');
                long long dpVal = currentTerm + maxPrev[u];
                
                ans = max(ans, dpVal);
                
                // Update maxPrev for future jumps FROM this index i
                // We use the same 'counts' and 'currentPrefixSum' because they represent Prefix[i-1],
                // which is exactly what the formula requires for a source index 'i'.
                for(int nextC : nextChars[u]) {
                    // Source Term for next jump: DP[i] - Prefix[i-1] + Count[nextC][i-1] * nextC
                    long long nextSourceVal = dpVal - currentPrefixSum + (long long)counts[nextC] * (nextC + 'a');
                    maxPrev[nextC] = max(maxPrev[nextC], nextSourceVal);
                }
            }
        }
        
        return (int)ans;
    }
};


class Solution {
    int recursion(int u, vi &dp, vvpii &adjList) {
        if (dp[u] != -1) return dp[u];
        int ans = 0;
        for (pii &p : adjList[u]) {
            int v = p.first, w = p.second;
            int nextAns = w + recursion(v, dp, adjList);
            ans = max(ans, nextAns);
        }
        return dp[u] = ans;
    }

public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        // 1. Map allowed jumps
        vvc edgeMap(26);
        for (vc &jump : jumps) {
            char from = jump[0];
            char to = jump[1];
            edgeMap[to - 'a'].push_back(from);
        }
        
        int n = s.length();
        
        // 2. Precompute Prefix Sums and Counts
        vvi prefixCount(26, vi(n, 0));
        vi prefixArr(n, 0);
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';
            prefixCount[idx][i] = 1;
            if (i) prefixArr[i] = prefixArr[i - 1] + (int)ch;
            else prefixArr[i] = (int)ch;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++)
                prefixCount[j][i] += prefixCount[j][i - 1];
        }
        
        // 3. Build Graph
        vvpii adjList(n);
        vvi indexMap(26);
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';
            
            // --- FIX START ---
            // 1. Same Character Jumps
            for (int &j : indexMap[idx]) {
                // REMOVED "- 1" here. We need Inclusive Count to cancel the Inclusive Sum.
                int freq = prefixCount[idx][i] - (j > 0 ? prefixCount[idx][j - 1] : 0);
                int w = prefixArr[i] - (j > 0 ? prefixArr[j - 1] : 0) - freq * (int)ch;
                adjList[j].push_back({i, w});
            }
            // --- FIX END ---
            
            // 2. Different Character Jumps (This was already correct)
            vc &connectedChars = edgeMap[idx];
            for (char nodes : connectedChars) {
                int idx_ = nodes - 'a';
                for (int &j : indexMap[idx_]) {
                    int freq = prefixCount[idx][i] - (j > 0 ? prefixCount[idx][j - 1] : 0);
                    int w = prefixArr[i] - (j > 0 ? prefixArr[j - 1] : 0) - freq * (int)ch;
                    adjList[j].push_back({i, w});
                }
            }
            indexMap[idx].push_back(i);
        }
        
        vi dp(n, -1);
        return recursion(0, dp, adjList);
    }
};

int main(){

return 0;
}