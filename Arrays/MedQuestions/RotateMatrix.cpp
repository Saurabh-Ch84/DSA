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
    void print(vector<vector<int>> &matrix){
        for(vector<int> &row: matrix){
            for(int &val: row){
                cout<<val<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
public:
    void rotate(vector<vector<int>> matrix) {
        int n=matrix.size();
        print(matrix);
        transposeMatrix(matrix,n);
        print(matrix);
        reverseMatrix(matrix,n);
        print(matrix);
    }
};

int main(){
    Solution s;
    s.rotate({{1,2,3},{4,5,6},{7,8,9}});
return 0;
}