#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    bool isValid(int newR,int newC,int n,int m){
        return (newR>=0 && newC>=0  && newR<n && newC<m);
    }
  public:
    int orangesRotting1(vector<vector<int>>& mat) {
        // Code here
        queue<pair<int,int>> q;
        int n=mat.size(),m=mat[0].size();
        int freshOrange=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2) q.push({i,j});
                else if(mat[i][j]==1) freshOrange+=1;
            }
        }
        if(!freshOrange) return 0;

        vector<int> dr={-1,0,1,0},dc={0,1,0,-1};
        int timeToRot=0;
        while(!q.empty())
        {
            int sz=q.size();
            bool rotted=false;
            for(int i=0;i<sz;i++)
            {
                int row=q.front().first,col=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newR=row+dr[k],newC=col+dc[k];
                    if(isValid(newR,newC,n,m) && mat[newR][newC]==1){
                        mat[newR][newC]=2;
                        freshOrange-=1;
                        rotted=true;
                        q.push({newR,newC});
                    }
                }
            }
            if(rotted) timeToRot+=1;
        }
        return (!freshOrange)? timeToRot:-1;
    }

    int orangesRotting2(vector<vector<int>>& mat) {
        // Code here
        queue<pair<int,int>> q;
        int n=mat.size(),m=mat[0].size();
        int freshOrange=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2) q.push({i,j});
                if(mat[i][j]==1) freshOrange+=1;
            }
        }
        if(!freshOrange) return 0;
        int timeToRot=0;
        while(!q.empty())
        {
            int size=q.size();
            bool flag=false;
            for(int i=0;i<size;i++)
            {
                int row=q.front().first,col=q.front().second;
                for(int dr=-1;dr<=1;dr++)
                {
                    for(int dc=-1;dc<=1;dc++)
                    {
                        if(row+dr>n-1 || row+dr<0 || col+dc>m-1 || col+dc<0 || abs(dc)==abs(dr)) 
                            continue;
                        if(mat[row+dr][col+dc]==1)
                        {
                            mat[row+dr][col+dc]=2;
                            flag=true;
                            freshOrange-=1;
                            q.push({row+dr,col+dc});
                        }
                    }
                }
                q.pop();
            }
            if(flag) timeToRot+=1;
        }
        return (!freshOrange)? timeToRot:-1;
    }
};

int main(){

return 0;
}