#include<iostream>
#include<vector>
using namespace std;

using vvc = vector<vector<char>> ; 
using vi = vector<int> ;
class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }

    bool DFS(int i,int j,int k,int n,int m,int sz,vi &di,vi &dj,string &word,vvc &board){
        if(k==sz) return true;
        char orig=board[i][j];
        board[i][j]='#';
        bool ans=false;
        for(int idx=0;idx<4;idx++){
            int i_=i+di[idx],j_=j+dj[idx];
            if(!isValid(i_,j_,n,m) || board[i_][j_]!=word[k]) continue;
            bool nextAns=DFS(i_,j_,k+1,n,m,sz,di,dj,word,board);
            if(nextAns){
                ans=nextAns;
                break; 
            }
        }
        board[i][j]=orig;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size(),sz=word.length();
        vi di={-1,0,1,0},dj={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j] && DFS(i,j,1,n,m,sz,di,dj,word,board)) 
                    return true;
            }
        }
        return false;
    }
};

int main(){

return 0;
}