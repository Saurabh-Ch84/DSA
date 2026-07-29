#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
public:
    int minCost(vint &startPos,vint &homePos,vint &rowCosts,vint &colCosts) {
        int cost=0;
        int sX=startPos[0], sY=startPos[1], dX=homePos[0], dY=homePos[1];
        bool isDown=(dX>=sX), isRight=(dY>=sY);
        while(sX!=dX){
            (isDown? sX++: sX--);
            cost+=rowCosts[sX];
        }
        while(sY!=dY){
            (isRight? sY++:sY--);
            cost+=colCosts[sY];
        }
        return cost;
    }
};

int main(){

return 0;
}