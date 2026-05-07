#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int m=mat.size(), n=mat[0].size();
        unordered_map<int,unordered_set<int>> hashMap;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx=j-i;
                hashMap[idx].insert(mat[i][j]);
                if(hashMap[idx].size()>1)
                    return false;
            }
        }
        return true;
    }
};

class Solution {
    using piint=pair<int,int>;
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
    using vvvvint=vector<vvvint>;
    using vvvvvint=vector<vvvvint>;

    int getCost(int x,int y,int x_,int y_){
        if(x_==-1 && y_==-1) return 0; 
        return abs(x-x_)+abs(y-y_);
    }
    
    piint getCoords(char ch){
        int offset=ch-'A';
        return {offset/6,offset%6};
    }
    
    int recursion(string &word,int n,int i,int x1,int y1,int x2,int y2,vvvvvint &dp){
        if(i==n) return 0;
        if(dp[i][x1+1][x2+1][y1+1][y2+1] != -1) return dp[i][x1+1][x2+1][y1+1][y2+1];
        char letter=word[i];
        piint coords=getCoords(letter);
        int x=coords.first, y=coords.second;
        int finger1=getCost(x,y,x1,y1)+recursion(word,n,i+1,x,y,x2,y2,dp);
        int finger2=getCost(x,y,x2,y2)+recursion(word,n,i+1,x1,y1,x,y,dp);
        return dp[i][x1+1][x2+1][y1+1][y2+1] = min(finger1,finger2);
    }
    
public:
    int minimumDistance(string word){
        int n=word.size();
        vvvvvint dp(n,vvvvint(6,vvvint(6,vvint(7,vint(7,-1)))));
        return recursion(word,n,0,-1,-1,-1,-1,dp);
    }
};

int main(){

return 0;
}