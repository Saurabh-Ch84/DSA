#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    double areaOfTriangle(vector<int> &A,vector<int> &B,vector<int> &C){
        return 0.5*abs(A[0]*(B[1]-C[1])-A[1]*(B[0]-C[0])+B[0]*C[1]-B[1]*C[0]);
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double maxArea=0.0;
        for(int i=0;i<n;i++){
            vector<int> &A=points[i];
            for(int j=i+1;j<n;j++){
                vector<int> &B=points[j];
                for(int k=j+1;k<n;k++){
                    vector<int> &C=points[k];
                    maxArea=max(maxArea,areaOfTriangle(A,B,C));
                }
            }
        }
        return maxArea;
    }
};

int main(){
    Solution s;
    vector<vector<int>> points={{1,2},{9,0},{4,5},{0,3},{-1,4},{11,20}};
    cout<<s.largestTriangleArea(points);
return 0;
}