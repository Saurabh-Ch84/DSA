#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
### Problem Statement

**Two arrays are called similar if one can be obtained from another by swapping at most one
pair of elements in one of the arrays.**

Given two arrays `a` and `b`, check whether they are similar.

#### Example

- For `a = [1, 2, 3]` and `b = [1, 2, 3]`, the output should be
  `areSimilar(a, b) = true`
  The arrays are equal, no need to swap any elements.

- For `a = [1, 2, 3]` and `b = [2, 1, 3]`, the output should be
  `areSimilar(a, b) = true`
  We can obtain `b` from `a` by swapping 2 and 1 in `b`.

- For `a = [1, 2, 2]` and `b = [2, 1, 1]`, the output should be
  `areSimilar(a, b) = false`

*/

class Solution
{
public:
    bool areSimilar(vector<int> a, vector<int> b)
    {
        int n = a.size(), m = b.size();
        if (n != m)
            return false;
        unordered_map<int, vector<int>> indexMap;
        for (int i = n - 1; i >= 0; i--)
            indexMap[a[i]].push_back(i);

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            int A = a[i], B = b[i];
            if (A != B)
            {
                if (flag)
                    return false;
                flag = true;
                int idx = (indexMap[B].empty()) ? -1 : indexMap[B].back();
                if (idx == -1)
                    return false;
                indexMap[B].pop_back();
                swap(b[idx], b[i]);
            }
        }
        return true;
    }
};

bool areSimilar(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) return false;
    vector<int> diffA, diffB;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diffA.push_back(a[i]);
            diffB.push_back(b[i]);
        }
    }
    if (diffA.empty()) return true; // identical
    if (diffA.size() == 2 && diffA[0] == diffB[1] && diffA[1] == diffB[0]) return true;
    return false;
}


int main()
{
    Solution s;
    cout << s.areSimilar({1, 2, 2}, {2, 1, 1}) << endl;
    cout << s.areSimilar({1, 2, 3}, {1, 2, 3}) << endl;
    cout << s.areSimilar({1, 2, 3}, {2, 1, 3}) << endl;
    cout << s.areSimilar({1, 2, 3}, {1, 2, 3}) << endl;       // true: identical arrays
    cout << s.areSimilar({1, 2, 3}, {2, 1, 3}) << endl;       // true: one swap (1 and 2)
    cout << s.areSimilar({1, 2, 2}, {2, 1, 1}) << endl;       // false: more than one mismatch
    cout << s.areSimilar({1, 2, 3}, {3, 2, 1}) << endl;       // false: needs two swaps
    cout << s.areSimilar({1, 2, 3, 4}, {1, 4, 3, 2}) << endl; // false: two mismatches, but not swappable
    cout << s.areSimilar({1, 2, 3, 4}, {1, 3, 2, 4}) << endl; // true: one swap (2 and 3)
    cout << s.areSimilar({1, 1, 4}, {1, 4, 1}) << endl;       // true: one swap (1 and 4)
    cout << s.areSimilar({1, 2, 3}, {1, 3, 2}) << endl;       // true: one swap (2 and 3)
    cout << s.areSimilar({1, 2, 3}, {3, 1, 2}) << endl;       // false: three mismatches
    cout << s.areSimilar({5, 6, 7}, {5, 7, 6}) << endl;       // true: one swap (6 and 7)
    return 0;
}