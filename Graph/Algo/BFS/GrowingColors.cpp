#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>

using namespace std;
using vi= vector<int> ;
using pii = pair<int,int> ;

/*
    The "Growing Colors" Problem

Problem Statement: You are given a 2D integer matrix grid of size m x n. 
                   The grid represents a petri dish where different colored bacteria are growing.

0 represents an empty cell.
A positive integer k represents a bacterium of color k.

Every minute, all bacteria expand simultaneously to their adjacent neighbors (up, down, left, right). 
The rules for expansion are:

Growth: If a colored cell is adjacent to an empty cell (0), the empty cell takes that color in the next minute.

Conflict:   If an empty cell is reached by two or more different colors at the exact same time (in the same minute), 
            the  bacteria fight and the cell becomes a "conflict zone". (Usually, this 
            means the cell stays 0 or becomes a special marker -1 and stops growing, depending on the specific variation. 
            Most common CodeSignal variation: The cell stays 0 and cannot be colored ever again.)

Stability: Once a cell has a color, it never changes.

Return the final state of the grid after no more expansion is possible.

Constraints:

1 ≤ m, n ≤ 50 (Small constraints imply you can simulate round-by-round).

1 ≤ grid[i][j] ≤ 100 (Max 100 different colors).

Time Limit: 2.0 seconds.
*/
bool isValid(int i,int j,int n,int m){
    return (i>=0 && i<n && j>=0 && j<m);
}

vector<vi> solve(vector<vi> petriDish){
    int n=petriDish.size(),m=petriDish[0].size();
    queue<pii> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(petriDish[i][j]) q.push({i,j});
        }
    }

    vi di={-1,0,1,0},dj={0,1,0,-1};
    // set<pii> visited;
    while(!q.empty()){  
        map<pii,set<int>> hashMap;
        int sz=q.size();
        while(sz--){
            pii top=q.front();q.pop();
            int i=top.first,j=top.second;
            int color=petriDish[i][j];
            if(color<=0) continue;
            for(int k=0;k<4;k++){
                int i_=i+di[k];
                int j_=j+dj[k];
                if(isValid(i_,j_,n,m) && petriDish[i_][j_]==0)
                    hashMap[{i_,j_}].insert(color);
            }
        }
        for(auto &p: hashMap){
            int i=p.first.first;
            int j=p.first.second;
            if(p.second.size()==1){
                int winner=*p.second.begin();
                petriDish[i][j]=winner;
                q.push({i,j});
            }
            else petriDish[i][j]=-1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(petriDish[i][j]==-1) 
                petriDish[i][j]=0;
        }
    }
    return petriDish;
}


void print(vector<vi> petriDish){
    int n=petriDish.size(),m=petriDish[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<petriDish[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    vector<vi> petriDish={{1,0,2},{0,0,0},{0,3,0}};
    print(petriDish);
    print(solve(petriDish));
return 0;
}