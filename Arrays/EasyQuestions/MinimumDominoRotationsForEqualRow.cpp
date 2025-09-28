#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    pair<int,int> minOperations(int domino,vector<int>& tops,vector<int> &bottoms,int n){
        int topCount=0,bottomCount=0;
        for(int i=0;i<n;i++){
            if(tops[i]!=domino && bottoms[i]!=domino){
                return {-1,-1};
            }
            else if(tops[i]==domino && bottoms[i]!=domino)
                bottomCount++;
            else if(tops[i]!=domino && bottoms[i]==domino)
                topCount++;
        }
        return {topCount,bottomCount};
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size(),mini=INT_MAX;
        vector<int> arr={tops[0],bottoms[0]};

        for(int i=0;i<2;i++){
            pair<int,int> p=minOperations(arr[i],tops,bottoms,n);
            int top=(p.first==-1) ? INT_MAX : p.first;
            int bottom=(p.second==-1) ? INT_MAX : p.second;
            mini=min({mini,top,bottom});
        }
        
        return (mini==INT_MAX) ?-1:mini;
    }
};

int main(){

return 0;
}