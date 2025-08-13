#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void recursion(int n,vector<string>&c,vector<bool>&r,vector<bool>&d,vector<bool>&s,vector<vector<string>> &a,int col=0){
        if(col==n){
            //valid answer found
            a.push_back(c);
            return ;
        }
        for(int row=0;row<n;row++)
        {
            if(!r[row] && !s[col+row] && !d[n+row-col-1]){
                //mark
                s[col+row]=true,d[n+row-col-1]=true,r[row]=true;
                //place 
                c[row][col]='Q';
                recursion(n,c,r,d,s,a,col+1);
                //backtracking
                //replace
                c[row][col]='.';
                //unmark
                r[row]=false,d[n+row-col-1]=false,s[col+row]=false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> chessBoard(n);
        string s(n,'.');
        //board construction
        for(int i=0;i<n;i++)
            chessBoard[i]=s;
        vector<bool> row(n,false),dexter(2*n-1,false),sinister(2*n-1,false);
        //takes care of visited rows,main diagonal and antidiagonal
        recursion(n,chessBoard,row,dexter,sinister,ans);
        return ans;
    }
};

int main(){

return 0;
}