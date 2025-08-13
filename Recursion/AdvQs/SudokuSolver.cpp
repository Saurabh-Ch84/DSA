#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool check(vector<vector<char>> &b,int row,int col){
        for(int i=0;i<9;i++)
        {
            if(i!=row && b[i][col]==b[row][col]) return false;
            if(i!=col && b[row][i]==b[row][col]) return false;
        }
        int boxRow=(row/3)*3,boxCol=(col/3)*3;
        for(int i=boxRow;i<boxRow+3;i++)
        {
            for(int j=boxCol;j<boxCol+3;j++)
            {
                if(i==row && j==col) continue;
                if(b[i][j]==b[row][col]) return false;
            }
        }
        return true;
    }
    bool recursion(vector<vector<char>>& board){
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char num='1';num<='9';num++)
                    {
                        board[i][j]=num;
                        if(check(board,i,j) && recursion(board)) return true;
                        board[i][j]='.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        recursion(board);
    }
};

int main(){

return 0;
}