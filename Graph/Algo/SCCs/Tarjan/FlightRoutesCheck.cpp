#include<bits/stdc++.h>
using namespace std;

class Solution{
    int timer;
    vector<vector<int>> SCCs;
    void DFS(int u,vector<vector<int>> &adj,vector<int> &discovery,vector<int> &lowest,vector<int> &instack,stack<int> &orderStack){
        discovery[u]=lowest[u]=timer++;
        instack[u]=1;
        orderStack.push(u);
        for(int &v: adj[u]){
            if(discovery[v]==-1){
                DFS(v,adj,discovery,lowest,instack,orderStack);
                lowest[u]=min(lowest[u],lowest[v]);
            }
            else if(!instack[v]) continue;
            else lowest[u]=min(lowest[u],discovery[v]);
        }
        if(lowest[u]==discovery[u]){
            vector<int> SCC;
            int prev=-1;
            while(prev!=u && !orderStack.empty()){
                prev=orderStack.top();
                SCC.push_back(prev);
                instack[prev]=0;
                orderStack.pop();
            }
            SCCs.push_back(SCC);
        }
    }
        public:
    void solve(int n,int m,vector<pair<int,int>> &edges){
        timer=0;
        SCCs.clear();
        vector<vector<int>> adj(n);
        for(auto &edge: edges){
            int u=edge.first-1, v=edge.second-1;
            adj[u].push_back(v);
        }
        vector<int> discovery(n,-1), lowest(n,-1), instack(n,0);
        stack<int> orderStack;
        for(int u=0;u<n;u++){
            if(discovery[u]==-1){
                DFS(u,adj,discovery,lowest,instack,orderStack);
                if(SCCs.size()>1){
                    cout<<"NO"<<endl;
                    int u=SCCs[0][0]+1, v=SCCs[1][0]+1;
                    cout<<u<<" "<<v<<endl;
                    return ;
                }
            }
        }
        cout<<"YES";
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;i++)
        cin>>edges[i].first>>edges[i].second;
    Solution s;
    s.solve(n,m,edges);
return 0;
}