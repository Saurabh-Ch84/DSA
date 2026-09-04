#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int maxEnd(vvint &clips,int n){
        int maxi=0;
        for(int i=0;i<n;i++)
            maxi=max(maxi,clips[i][1]);
        return maxi;
    }
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n=clips.size(), m=max(time,maxEnd(clips,n))+1;
        vint reach(m,-1);
        for(int i=0;i<n;i++){
            int st=clips[i][0], end=clips[i][1];
            reach[st]=max(reach[st],end);
        }
        int count=0, maxReach=0, currReach=-1;
        for(int i=0;i<=time;i++){
            if(i>maxReach) return -1;
            maxReach=max(maxReach,reach[i]);
            if(currReach<=i){
                currReach=maxReach;
                count++;
            }
            if(currReach>=time) break;
        }
        return count;
    }
};

int main(){

return 0;
}