#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    long long maxScore(vint &nums1,vint &nums2,int k) {
        int n=nums1.size();
        vvint arr(n);
        for(int i=0;i<n;i++)
            arr[i]={nums2[i],nums1[i]};

        sort(arr.rbegin(),arr.rend());
        priority_queue<int,vint,greater<int>> pq;
        long long maxi=0, sum=0;
        for(int i=0;i<n;i++){
            int miniInNums2=arr[i][0], curr=arr[i][1];
            sum+=curr;
            while(pq.size()>=k){ 
                // remove the smallest element from the priority queue if we have more than k or equal to k elements
                int minPrev=pq.top(); pq.pop();
                sum-=minPrev;
            }
            pq.push(curr); // this will be the kth element in the priority queue
            if(pq.size()==k) maxi=max(maxi,sum*miniInNums2);
        }
        return maxi;
    }
};

int main(){

return 0;
}