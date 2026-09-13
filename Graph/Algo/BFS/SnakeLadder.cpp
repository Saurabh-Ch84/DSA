#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
    int BFS(int start,int dest,unordered_map<int,int> &adjMap){
        queue<int> q;
        vector<int> visited(dest+1,0);
        visited[1]=1;
        q.push(start);
        int moves=0;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int u=q.front(); q.pop();
                if(u==dest) return moves;
                for(int die=1;die<=6;die++){
                    int v=u+die;
                    // if out of bounds, break the loop
                    if(v>dest) break;
                    // if there is a ladder or snake, move to the destination
                    if(adjMap.count(v))
                        v=adjMap[v];
                    // if already visited, continue
                    if(!visited[v]){
                        visited[v]=1;
                        q.push(v);
                    }
                }
            }
            // level completed, increment moves
            moves++;
        }
        return -1;
    }
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
        unordered_map<int,int> adjMap;
        int l=lad.size();
        for(int i=0;i<l;i+=2){
            int u=lad[i], v=lad[i+1];
            adjMap[u]=v;
        }
        int s=sn.size();
        for(int i=0;i<s;i+=2){
            int u=sn[i], v=sn[i+1];
            adjMap[u]=v;
        }
        return BFS(1,n*n,adjMap);
    }
};

int main(){

return 0;
}