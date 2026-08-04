#include<bits/stdc++.h>
using namespace std;

class XORBasis {
    vector<int> basis;
    int basis_size;
    int n;

public:
    // Constructor builds the basis from the initial array
    XORBasis(vector<int>& arr) {
        basis.assign(32, 0);
        basis_size = 0;
        n = arr.size();
        
        for (int x : arr) {
            insert(x);
        }
    }

    // Standard Gaussian Elimination for GF(2)
    void insert(int num) {
        for (int bit = 31; bit >= 0; bit--) {
            if ((num & (1 << bit)) == 0) continue;
            
            if (!basis[bit]) {
                basis[bit] = num;
                basis_size++;
                break;
            } else {
                num ^= basis[bit];
            }
        }
    }

    // 1. EXISTENCE: Does any subset XOR to K?
    bool canFormK(int k) {
        int num = k;
        // Try to reduce K using our existing basis
        for (int bit = 31; bit >= 0; bit--) {
            if ((num & (1 << bit)) == 0) continue;
            
            if (!basis[bit]) {
                // If we hit an empty slot, K has a bit that our basis cannot form.
                // Therefore, K is linearly independent and CANNOT be formed.
                return false; 
            } else {
                num ^= basis[bit];
            }
        }
        // If K reduces exactly to 0, it means it was linearly dependent on the basis.
        // Therefore, the original array CAN form K!
        return num == 0;
    }

    // 2. COUNTING: How many subsets XOR to K?
    long long countSubsetsWithXORK(int k) {
        // Step A: If it's mathematically impossible to form K, return 0.
        if (!canFormK(k)) {
            return 0; 
        }
        
        // Step B: If it is possible, the number of combinations is exactly 2^(free_variables)
        // Free variables = Total elements (N) - Linearly independent elements (basis_size)
        // Note: Using 1LL to prevent integer overflow if N > 31.
        long long free_variables = n - basis_size;
        return (1LL << free_variables); 
    }
};

int main() {
    vector<int> arr = {2, 2, 2}; // Example array
    XORBasis xb(arr);
    
    // Test Existence
    cout << "Can form 2? " << (xb.canFormK(2) ? "Yes" : "No") << endl;
    cout << "Can form 3? " << (xb.canFormK(3) ? "Yes" : "No") << endl;
    
    // Test Counting
    // Out of [2, 2, 2], the subsets forming 2 are: {2}, {2}, {2}, {2,2,2} (4 total)
    cout << "Subsets forming 2: " << xb.countSubsetsWithXORK(2) << endl; 
    
    return 0;
}