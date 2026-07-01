#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

using vi=vector<int>;
class Solution {
public:
    int findMaximizedCapital(int k, int w,vi &profits,vi &capital){
        int n=capital.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++)
            arr.push_back({capital[i],profits[i]});
            
        sort(arr.begin(),arr.end());
        priority_queue<int> pq;
        int idx=0;
        while(k--){
            while(idx<n && arr[idx].first<=w){
                pq.push(arr[idx].second);
                idx++;
            }
            if(pq.empty()) break;
            w+=pq.top(); pq.pop();
        }
        return w;
    }
};

int main(){

return 0;
}