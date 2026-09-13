#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;


class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(), u=0;
        unordered_map<int,int> edges;
        bool dir=true;

        for(int i=n-1;i>=0;i--){
            if(dir){
                for(int j=0;j<n;j++){
                    u++;
                    if(board[i][j]!=-1)
                        edges[u]=board[i][j];
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    u++;
                    if(board[i][j]!=-1) 
                        edges[u]=board[i][j];
                }
            }
            dir=!dir;
        }

        queue<int> q;
        unordered_set<int> visited;
        q.push(1);
        visited.insert(1);
        int moves=0;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int u=q.front(); q.pop();
                if(u==n*n) return moves;
                for(int d=1;d<=6;d++){
                    int v=(edges.count(u+d)? edges[u+d]: u+d);
                    if(v>n*n || visited.count(v)) continue;
                    q.push(v);
                    visited.insert(v);
                }
            }
            moves++;
        }

        return -1;
    }
};

int main(){

return 0;
}