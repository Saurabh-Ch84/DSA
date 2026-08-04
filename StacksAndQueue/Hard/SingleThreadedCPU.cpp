#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    vint getOrder(vvint &tasks) {
        priority_queue<vint,vvint,greater<vint>> pq1, pq2;
        int n=tasks.size();
        for(int i=0;i<n;i++)
            pq1.push({tasks[i][0],tasks[i][1],i});

        long long time=0;
        vint order;
        while(order.size()!=n){
            if(!pq1.empty() && pq2.empty())
                time=max(time,1LL*pq1.top()[0]);
            while(!pq1.empty() && pq1.top()[0]<=time){
                vint entry=pq1.top(); pq1.pop();
                int processingTime=entry[1], index=entry[2];
                pq2.push({processingTime,index});
            }
            vint entry=pq2.top(); pq2.pop();
            int processingTime=entry[0], idx=entry[1];
            order.push_back(idx);
            time=time+processingTime;
        }
        return order;
    }
};

int main(){

return 0;
}