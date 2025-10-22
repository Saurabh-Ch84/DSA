#include<iostream>
#include<queue>
using namespace std;

using g=greater<int>;
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        priority_queue<int,vector<int>,g> pq(arr.begin(),arr.begin()+k+1);
        for(int i=0;i<n;i++){
            arr[i]=pq.top();
            pq.pop();
            if(i + k + 1 < n) pq.push(arr[i+k+1]);
        }
    }
};

int main(){

return 0;
}