#include<bits/stdc++.h>
using namespace std;

class Solution {
    int squareOfDistanceBetweenTwoPoints(int x1,int y1,int x2,int y2){
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    }
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xI=-1, yI=-1;
        if(x1>xCenter) xI=x1;
        else if(x2<xCenter) xI=x2;
        else xI=xCenter;

        if(y1>yCenter) yI=y1;
        else if(y2<yCenter) yI=y2;
        else yI=yCenter;
        int distSquare=squareOfDistanceBetweenTwoPoints(xCenter,yCenter,xI,yI);
        return (radius*radius>=distSquare);
    }
};

int main(){

return 0;
}