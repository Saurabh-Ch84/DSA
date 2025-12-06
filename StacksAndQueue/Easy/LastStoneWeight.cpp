#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        pq.push(0);
        while(pq.size()>1){
            int y=pq.top();pq.pop();
            int x=pq.top();pq.pop();
            if(y!=x) pq.push(y-x);
        }
        return pq.top();
    }
};

int main(){

return 0;
}