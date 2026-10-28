#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(int n, int m, string& s) {
        // code here
        unordered_map<char,pair<int,int>> hashMap={
            {'L',{0,-1}},
            {'R',{0,1}},
            {'D',{-1,0}},
            {'U',{1,0}}
        };
        int i=0, j=0, minI=0, maxI=0, minJ=0, maxJ=0;
        for(const char &move: s){
            i=i+hashMap[move].first, j=j+hashMap[move].second;
            minI=min(minI,i), maxI=max(maxI,i); 
            minJ=min(minJ,j), maxJ=max(maxJ,j);
            if(maxI-minI+1>n || maxJ-minJ+1>m) return 0;
        }
        return 1;
    }
};

int main(){

return 0;
}