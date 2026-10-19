#include<bits/stdc++.h>
using namespace std;

class Solution1{
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        long long total=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int val=abs(nums1[i]-nums2[i]);
            total=total+1LL*val*val;
            pq.push(val);
        }
        int k=k1+k2;
        long long mini=total;
        while(k){
            int largestVal=pq.top(); pq.pop();
            int newVal=largestVal-1;
            if(newVal) pq.push(newVal);
            total=total-(1LL*largestVal*largestVal)+(1LL*newVal*newVal);
            mini=min(mini,total);
            k--;
        }
        return max(0LL,mini);
    }
};

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size(), maxDiff=1e5, maxi=-1;
        long long total=0;
        vector<int> countArr(maxDiff+1,0);
        for(int i=0;i<n;i++){
            int val=abs(nums1[i]-nums2[i]);
            countArr[val]++;
            total=total+(1LL*val*val);
            maxi=max(maxi,val);
        }
        int diff=maxi, k=k1+k2;
        while(diff>0 && k>0){
            if(countArr[diff]){
                int count=min(countArr[diff],k);
                k-=count;
                countArr[diff]-=count;
                countArr[diff-1]+=count;
                // total=total-(1LL*count*diff*diff)+(1LL*count*(diff-1)*(diff-1)); // can be simplified.
                total=total-(1LL*count*(2*diff-1));
                if(!total) break;
            }
            diff--;
        }
        return total;
    }
};

int main(){

return 0;
}