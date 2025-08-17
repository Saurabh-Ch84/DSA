#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(int i,int j,int n){
        return i<n && j<n && i>=0 && j>=0;
    }
    
    bool isDestination(int i,int j,int n){
        return i==n-1 && j==n-1;
    }
    
    void recursion(vector<vector<int>>& maze,vector<string> &ans,vector<int> &di,
                   vector<int> &dj,vector<char> &moves,string &temp,int n,int i,int j)
    {
        maze[i][j]=0;
        if(isDestination(i,j,n)){
            ans.push_back(temp);
            return ;
        }                                    
        for(int k=0;k<4;k++){
            int newI=i+di[k],newJ=j+dj[k];
            if(isValid(newI,newJ,n) && maze[newI][newJ]==1){
                maze[newI][newJ]=0;
                temp+=moves[k];
                recursion(maze,ans,di,dj,moves,temp,n,newI,newJ);
                maze[newI][newJ]=1;
                temp.pop_back();
            }
        }
        maze[i][j]=1;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n=maze.size();
        vector<string> ans;
        string temp="";
        vector<int> di={-1,0,1,0},dj={0,1,0,-1};
        vector<char> moves={'U','R','D','L'};
        recursion(maze,ans,di,dj,moves,temp,n,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){

return 0;
}