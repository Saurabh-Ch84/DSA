#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    int maxPerformance(int n,vint &speed,vint &efficiency, int k) {
        vvint arr(n);
        for(int i=0;i<n;i++)
            arr[i]={efficiency[i],speed[i]};
        sort(arr.rbegin(),arr.rend());
        priority_queue<int,vint,greater<int>> pq;
        int mod=1e9+7;
        long long maxi=0, sumOfSpeed=0;
        for(int i=0;i<n;i++){
            int minEfficiency=arr[i][0], currSpeed=arr[i][1];
            sumOfSpeed+=currSpeed;
            while(pq.size()==k){
                int minSpeed=pq.top(); pq.pop();
                sumOfSpeed-=minSpeed;
            }
            maxi=max(maxi,sumOfSpeed*minEfficiency);
            pq.push(currSpeed);
        }
        return maxi%mod;
    }
};

int main(){

return 0;
}