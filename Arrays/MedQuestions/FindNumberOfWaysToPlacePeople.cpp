#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<vector<int>>& points,int i,int j,int n){
        int lbx=min(points[i][0],points[j][0]);
        int ubx=max(points[i][0],points[j][0]);
        int lby=min(points[i][1],points[j][1]);
        int uby=max(points[i][1],points[j][1]);
        for(int k=0;k<n;k++){
            if(k==i || k==j) continue;
            int x=points[k][0],y=points[k][1];
            if(lbx<=x && x<=ubx && lby<=y && y<=uby) return false;
        }
        return true;
    }
public:
    // Brute Force
    int numberOfPairsBrute(vector<vector<int>>& points) {
        int n=points.size(),count=0;
        for(int i=0;i<n;i++){
            int x=points[i][0],y=points[i][1];
            for(int j=i+1;j<n;j++){
                int x_=points[j][0],y_=points[j][1];
                if(y>=y_ && x<=x_)
                    count+=isPossible(points,i,j,n);
                else if(y_>=y && x_<=x)
                    count+=isPossible(points,j,i,n);
            }
        }
        return count;
    }
    //optimal Version
    static bool comp(const vector<int> &a,const vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }

    int numberOfPairsOptimal(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int n=points.size(),count=0;
        for(int i=0;i<n;i++){
            int y=points[i][1],criticalY=-1;
            for(int j=i+1;j<n;j++){
                int y_=points[j][1];
                if(y_<=y && y_>criticalY){
                    count++;
                    criticalY=y_;
                }
            }
        }
        return count;
    }
};

int main(){

return 0;
}