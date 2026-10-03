#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(int i,int j,int n){
        return (i<4*n && j<4*n && i>=0 && j>=0);
    }
  public:
    vector<vector<int>> formCoils(int n) {
        // code here
        vector<vector<int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<int>> matrix(4*n,vector<int>(4*n,-1));
        
        int count=1;
        for(int i=0;i<4*n;i++){
            for(int j=0;j<4*n;j++){
                matrix[i][j]=count;
                count++;
            }
        }
        
        queue<tuple<int,int,int,int>> q; // type, direction, i, j
        q.push({0,2,0,0}); 
        q.push({1,0,4*n-1,4*n-1});
        
        vector<vector<int>> res(2);
        while(!q.empty()){
            auto entry=q.front(); q.pop();
            int t=get<0>(entry), d=get<1>(entry), i=get<2>(entry), j=get<3>(entry);
            res[t].push_back(matrix[i][j]);
            matrix[i][j]=0;
            int numberOfTurnsTaken=0;
            while(numberOfTurnsTaken<2){
                int ii=i+dir[d][0], jj=j+dir[d][1];
                if(isValid(ii,jj,n) && matrix[ii][jj]){
                    q.push({t,d,ii,jj});
                    break;
                }
                else{
                    d=(d+1)%4;
                    numberOfTurnsTaken++;
                }
            }
        }
        return res;
    }
};

int main(){

return 0;
}