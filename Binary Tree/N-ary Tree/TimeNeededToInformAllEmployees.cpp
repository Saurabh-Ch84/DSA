#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using vi=vector<int>;
using vvi=vector<vi>;

class Solution {
public:
    int numOfMinutes(int n,int headID,vi &manager,vi &informTime) {
        vvi adjList(n);
        for(int u=0;u<n;u++){
            if(manager[u]==-1) continue;
            int v=manager[u];
            adjList[v].push_back(u);
        }

        int time=0;
        queue<pair<int,int>> q;
        q.push({headID,informTime[headID]});

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front(); q.pop();
                int u=p.first, t=p.second;
                for(const int &v: adjList[u]){
                    int t_=t+informTime[v];
                    time=max(time,t_);
                    q.push({v,t_});
                }
            }
        }

        return time;
    }
};

int main(){

return 0;
}