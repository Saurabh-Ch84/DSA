#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// User function Template for C++
using vi=vector<int>;
using memo_t1=unordered_map<int,int>;
using memo_t2=unordered_set<int>;

class Solution {
    int BFS(memo_t1 &edgeMap){
        vi score={1,2,3,4,5,6};
        queue<int> q;
        memo_t2 visited;
        q.push(1);
        
        int moves=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int u=q.front(); q.pop();
                if(u==30) return moves;
                for(int i=0;i<6;i++){
                    int v=u+score[i];
                    if(v<=30){
                        if(edgeMap.count(v)) v=edgeMap[v];
                        if(visited.count(v)) continue;
                        visited.insert(v);
                        q.push(v);
                    }
                }
                visited.insert(u);
            }
            moves++;
        }
        return -1;
    }
  public:
    int minThrow(int N, int arr[]) {
        // code here
        memo_t1 edgeMap;
        for(int i=0;i<2*N;i+=2){
            int u=arr[i], v=arr[i+1];
            edgeMap[u]=v;
        }
        return BFS(edgeMap);
    }
};

int main(){

return 0;
}