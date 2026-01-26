#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int> hashMap;
        for(int i=0;i<n;i++)
            hashMap[arr[i]]++;
        
        vector<int> result(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && hashMap[st.top()]<=hashMap[arr[i]])
                st.pop();
            if(st.empty()) result[i]=-1;
            else result[i]=st.top();
            st.push(arr[i]);
        }
        
        return result;
    }
};


class Solution {
    bool isMagicSquare(vvi &grid,int i,int j,int side,vvi &prefixSumRow,vvi &prefixSumCol){
        // Target sum: first row of the square
        int target = prefixSumRow[i][j+side-1] - (j ? prefixSumRow[i][j-1] : 0);

        // Check all rows
        for(int row=i; row<i+side; row++){
            int sum = prefixSumRow[row][j+side-1] - (j ? prefixSumRow[row][j-1] : 0);
            if(sum != target) return false;
        }

        // Check all columns
        for(int col=j; col<j+side; col++){
            int sum = prefixSumCol[i+side-1][col] - (i ? prefixSumCol[i-1][col] : 0);
            if(sum != target) return false;
        }

        // Check main diagonal
        int diag1 = 0;
        for(int k=0; k<side; k++) diag1 += grid[i+k][j+k];
        if(diag1 != target) return false;

        // Check anti-diagonal
        int diag2 = 0;
        for(int k=0; k<side; k++) diag2 += grid[i+k][j+side-1-k];
        if(diag2 != target) return false;

        return true;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vvi prefixSumRow(n, vi(m,0)), prefixSumCol(n, vi(m,0));

        // Build prefix sums
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                prefixSumRow[i][j] = grid[i][j] + (j ? prefixSumRow[i][j-1] : 0);
                prefixSumCol[i][j] = grid[i][j] + (i ? prefixSumCol[i-1][j] : 0);
            }
        }

        // Try largest possible square first
        for(int side=min(n,m); side>1; side--){
            for(int i=0; i<n-side+1; i++){
                for(int j=0; j<m-side+1; j++){
                    if(isMagicSquare(grid,i,j,side,prefixSumRow,prefixSumCol))
                        return side;
                }
            }
        }
        return 1;
    }
};


int main(){

return 0;
}