#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    // Write your logic inside this function
    // Return true if all woodcutters are telling the truth, false otherwise
    bool solve(int n,vector<int>& A,vector<int>& B) {
        // TODO: Implement your logic here.
        // Hint: Woodcutter i claims axe A[i].
        // The goddess knows axe j belongs to woodcutter B[j] (based on 1-based indexing in problem).
        // You need to verify if the claim matches the goddess's knowledge for every woodcutter.
        for(int woodCutter=0;woodCutter<n;woodCutter++){
            int axeClaimed=A[woodCutter];
            if(B[axeClaimed-1]-1!=woodCutter) 
                return false;
        }
        return true; // Not Lying
    }
};

void run_test_case(int n, vector<int>& A, vector<int>& B, bool expected) {
    Solution sol;
    bool result = sol.solve(n, A, B);
    string outcome = result ? "Yes" : "No";
    string expected_outcome = expected ? "Yes" : "No";
    
    if (result == expected) {
        cout << "Test Passed: Output " << outcome << endl;
    } else {
        cout << "Test Failed: Output " << outcome << ", Expected " << expected_outcome << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Sample Input 1
    // N = 3
    // A = {3, 1, 2}
    // B = {2, 3, 1}
    // Expected: Yes
    {
        int n = 3;
        vector<int> A = {3, 1, 2};
        vector<int> B = {2, 3, 1};
        run_test_case(n, A, B, true);
    }

    // Sample Input 2
    // N = 4
    // A = {1, 2, 3, 4}
    // B = {1, 3, 2, 4}
    // Expected: No
    {
        int n = 4;
        vector<int> A = {1, 2, 3, 4};
        vector<int> B = {1, 3, 2, 4};
        run_test_case(n, A, B, false);
    }

    // Sample Input 3
    // N = 5
    // A = {2, 4, 5, 1, 3}
    // B = {4, 1, 5, 2, 3}
    // Expected: Yes
    {
        int n = 5;
        vector<int> A = {2, 4, 5, 1, 3};
        vector<int> B = {4, 1, 5, 2, 3};
        run_test_case(n, A, B, true);
    }

    // Uncomment the lines below to read from standard input manually
    /*
    int n;
    if (cin >> n) {
        vector<int> A(n);
        vector<int> B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];
        
        Solution sol;
        if (sol.solve(n, A, B)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    */

    return 0;
}