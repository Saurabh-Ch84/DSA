#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    int fun(vector<vector<int>> &h,int sX,int sY,int X,int Y,int n,int m){
        vector<vector<int>> diff(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        diff[sX][sY]=0;
        pq.push({0,{sX,sY}});

        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        while(!pq.empty()){
            int diffU=pq.top().first;
            int xU=pq.top().second.first,yU=pq.top().second.second;
            if(xU==X && yU==Y) return diff[X][Y];
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int xV=xU+dx[i],yV=yU+dy[i];
                if(xV>=n || yV>=m || xV<0 || yV<0) continue;
                int newEffort=max(diffU,abs(h[xV][yV]-h[xU][yU]));
                if(diff[xV][yV]>newEffort)
                {
                    diff[xV][yV]=newEffort;
                    pq.push({newEffort,{xV,yV}});
                }
            }
        }
        return diff[X][Y];
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights){
        int sX=0,sY=0,dX=heights.size()-1,dY=heights[0].size()-1;
        return fun(heights,sX,sY,dX,dY,heights.size(),heights[0].size());
    }
};

int main(){

return 0;
}