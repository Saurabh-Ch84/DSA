#include<iostream>
#include<vector>
using namespace std;

//Most Optimal
class Solution1 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int colZero=1,n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0) matrix[0][j]=0;
                    else colZero=0;
                }
            }
        }
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j]=0;

        if(matrix[0][0]==0) for(int j=0;j<m;j++) matrix[0][j]=0;
        if(colZero==0) for(int i=0;i<n;i++) matrix[i][0]=0;
    }
};

// better
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<bool> col(m),row(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    col[j]=true;
                    row[i]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(col[j] || row[i])
                    matrix[i][j]=0;
            }
        }
    }
};

int main(){

return 0;
}