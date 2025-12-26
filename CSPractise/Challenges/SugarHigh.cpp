#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

// Structure to keep track of original indices
struct Candy {
    int sugar;
    int id;
};

// Comparator for sorting
// 1. Sort by Sugar (Ascending) -> Eat max candies with min sugar
// 2. If Sugar is equal, sort by ID (Ascending) -> Prefer lower indices
bool compareCandies(const Candy& a, const Candy& b) {
    if (a.sugar != b.sugar) {
        return a.sugar < b.sugar;
    }
    return a.id < b.id;
}

vi sugarHigh(vi candies, int threshold) { // Pass by value to preserve original array
    int n = candies.size();
    vector<Candy> sortedCandies(n);
    
    // 1. Store value and original index
    for(int i = 0; i < n; i++) {
        sortedCandies[i] = {candies[i], i};
    }
    
    // 2. Sort based on criteria
    sort(sortedCandies.begin(), sortedCandies.end(), compareCandies);
    
    vi resultIndices;
    
    // 3. Greedily pick candies
    for(int i = 0; i < n; i++) {
        if(threshold >= sortedCandies[i].sugar) {
            threshold -= sortedCandies[i].sugar;
            resultIndices.push_back(sortedCandies[i].id);
        } else {
            // Optimization: Since the array is sorted, 
            // if we can't afford the current smallest, we can't afford any subsequent ones.
            break; 
        }
    }
    
    // 4. IMPORTANT: The problem implicitly expects the output indices to be sorted
    sort(resultIndices.begin(), resultIndices.end());
    
    return resultIndices;
}

void print(vector<int> v) {
    cout << "[ ";
    for(int &val : v) {
        cout << val << " ";
    }
    cout << "]" << endl;
}

int main() {
    vi c1 = {33, 20, 12, 19, 29};
    print(sugarHigh(c1, 33)); // Expected: [2, 3]

    vi c2 = {62, 67, 100};
    print(sugarHigh(c2, 8)); // Expected: []

    vi c3 = {16, 39, 67, 16, 38, 71};
    print(sugarHigh(c3, 17)); // Expected: [0]
    
    // Counter-example for unsorted output check
    vi c4 = {5, 1}; 
    print(sugarHigh(c4, 10)); // Should be [0, 1], not [1, 0]

    return 0;
}