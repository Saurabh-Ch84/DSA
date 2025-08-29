#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int numberOfPointsCoveredByExactlyOneInterval(vector<pair<int, int>> &intervals) {
    int mini = INT_MAX, maxi = INT_MIN;
    for (auto &p : intervals) {
        mini = min(mini, p.first);
        maxi = max(maxi, p.second);
    }

    int size = maxi - mini + 2; // +2 to handle end+1
    vector<int> diff(size, 0);

    // Build difference array
    for (auto &p : intervals) {
        int l = p.first - mini;
        int r = p.second - mini;
        diff[l] += 1;
        diff[r + 1] -= 1;
    }

    // Prefix sum and count points with coverage == 1
    int count = 0, curr = 0;
    for (int i = 0; i < size - 1; ++i) {
        curr += diff[i];
        if (curr == 1) count++;
    }

    return count;
}

int main() {
    vector<pair<int, int>> intervals1 = {{1, 3}, {5, 7}, {9, 10}}; // Expected: 8
    vector<pair<int, int>> intervals2 = {{1, 5}, {3, 7}};          // Expected: 4
    vector<pair<int, int>> intervals3 = {{1, 10}, {2, 5}, {3, 4}}; // Expected: 6

    cout << numberOfPointsCoveredByExactlyOneInterval(intervals1) << endl;
    cout << numberOfPointsCoveredByExactlyOneInterval(intervals2) << endl;
    cout << numberOfPointsCoveredByExactlyOneInterval(intervals3) << endl;

    return 0;
}
