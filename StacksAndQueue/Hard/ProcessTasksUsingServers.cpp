#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;

    using vll=vector<long long>;
    using vvll=vector<vll>;
public:
    vint assignTasks(vint &servers,vint &tasks) {
        int n=servers.size(), m=tasks.size();
        priority_queue<vll,vvll,greater<vll>> pq1, pq2;
        for(int i=0;i<n;i++)
            pq1.push({servers[i],i});
        vint res(m,-1);
        long long time=0;
        for(int i=0;i<m;i++){
            if(time<i) time=i; // multiple tasks can be assigned at the same time, wait for the next task to arrive
            if(pq1.empty()) time=max(time,pq2.top()[0]); // wait for the next server to be free
            while(!pq2.empty() && pq2.top()[0]<=time){
                int w=pq2.top()[1], idx=pq2.top()[2];
                pq1.push({w,idx});
                pq2.pop();
            }
            vll entry=pq1.top(); pq1.pop();
            int w=entry[0], idx=entry[1];
            res[i]=idx;
            pq2.push({time+tasks[i],w,idx});
        }
        return res;
    }
};

int main(){

return 0;
}