#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
    void recursion(string &p,vector<string> &a,vector<vector<int>> &m,int i,int j,int n){
        if(i==n-1 && j==n-1){
            a.push_back(p);
            return ;
        }
        if(m[i][j]==0) return ;
        m[i][j]=-1;
        if(i>0 && m[i-1][j]==1) //up
        {
            p.push_back('U');
            recursion(p,a,m,i-1,j,n);
            p.pop_back();
        }
        if(j>0 && m[i][j-1]==1) //left
        {
            p.push_back('L');
            recursion(p,a,m,i,j-1,n);
            p.pop_back();
        }
        if(j<n-1 && m[i][j+1]==1) //right
        {
            p.push_back('R');
            recursion(p,a,m,i,j+1,n);
            p.pop_back();
        }
        if(i<n-1 && m[i+1][j]==1) //down
        {
            p.push_back('D');
            recursion(p,a,m,i+1,j,n);
            p.pop_back();
        }
        m[i][j]=1;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        if(!maze[0][0]) return {};
        // code here
        string path;
        vector<string> ans;
        int n=maze.size();
        recursion(path,ans,maze,0,0,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

class Solution2 {
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
    
    void recursion(vector<string> &result,vector<vector<int>>& maze,string &path,vector<int> &di,
                  vector<int> &dj,string &moves,int i,int j,int n,int m)
    {
        if(maze[i][j]==0) return ;
        if(i==n-1 && j==m-1)                  {
            result.push_back(path);
            return ;
        }
        maze[i][j]=0;
        for(int k=0;k<4;k++){
            int i_=i+di[k],j_=j+dj[k];
            if(!isValid(i_,j_,n,m)) continue;
            path.push_back(moves[k]);
            recursion(result,maze,path,di,dj,moves,i_,j_,n,m);
            path.pop_back();
        }
        maze[i][j]=1;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int sX=0,sY=0,n=maze.size(),m=maze[0].size();
        vector<string> result;
        string path,moves="DLRU";
        vector<int> di={1,0,0,-1},dj={0,-1,1,0};
        recursion(result,maze,path,di,dj,moves,sX,sY,n,m);
        return result;
    }
};

int main(){

return 0;
}