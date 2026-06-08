#include <bits/stdc++.h>

using namespace std;

// Use long long for values to prevent overflow as V_i can be up to 10^9 
// and the sum can exceed 2*10^9.
using ll = long long;

class Solution {
public:
    // Write your logic inside this function
    // n: total gems
    // k: number of gems to choose
    // m: minimum distinct colors required
    // C: vector of colors
    // V: vector of values
    // Returns the maximum possible total value
    ll solve(int n, int k, int m, const vector<int>& C, const vector<int>& V) {
        // TODO: Implement your logic here.
        // Strategy Hint:
        // 1. Group gems by color. For each color, sort the gems by value (descending).
        // 2. To satisfy the "at least M distinct colors" constraint, you likely need to pick
        //    the top gem from at least M different colors.
        // 3. A common approach is:
        //    - Pick the best (highest value) gem from exactly M distinct colors.
        //    - Then, pick the remaining (K - M) gems from the pool of ALL remaining gems 
        //      (including the 2nd/3rd best from the chosen colors and the best from unchosen colors)
        //      that have the highest values.
        // 4. Since you can choose ANY M colors, you might need to iterate or use a greedy strategy
        //    to find the optimal set.
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)
            arr.push_back({V[i],C[i]});
        
        sort(arr.rbegin(),arr.rend());

        ll maxi=0;
        unordered_set<int> hashSet;
        priority_queue<int> pq;

        for(vector<int> &entry: arr){
            int v=entry[0], c=entry[1];
            if(!hashSet.count(c) && hashSet.size()!=m){
                hashSet.insert(c);
                maxi+=v;
            }
            else pq.push(v);
        }

        int count=hashSet.size();
        while(count!=k && !pq.empty()){
            maxi+=pq.top();
            pq.pop();
            count++;
        }
        return maxi;
    }
};

void run_test_case(int n, int k, int m, const vector<int>& C, const vector<int>& V, ll expected) {
    Solution sol;
    ll result = sol.solve(n, k, m, C, V);
    
    if (result == expected) {
        cout << "Test Passed: Output " << result << endl;
    } else {
        cout << "Test Failed: Output " << result << ", Expected " << expected << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Sample Input 1
    // N=5, K=3, M=2
    // Gems: (1,30), (1,40), (1,50), (2,10), (3,20)
    // Expected: 110
    {
        int n = 5, k = 3, m = 2;
        vector<int> C = {1, 1, 1, 2, 3};
        vector<int> V = {30, 40, 50, 10, 20};
        run_test_case(n, k, m, C, V, 110);
    }

    // Sample Input 2
    // N=5, K=3, M=3
    // Gems: (1,30), (1,40), (1,50), (2,10), (3,20)
    // Expected: 80
    {
        int n = 5, k = 3, m = 3;
        vector<int> C = {1, 1, 1, 2, 3};
        vector<int> V = {30, 40, 50, 10, 20};
        run_test_case(n, k, m, C, V, 80);
    }

    // Sample Input 3
    // N=5, K=5, M=1
    // Gems: (4, 1e9), (5, 1e9), (4, 1e9), (5, 1e9), (4, 1e9)
    // Expected: 5000000000 (Beware of 32-bit int overflow)
    {
        int n = 5, k = 5, m = 1;
        vector<int> C = {4, 5, 4, 5, 4};
        vector<int> V = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
        run_test_case(n, k, m, C, V, 5000000000);
    }

    // Uncomment the lines below to read from standard input manually
    /*
    int n, k, m;
    if (cin >> n >> k >> m) {
        vector<int> C(n);
        vector<int> V(n);
        for (int i = 0; i < n; ++i) {
            cin >> C[i] >> V[i];
        }

        Solution sol;
        cout << sol.solve(n, k, m, C, V) << endl;
    }
    */

    return 0;
}