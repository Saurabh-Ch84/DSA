#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, vector<int>> diagonals;

        // 1. Group numbers by their diagonal sum (i + j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diagonals[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> res;
        // 2. Iterate through all possible sums
        // Max sum is (n-1) + (m-1)
        for (int k = 0; k <= n + m - 2; k++) {
            if (k % 2 == 0) {
                // Even Sum: We need to go Up-Right. 
                // The map stored them Down-Left (because i increased in the loop).
                // So we REVERSE.
                reverse(diagonals[k].begin(), diagonals[k].end());
            }
            // Append to result
            res.insert(res.end(), diagonals[k].begin(), diagonals[k].end());
        }

        return res;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        int r = 0, c = 0;
        bool up = true; // Direction flag
        
        while (result.size() < m * n) {
            result.push_back(mat[r][c]);
            if (up) {
                // Try moving Up-Right
                if (c == n - 1) { r++; up = false; } // Hit Right Wall -> Go Down
                else if (r == 0) { c++; up = false; } // Hit Top Wall -> Go Right
                else { r--; c++; } // Standard Move
            } else {
                // Try moving Down-Left
                if (r == m - 1) { c++; up = true; } // Hit Bottom Wall -> Go Right
                else if (c == 0) { r++; up = true; } // Hit Left Wall -> Go Down
                else { r++; c--; } // Standard Move
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> newMat(n+m-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx=i+j;
                newMat[idx].push_back(mat[i][j]);
            }
        }
        vector<int> res;
        for(int i=0;i<n+m-1;i++){
            if(i%2==0) res.insert(res.end(),newMat[i].rbegin(),newMat[i].rend());
            else res.insert(res.end(),newMat[i].begin(),newMat[i].end());
        }
        return res;
    }
};

void print(vector<vector<int>> &nums){
    for(vector<int> &row:nums){
        for(int &num:row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print(vector<int> nums){
    for(int &num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(){
    Solution s;
    vector<vector<int>> nums={{1,7,8},{3,45,7},{23,5,0}};
    print(nums);
    print(s.findDiagonalOrder(nums));
return 0;
}