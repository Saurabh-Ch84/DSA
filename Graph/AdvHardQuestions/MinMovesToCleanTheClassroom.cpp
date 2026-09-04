#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // bfs with bitmasking visited tracking
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
    using vvvvint=vector<vvvint>;
    using vstr=vector<string>;
    vint di={-1,0,1,0}, dj={0,1,0,-1};
    int setKthBit(int num,int k){
        return num|(1<<k);
    }
    bool isValid(int i,int j,int m,int n){
        return (i<m && j<n && i>=0 && j>=0);
    }
    int BFS(int sI,int sJ,int m,int n,int litter,map<pair<int,int>,int> &indexToBitMap,int energy,vstr &classroom){
        int mask=1<<litter, moves=0, target=mask-1;
        queue<vint> q;
        vvvvint dp(m,vvvint(n,vvint(energy+1,vint(mask,0))));
        q.push({sI,sJ,energy,0});
        dp[sI][sJ][energy][0]=1;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto entry=q.front(); q.pop();
                int i=entry[0], j=entry[1], e=entry[2], l=entry[3];
                if(l==target) return moves;
                if(!e) continue;
                for(int k=0;k<4;k++){
                    int i_=i+di[k], j_=j+dj[k];
                    if(!isValid(i_,j_,m,n) || classroom[i_][j_]=='X')
                        continue;
                    int e_=(classroom[i_][j_]=='R'? energy: e-1);
                    int l_=(classroom[i_][j_]=='L'? setKthBit(l,indexToBitMap[{i_,j_}]): l);
                    if(dp[i_][j_][e_][l_]) continue; 
                    else{
                        q.push({i_,j_,e_,l_});
                        dp[i_][j_][e_][l_]=1;
                    }
                }
            }
            moves++;
        }
        return -1;
    }
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size(), n=classroom[0].size(), sI=-1, sJ=-1, litter=0;
        map<pair<int,int>,int> indexToBitMap;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    sI=i, sJ=j;
                }
                else if(classroom[i][j]=='L'){
                    indexToBitMap[{i,j}]=litter;
                    litter++;
                }
            }
        }
        if(!litter) return 0;
        return BFS(sI,sJ,m,n,litter,indexToBitMap,energy,classroom);
    }
};

int main(){

return 0;
}