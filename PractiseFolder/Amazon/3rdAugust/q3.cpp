#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<string> &board){
    for(string &row:board){
        for(char &ch:row) cout<<ch<<" ";
        cout<<endl;
    }
    cout<<endl;
}

class Solution{
    bool isValidMove(int i,int j,int n,int m){
        return (i>-1 && i<n && j>-1 && j<m);
    }

    void DFS(vector<string> &board,int n,int m,int i,int j){
        board[i][j]='#';
        vector<int> di={-1,0,1,0};
        vector<int> dj={0,1,0,-1};
        for(int k=0;k<4;k++){
            int newI=i+di[k],newJ=j+dj[k];
            if(isValidMove(newI,newJ,n,m) && board[newI][newJ]=='O') DFS(board,n,m,newI,newJ);
        }
    }
        public:
    void fun(vector<string> &board,int n,int m){
        for(int i=0;i<n;i++){
            if(i==0 || i==n-1){
                for(int j=0;j<m;j++){
                    if(board[i][j]=='O') DFS(board,n,m,i,j);
                }
            }
            else{
                for(int j=0;j<m;j+=m-1){
                    if(board[i][j]=='O') DFS(board,n,m,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
};

int main(){
    int n,m;
    Solution s;
    cout<<"Enter Dimensions of the matrix (n and m): ";
    cin>>n>>m;

    vector<string> board(n);
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i<<"th row of the matrix ";
        getline(cin,board[i]);
    }
    cout<<"Before Flood Fill:-"<<endl;
    printMatrix(board);
    s.fun(board,n,m);
    cout<<"After Flood Fill:-"<<endl;
    printMatrix(board);
return 0;
}