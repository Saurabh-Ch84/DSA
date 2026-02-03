#include<iostream>
#include<vector>
#include<map>
using namespace std;

using vi=vector<int>;
using vll=vector<long long>;
using vvi=vector<vi>;
using vvll=vector<vll>;

class Solution {
        public:
    vector<vector<long long>> splitPainting(vvi & segments) {
        map<int,long long> events;
        for(vi &segment: segments){
            int start=segment[0], end=segment[1], cost=segment[2];
            events[start]+=1LL*cost;
            events[end]-=1LL*cost;
        }
        vvll result;
        long long sum=0;
        int prev=0;
        for(auto &p: events){
            int curr=p.first;
            if(prev && sum>0) result.push_back({prev,curr,sum});
            prev=curr;
            sum+=p.second;
        }
        return result;
    }
};

int main(){

return 0;
}