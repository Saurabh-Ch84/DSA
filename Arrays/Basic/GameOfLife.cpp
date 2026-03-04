#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void preprocess(vector<vector<int>> &neighbor,vector<vector<int>> &board,int n,int m){
        vector<int> di={-1,-1,-1,0,1,1,1,0}, dj={-1,0,1,1,1,0,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                for(int k=0;k<8;k++){
                    int i_=i+di[k], j_=j+dj[k];
                    if(i_<0 || i_>=n || j_<0 || j_>=m) continue;
                    if(board[i_][j_]) count++;
                }
                neighbor[i][j]=count;
            }
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(), m=board[0].size();
        vector<vector<int>> neighbor(n,vector<int>(m,0));
        preprocess(neighbor,board,n,m);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]){
                    if(neighbor[i][j]<2) board[i][j]=0;
                    else if(neighbor[i][j]>3) board[i][j]=0;
                }
                else{
                    if(neighbor[i][j]==3) board[i][j]=1;
                }
            }
        }
    }
};

int main(){

return 0;
}