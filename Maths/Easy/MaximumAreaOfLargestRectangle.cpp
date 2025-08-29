#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area=0,diaSq=0;
        for(vector<int> &dim:dimensions){
            double dSquare=dim[0]*dim[0]+dim[1]*dim[1];
            if(dSquare>diaSq){
                diaSq=dSquare;
                area=dim[0]*dim[1];
            }
            else if(dSquare==diaSq) area=max(area,dim[0]*dim[1]);
        }
        return area;
    }
};

int main(){
    Solution s;
    vector<vector<int>>  dimensions1 = {{3,4},{4,3}};
    vector<vector<int>>  dimensions2 = {{6,5},{8,6},{2,10},{8,1},{9,2},{3,5},{3,5}};
    cout<<s.areaOfMaxDiagonal(dimensions2);
return 0;
}