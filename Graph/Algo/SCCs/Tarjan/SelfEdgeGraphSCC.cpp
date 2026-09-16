#include<bits/stdc++.h>
using namespace std;

class Solution{
    using vint=vector<int>;
    int timer;
    vector<vint> SCCs;
    void DFS(int u,vector<vint> &adj,vint &discovery,vint &lowest,vector<bool> &inStack,stack<int> &orderSt){
        lowest[u]=discovery[u]=timer++;
        inStack[u]=1;
        orderSt.push(u);
        for(int &v: adj[u]){
            if(discovery[v]==-1){
                // direct-edge or forward-edge
                DFS(v,adj,discovery,lowest,inStack,orderSt);
                lowest[u]=min(lowest[u],lowest[v]);
            }
            else if(!inStack[v]){
                // cross-edge
                continue;
            }
            else{
                // back-edge
                lowest[u]=min(lowest[u],discovery[v]);
            }
        }
        if(lowest[u]==discovery[u]){
            vector<int> SCC;
            int prev=-1;
            while(prev!=u && !orderSt.empty()){
                prev=orderSt.top();
                inStack[prev]=0;
                SCC.push_back(prev);
                orderSt.pop();
            }
            SCCs.push_back(SCC);
        }
    }
    void printSCC(){
        cout<<SCCs.size()<<endl;
        for(auto &SCC: SCCs){
            cout<<SCC.size()<<" ";
            for(int &u: SCC){
                cout<<u<<" ";
            }
            cout<<endl;
        }
    }
        public:
    void getSCCs(int n,vector<vector<int>> &edges){
        vector<vector<int>> adj(n);
        for(auto &edge: edges){
            int u=edge[0], v=edge[1];
            adj[u].push_back(v);
        }
        vint discovery(n,-1), lowest(n,-1);
        vector<bool> inStack(n,0);
        stack<int> orderSt;
        timer=0;
        SCCs.clear();
        for(int u=0;u<n;u++){
            if(discovery[u]==-1){
                DFS(u,adj,discovery,lowest,inStack,orderSt);
            }
        }
        // topographical order
        reverse(SCCs.begin(),SCCs.end());
        printSCC();
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m,vector<int>(2));
    for(int i=0;i<m;i++)
        cin>>edges[i][0]>>edges[i][1];
    Solution s;
    s.getSCCs(n,edges);
return 0;
}