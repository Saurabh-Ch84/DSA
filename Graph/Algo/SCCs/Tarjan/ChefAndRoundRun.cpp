#include<bits/stdc++.h>
using namespace std;

class Solution{
    int magicBoxes, timer;
    using vint=vector<int>;
    void DFS(int u,int n,vint &discovery,vint &lowest,vector<bool> &instack,stack<int> &orderStack,vint &boxes){
        discovery[u]=lowest[u]=timer++;
        instack[u]=1;
        orderStack.push(u);
        int v=(u+1+boxes[u])%n;
        if(discovery[v]==-1){
            DFS(v,n,discovery,lowest,instack,orderStack,boxes);
            lowest[u]=min(lowest[u],lowest[v]);
        }
        else{
            lowest[u]=min(lowest[u],discovery[v]);
        }
        if(lowest[u]==discovery[u]){
            int prev=-1, SCCsize=0;
            while(prev!=u && !orderStack.empty()){
                prev=orderStack.top();
                instack[prev]=0;
                orderStack.pop();
                SCCsize++;
            }
            if(SCCsize>1 || v==u) magicBoxes+=SCCsize;
        }
    }
        public:
    int solve(int n,vector<int> &boxes){
        vector<int> discovery(n,-1), lowest(n,-1);
        vector<bool> instack(n,0);
        stack<int> orderStack;
        magicBoxes=0, timer=0;
        for(int u=0;u<n;u++){
            if(discovery[u]==-1){
                DFS(u,n,discovery,lowest,instack,orderStack,boxes);
            }
        }
        return magicBoxes;
    }
};

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> boxes(n);
        for(int j=0;j<n;j++)
            cin>>boxes[j];
        Solution s;
        cout<<s.solve(n,boxes)<<endl;
    }
return 0;
}