#include<iostream>
#include<vector>
using namespace std;

class NumMatrix {
    vector<vector<int>> area;
    void preprocessing(vector<vector<int>> &matrix,int n,int m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int top=area[i-1][j];
                int left=area[i][j-1];
                int topLeft=area[i-1][j-1];
                area[i][j]=top+left-topLeft+matrix[i-1][j-1];
            }
        }
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        area.resize(n+1,vector<int>(m+1,0));
        preprocessing(matrix,n,m);
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int areaBetween=area[row2+1][col2+1]-area[row2+1][col1]
            -area[row1][col2+1]+area[row1][col1];
        return areaBetween;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(){

return 0;
}