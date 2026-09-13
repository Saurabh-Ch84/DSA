#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using vvi = vector<vector<int>> ;
using vi = vector<int> ;

class Solution {
    int topoSort(int n,string &colors,vvi &adjMatrix,vi &indegree){
        queue<int> q;
        vvi colorMatrix(n,vi(26,0));

        for(int i=0;i<n;i++){
            if(!indegree[i]){
                char color=colors[i];
                colorMatrix[i][color-'a']=1;
                q.push(i);
            }
        }

        int count=0,maxi=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            char color=colors[u];
            count++;
            maxi=max(maxi,colorMatrix[u][color-'a']);
            for(int &v: adjMatrix[u]){
                int c_=colors[v]-'a';
                for(int c=0;c<26;c++)
                    colorMatrix[v][c]=max(colorMatrix[v][c],colorMatrix[u][c]+(c_==c? 1: 0));
                indegree[v]--;
                if(!indegree[v]) q.push(v);
            }
        }

        return (count==n)? maxi: -1;
    }

        public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vvi adjMatrix(n);
        vi indegree(n,0);

        for(vi &edge: edges){
            int u=edge[0],v=edge[1];
            adjMatrix[u].push_back(v);
            indegree[v]++;
        }

        return topoSort(n,colors,adjMatrix,indegree);
    }
};

int main(){

return 0;
}