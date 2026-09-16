#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool helper(vector<int>& rec1, vector<int>& rec2){
        int x1=rec1[0], y1=rec1[1], x2=rec1[2], y2=rec1[3];
        int x1_=rec2[0], y1_=rec2[1], x2_=rec2[2], y2_=rec2[3];
        return !(x1_>=x2 || x2_<=x1 || y1_>=y2 || y2_<=y1);
    }
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return helper(rec1,rec2);
    }
};

int main(){

return 0;
}