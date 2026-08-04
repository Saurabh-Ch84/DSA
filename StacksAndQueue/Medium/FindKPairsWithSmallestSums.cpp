#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    vvint kSmallestPairs(vint &nums1,vint &nums2,int k) {
        int n1=nums1.size(), n2=nums2.size();
        priority_queue<vint,vvint,greater<vint>>  pq;
        for(int i=0;i<n1;i++)
            pq.push({nums1[i]+nums2[0],i,0});
        vvint res;
        while(!pq.empty() && res.size()<k){
            vint entry=pq.top(); pq.pop();
            int i=entry[1], j=entry[2];
            res.push_back({nums1[i],nums2[j]});
            if(j<n2-1) pq.push({nums1[i]+nums2[j+1],i,j+1});
        }
        return res;
    }
};

int main(){

return 0;
}