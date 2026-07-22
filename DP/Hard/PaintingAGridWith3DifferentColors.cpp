#include<iostream>
#include<vector>
using namespace std;

using vi=vector<int>;
using vs=vector<string>;
using vvi=vector<vi>;

class Solution {
    const int MOD=1e9+7;

    void recursionGenerateStates(int m,string &colors,string &state,vs &states){
        if(state.size()==m){
            states.push_back(state);
            return ;
        }
        for(char color: colors){
            if(state.empty() || state.back()!=color){
                state.push_back(color);
                recursionGenerateStates(m,colors,state,states);
                state.pop_back();
            }
        }
    }

    void buildGraph(int k,int m,vs &states,vvi &adjList){
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                if(isCompatible(m,states[i],states[j])){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
    }

    bool isCompatible(int m,string &u,string &v){
        for(int i=0;i<m;i++){
            if(u[i]==v[i]) return false;
        }
        return true;
    }

    int recursion(int i,int n,int m,int u,vvi &adjList,vvi &dp){
        if(i==n) return 1;
        if(dp[i][u]!=-1) return dp[i][u];
        long long ans=0;
        for(int &v: adjList[u]){
            ans=(ans+recursion(i+1,n,m,v,adjList,dp))%MOD;
        }
        return dp[i][u]=(int)ans;
    }
public:
    int colorTheGrid(int m, int n) {
        vs states;
        string state, colors="rgb";
        recursionGenerateStates(m,colors,state,states);

        int k=states.size();
        vvi adjList(k);
        buildGraph(k,m,states,adjList);

        long long ans=0;
        vvi dp(n,vi(k,-1));
        for(int u=0;u<k;u++){
            ans=(ans+recursion(1,n,m,u,adjList,dp))%MOD;
        }
        return (int)ans;
    }
};

int main(){

return 0;
}