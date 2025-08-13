#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    void transposeMatrix(vector<vector<int>>& matrix,int n){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
        }
    }
    void reverseMatrix(vector<vector<int>>& matrix,int n){
        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        transposeMatrix(matrix,n);
        reverseMatrix(matrix,n);
    }
};

int main(){

return 0;
}