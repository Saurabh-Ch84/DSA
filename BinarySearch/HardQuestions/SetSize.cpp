#include<bits/stdc++.h>
using namespace std;

class Solution{
    int m;
    vector<int> difference;
    vector<long long> prefixSum;
public:
    Solution(vector<int> &A) {
        // 1. Cleanly sort and remove duplicates
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        m = A.size();
        // 2. Calculate differences between adjacent unique elements
        for(int i = 0; i < m - 1; i++)
            difference.push_back(A[i+1] - A[i]);
        sort(difference.begin(), difference.end());
        // 3. 1-indexed Prefix Sum (handles empty arrays and 0-index queries safely)
        int N = difference.size();
        prefixSum.resize(N + 1, 0); 
        for(int i = 0; i < N; i++){
            prefixSum[i+1] = prefixSum[i] + difference[i];
        }
    }
    
    long long solve(int x){
        // index = count of differences strictly <= x
        int index = upper_bound(difference.begin(), difference.end(), x) - difference.begin();
        // prefixSum[index]: Sum of differences <= x
        // (m - 1 - index) * x: The remaining differences capped at x
        // + x: The unconstrained last element
        long long setSize = prefixSum[index] + 1LL * (m - 1 - index) * x + x;
        return setSize;
    }
};

int main(){
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    Solution s(A);
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        cout << s.solve(x) << "\n";
    }
    return 0;
}