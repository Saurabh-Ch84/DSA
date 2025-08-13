#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void recursion(vector<int> &c, int n, int i, int t, vector<int> &v, vector<vector<int>> &ans) {
        if (t == 0) {
            ans.push_back(v);
            return;
        }
        for (int j = i; j < n; j++) {
            if (j > i && c[j] == c[j-1]) continue; // Skip duplicates
            if (c[j] > t) break; // No need to proceed further
            v.push_back(c[j]);
            recursion(c, n, j+1, t-c[j], v, ans);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        recursion(candidates, candidates.size(), 0, target, temp, answer);
        return answer;
    }
};


int main(){

return 0;
}