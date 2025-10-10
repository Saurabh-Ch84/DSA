#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool isValid(int i,int j,int n){
        return (i<n && j<n && i>=0 && j>=0);
    }
    
    bool DFS(int n,int i,int j,int m,int count,vector<int> &di,vector<int> &dj,vector<vector<int>> &board){
        if(board[i][j]!=-1) return false;
        board[i][j]=count;
        if(count==m) return true;
        for(int k=0;k<8;k++){
            int i_=i+di[k],j_=j+dj[k];
            if(!isValid(i_,j_,n)) continue;
            bool next=DFS(n,i_,j_,m,count+1,di,dj,board);
            if(next) return true;
        }
        board[i][j]=-1;
        return false;
    }
  public:
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>> board(n,vector<int>(n,-1));
        vector<int> di={-2,-1,1,2,2,1,-1,-2};
        vector<int> dj={1,2,2,1,-1,-2,-2,-1};
        int m=n*n-1,count=0;
        bool isPossible=DFS(n,0,0,m,count,di,dj,board);
        return (isPossible) ? board : vector<vector<int>>{{-1}};
    }
};

int main(){

return 0;
}