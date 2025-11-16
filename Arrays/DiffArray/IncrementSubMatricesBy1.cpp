#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        for(vector<int> &query: queries){
            int a=query[0],b=query[1];
            int c=query[2],d=query[3];
            for(int i=a;i<=c;i++){
                for(int j=b;j<=d;j++){
                    matrix[i][j]++;
                }
            }
        }
        return matrix;
    }
};

class Solution2{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n,vector<int>(n,0));

        for(vector<int> &query: queries){
            int r1=query[0],c1=query[1];
            int r2=query[2],c2=query[3];
            for(int i=r1;i<=r2;i++){
                diff[i][c1]+=1;
                if(c2+1<n) diff[i][c2+1]-=1;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++)
                diff[i][j]+=diff[i][j-1];
        }
        return diff;
    }
};

int main(){

return 0;
}