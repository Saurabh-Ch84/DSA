#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> startEnd(n+1,0);
        for(int i=0;i<n+1;i++){
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            startEnd[left]=max(startEnd[left],right);
        }
        int count=0, maxReach=0, currReach=0;
        for(int i=0;i<n+1;i++){
            if(i>maxReach) return -1;
            if(i>currReach){
                count++;
                currReach=maxReach;
            }
            maxReach=max(maxReach,startEnd[i]);
        }
        return count;
    }
};

int main(){

return 0;
}