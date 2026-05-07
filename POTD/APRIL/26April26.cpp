#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    using vch=vector<char>;
    using vvch=vector<vch>;

    using vint=vector<int>;
    using vvint=vector<vint>;

    bool isValid(int i,int j,int m,int n){
        return (i<m && i>=0 && j<n && j>=0);
    }
    bool isParent(int i,int j,int iP,int jP){
        return (i==iP && j==jP);
    }
    bool DFS(int i,int j,int m,int n,vint &di,vint &dj,vvch &grid,vvint &vis,int mk,int iP=-1,int jP=-1){
        if(vis[i][j]==mk) return true;
        vis[i][j]=mk;
        for(int k=0;k<4;k++){
            int i_=i+di[k], j_=j+dj[k];
            if(!isValid(i_,j_,m,n) || isParent(i_,j_,iP,jP) || grid[i_][j_]!=grid[i][j])
                continue;
            bool nextAns=DFS(i_,j_,m,n,di,dj,grid,vis,mk,i,j);
            if(nextAns) return true;
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();

        vvint visited(m,vint(n,0));
        int marker=1;
        vint di={0,1,0,-1}, dj={1,0,-1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && DFS(i,j,m,n,di,dj,grid,visited,marker++))
                    return true;
            }
        }

        return false;
    }
};

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    void helper(int &i1,int &i2,int &i3,int s1,int s2,int s3,int v1,int v2,int v3){
        if(i1<s1-1) i1++;
        else{
            int secMiniVal=min(v2,v3);
            if(secMiniVal==v2){
                if(i2<s2-1) i2++;
                else i3++;
            }
            else{
                if(i3<s3-1) i3++;
                else i2++;
            }
        }
    }
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        vint res;
        int i=0, j=0, k=0;
        int sA=a.size(), sB=b.size(), sC=c.size();
        while(i<sA && j<sB && k<sC){
            int valA=a[i], valB=b[j], valC=c[k];
            if(valA==valB && valA==valC){
                if(res.empty() || res.back()!=valA)
                    res.push_back(valA);
            }
            int miniVal=min({valA,valB,valC});
            if(miniVal==valA) helper(i,j,k,sA,sB,sC,valA,valB,valC);
            else if(miniVal==valB) helper(j,i,k,sB,sA,sC,valB,valA,valC);
            else helper(k,i,j,sC,sA,sB,valC,valA,valB);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int> res;
        int i = 0, j = 0, k = 0;
        int sA = a.size(), sB = b.size(), sC = c.size();
        
        while(i < sA && j < sB && k < sC) {
            int valA = a[i], valB = b[j], valC = c[k];
            
            // 1. If all three match, add it and move ALL pointers forward!
            if(valA == valB && valB == valC) {
                if(res.empty() || res.back() != valA) {
                    res.push_back(valA);
                }
                i++; j++; k++;
            }
            // 2. Otherwise, simply advance the pointer that is lagging behind the most
            else if (valA < valB) {
                i++;
            } 
            else if (valB < valC) {
                j++;
            } 
            else {
                k++;
            }
        }
        return res;
    }
};

int main(){

return 0;
}