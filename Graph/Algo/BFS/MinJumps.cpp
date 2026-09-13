#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>
using namespace std;

using vi = vector<int>;
// 1. Move the Sieve array to the global scope
const int MAX_LIMIT = 1000005; // 1e6 + 5
vector<bool> isPrime(MAX_LIMIT, true);

// 2. The Static Block: Evaluates ONCE before any test case runs
int auto_init = []() {
    isPrime[0] = false;
    isPrime[1] = false;
    for (long i = 2; i * i < MAX_LIMIT; i++) {
        if (!isPrime[i]) continue;
        for (long j = i * i; j < MAX_LIMIT; j += i) {
            isPrime[j] = false;
        }
    }
    
    // Fast I/O to speed up cin/cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}();


class Solution {
    int BFS(unordered_map<int, vi> &primeMap, int n) {
        int moves = 0;
        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        visited.insert(0);
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int u = q.front(); 
                q.pop();
                
                if (u == n - 1) return moves;
                
                if (u > 0 && !visited.count(u - 1)) {
                    q.push(u - 1);
                    visited.insert(u - 1);
                }
                if (u < n - 1 && !visited.count(u + 1)) {
                    q.push(u + 1);
                    visited.insert(u + 1);  
                }
                
                // Minor Fix: Use count() to prevent unordered_map from 
                // accidentally creating empty vectors for non-primes
                if (primeMap.count(u)) {
                    for (int &v : primeMap[u]) {
                        if (visited.count(v)) continue;
                        visited.insert(v);  
                        q.push(v);
                    }
                    // Optimization: Once we take these prime jumps, clear them 
                    // so we don't iterate through them again if overlapping occurs
                    primeMap[u].clear(); 
                }
            }
            moves++;
        }
        return moves;
    }

public:
    int minJumps(vector<int>& nums) {
        unordered_map<int, vi> primeMap;
        int n = nums.size();
        
        // 3. Just use the global `isPrime` array instantly!
        for (int i = 0; i < n; i++) {
            if (isPrime[nums[i]]) {
                primeMap[i] = {};
            }
        }

        for (auto &prime : primeMap) {
            int p = prime.first;
            vi &indices = prime.second;
            for (int i = 0; i < n; i++) {
                if (i != p && nums[i] % nums[p] == 0) {
                    indices.push_back(i);
                }
            }
        }
        
        return BFS(primeMap, n);
    }
};

int main(){

return 0;
}