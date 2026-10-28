#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isInvalid(int idx,int left,int right){
        return (left<=idx && idx<=right);
    }
  public:
    int minDiff(int k, vector<int> &arr) {
        // code here
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>> maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap; 
        for(int i=k;i<n;i++){
            maxHeap.push({arr[i],i});
            minHeap.push({arr[i],i}); 
        }
        int mini=1e9;
        for(int i=k-1;i<n;i++){
            if(i>=k){
                int right=i, left=i-k+1;
                while(!maxHeap.empty() && isInvalid(maxHeap.top().second,left,right))
                    maxHeap.pop();
                while(!minHeap.empty() && isInvalid(minHeap.top().second,left,right))  
                    minHeap.pop();
                maxHeap.push({arr[i-k],i-k});
                minHeap.push({arr[i-k],i-k}); 
            }
            int maximum=maxHeap.top().first, minimum=minHeap.top().first;
            mini=min(mini,maximum-minimum);
        }
        return mini;
    }
};


int main(){

return 0;
}