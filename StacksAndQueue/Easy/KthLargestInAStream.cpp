#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class KthLargest {
    priority_queue<int,vector<int>,greater<int>> heapK;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<min(k,n);i++)
            heapK.push(nums[i]);
    }
    
    int add(int val) {
        if(heapK.size()<k) heapK.push(val);
        else if(val>heapK.top()){
            heapK.pop();
            heapK.push(val);
        }
        return heapK.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(){

return 0;
}