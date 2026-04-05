#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    bool check(vvint &mat,vvint &target,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j])
                    return false;
            }
        }
        return true;
    }

    void rotateBy90(vvint &mat,int n){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int count=0, n=mat.size();
        while(count<4){
            if(check(mat,target,n))
                return true;
            rotateBy90(mat,n);
            count++;
        }
        return false;
    }
};

class Solution2 {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n=mat.size(), m=mat[0].size(), fresh=0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                }
                else if(mat[i][j]==1)
                    fresh++;
            }
        }
        
        if(!fresh) return 0;
        
        vector<int> di={-1,0,1,0}, dj={0,1,0,-1};
        
        int timeReq=0;
        while(!q.empty()){
            int sz=q.size();
            bool flag=false;
            while(sz--){
                auto entry=q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int i=entry.first+di[k], j=entry.second+dj[k];
                    if(i>=n || j>=m || i<0 || j<0 || mat[i][j]!=1)
                        continue;
                    mat[i][j]=2;
                    q.push({i,j});
                    flag=true;
                    fresh--;
                }
            }
            if(flag) timeReq++;
        }
        
        return (fresh? -1:timeReq);
    }
};

int main(){

return 0;
}