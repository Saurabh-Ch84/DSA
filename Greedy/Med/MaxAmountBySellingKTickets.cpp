#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod=1e9+7;
    using piint=pair<int,int>;
    using vpiint=vector<piint>;
    struct Comp{
        bool operator()(const piint &a,const piint &b)const{
            if(a.first!=b.first)
                return (a.first<b.first);
            return (a.second>b.second);
        }
    };
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        int n=arr.size(), k_=k, sum=0;
        priority_queue<piint,vpiint,Comp> pq;
        for(int i=0;i<n;i++)
            pq.push({arr[i],0});
        while(k && !pq.empty()){
            auto entry=pq.top(); pq.pop();
            if(entry.second==k_ || entry.first<=0) continue;
            sum=(1L*sum+entry.first)%mod;
            entry.first--;
            entry.second++;
            pq.push(entry);
            k--;
        }
        return sum;
    }
};

int main(){

return 0;
}