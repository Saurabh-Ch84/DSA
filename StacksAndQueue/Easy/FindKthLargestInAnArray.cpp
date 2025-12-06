#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int &num: nums){
            if(pq.size()<k) pq.push(num);
            else{
                int top=pq.top();
                if(num>top){
                    pq.pop();
                    pq.push(num);
                }
            }
        }
        return pq.top();
    }
};

int main(){

return 0;
}