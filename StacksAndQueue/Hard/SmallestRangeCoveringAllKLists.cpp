#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    vint smallestRange(vvint &nums) {
        int n=nums.size(),maxi=-1e9;
        priority_queue<vint,vvint,greater<vint>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],0,i});
            maxi=max(maxi,nums[i][0]);
        }
        int range=1e9, low=1e9, high=-1e9;
        while(!pq.empty()){
            vint entry=pq.top(); pq.pop();
            int mini=entry[0], j=entry[1], i=entry[2], m=nums[i].size();
            int currRange=maxi-mini+1; // inclusive range
            if(currRange<range){
                range=currRange;
                low=mini;
                high=maxi;
            }
            if(j==m-1) break;
            else{
                maxi=max(maxi,nums[i][j+1]);
                pq.push({nums[i][j+1],j+1,i});
            }
        }
        return {low,high};
    }
};

int main(){

return 0;
}