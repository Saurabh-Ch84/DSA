#include<iostream>
#include<vector>
using namespace std;

class Solution {
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

int main(){

return 0;
}