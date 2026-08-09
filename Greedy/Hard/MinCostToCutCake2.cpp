#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(),horizontalCut.rend());
        sort(verticalCut.rbegin(),verticalCut.rend());
        int h=0, v=0, cost=0, M=m-1 ,N=n-1;
        int horizontalPieces=1, verticalPieces=1;
        while(h<M || v<N){
            if(v==N || (h<M && horizontalCut[h]>verticalCut[v])){
                cost+=horizontalCut[h++]*verticalPieces;
                horizontalPieces++;
            }
            else{
                cost+=verticalCut[v++]*horizontalPieces;
                verticalPieces++;
            }
        }
        return cost;
    }
};

int main(){

return 0;
}