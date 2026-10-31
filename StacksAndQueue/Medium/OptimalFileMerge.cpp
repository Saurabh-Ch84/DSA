#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minComputation(vector<int> &files) {
        // code here
        priority_queue<int,vector<int>,greater<int>> minHeap(files.begin(),files.end());
        int minCost=0;
        while(minHeap.size()>1){
            int x=minHeap.top(); minHeap.pop();
            int y=minHeap.top(); minHeap.pop();
            minCost=minCost+x+y;
            minHeap.push(x+y);
        }
        return minCost;
    }
};

int main(){

return 0;
}