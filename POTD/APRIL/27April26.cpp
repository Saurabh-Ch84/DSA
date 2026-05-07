#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    using vint=vector<int>;
  public:
    int smallestSubstring(string s) {
        // code here
        int left=0, right=0, n=s.size(), mini=n+1;
        vint count(3,0);
        while(right<n){
            count[s[right]-'0']++;
            while(count[0] && count[1] && count[2]){
                mini=min(mini,right-left+1);
                if(mini==3) return 3;
                count[s[left]-'0']--;
                left++;
            }
            right++;
        }
        return (mini==n+1? -1:mini);
    }
};

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using memo_t=unordered_map<int,vvint>;

    bool isValid(int i,int j,int m,int n){
        return (i<m && j<n && i>=0 && j>=0);
    }

    bool DFS(int i,int j,int o,int m,int n,memo_t &memo,vvint &grid,vvint &vis){
        if(vis[i][j]) return false;
        vis[i][j]=1;
        if(memo[grid[i][j]][o].empty()) return false;
        // 2. The Fix: If it safely entered the target pipe, we win instantly!
        if(i == m-1 && j == n-1) return true;

        int i_=i+memo[grid[i][j]][o][0];
        int j_=j+memo[grid[i][j]][o][1];
        int o_=memo[grid[i][j]][o][2];

        if(isValid(i_,j_,m,n)) return DFS(i_,j_,o_,m,n,memo,grid,vis);
        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        
        memo_t memo={
            {1,{{},{0,1,1},{},{0,-1,3}}},
            {2,{{-1,0,0},{},{1,0,2},{}}},
            {3,{{0,-1,3},{1,0,2},{},{}}},
            {4,{{0,1,1},{},{},{1,0,2}}},
            {5,{{},{-1,0,0},{0,-1,3},{}}},
            {6,{{},{},{0,1,1},{-1,0,0}}}
        };

        for (int o = 0; o < 4; o++) {
            if (!memo[grid[0][0]][o].empty()) {
                vvint visited(m, vint(n, 0));
                if (DFS(0, 0, o, m, n, memo, grid, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};


int main(){

return 0;
}