#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;

class Solution {
    bool isBoundary(int i,int j,int n){
        return (i<0 || j<0 || i>=n || j>=n);
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        vvi matrix(n,vi(n,0));
        vi di={0,1,0,-1},dj={1,0,-1,0};
        int i=0,j=0,dir=0;
        for(int k=1;k<=n*n;k++){
            matrix[i][j]=k;
            int i_=i+di[dir];
            int j_=j+dj[dir];
            if(isBoundary(i_,j_,n) || matrix[i_][j_]!=0){
                dir=(dir+1)%4;
                i_=i+di[dir];
                j_=j+dj[dir];
            }
            i=i_;
            j=j_;
        }
        return matrix;
    }
};

int main(){

return 0;
}