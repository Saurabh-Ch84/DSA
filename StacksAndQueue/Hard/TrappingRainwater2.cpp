#include<iostream>
#include<queue>
#include<vector>
using namespace std;

using pipii=pair<int,pair<int,int>>;
class Solution {

    bool isValid(int i,int j,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size(),m=heightMap[0].size();
        priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            pq.push({heightMap[i][0],{i,0}});
            visited[i][0]=true;
            pq.push({heightMap[i][m-1],{i,m-1}});
            visited[i][m-1]=true;
        }

        for(int j=0;j<m;j++){
            pq.push({heightMap[0][j],{0,j}});
            visited[0][j]=true;
            pq.push({heightMap[n-1][j],{n-1,j}});
            visited[n-1][j]=true;
        }

        int count=0;
        vector<int> di={-1,0,1,0},dj={0,1,0,-1};

        while(!pq.empty()){
            auto pp=pq.top();
            pq.pop();
            int height=pp.first;
            int i=pp.second.first,j=pp.second.second;
            for(int k=0;k<4;k++)
            {
                int i_=i+di[k],j_=j+dj[k];
                if(!isValid(i_,j_,n,m) || visited[i_][j_]) continue; 
                count+=max(height-heightMap[i_][j_],0);
                pq.push({max(height,heightMap[i_][j_]),{i_,j_}});
                visited[i_][j_]=true;
            }
        }

        return count;
    }
};

int main(){

return 0;
}