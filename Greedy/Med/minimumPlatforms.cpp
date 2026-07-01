#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution1 {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        vector<pair<int,int>> vec;
        int n = arr.size();
        for(int i = 0; i < n; i++) vec.push_back({arr[i], dep[i]});
            
        sort(vec.begin(), vec.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(pair<int,int> &p : vec){
            // Use <= to allow platform reuse when departure time equals arrival time
            if(!minHeap.empty() && minHeap.top() <= p.first) minHeap.pop();
            minHeap.push(p.second);
        }
        return minHeap.size();
    }
};

class Solution2 {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int arrPtr=0,depPtr=0,stationCount=0,n=arr.size();
        int count=0;
        while(arrPtr<n && depPtr<n){
            if(arr[arrPtr]<=dep[depPtr])
            {
                arrPtr++;
                count++;
                stationCount=max(count,stationCount);
            }
            else{
                depPtr++;
                count--;
            }
        }
        return stationCount;
    }
};

