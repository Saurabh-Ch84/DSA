#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        unordered_map<int,int> hashMap;
        set<int> set_;
        vector<int> ans(n,1);

        for(int i=0;i<n;i++){
            if(rains[i]==0){
                set_.insert(i);
                continue;
            }
            if(hashMap.count(rains[i])){
                if(set_.empty()) return {};
                auto it=set_.lower_bound(hashMap[rains[i]]);
                if(it==set_.end()) return {};
                int idx=*it;
                ans[idx]=rains[i];
                set_.erase(it);
            }
            ans[i]=-1;
            hashMap[rains[i]]=i;
        }
        return ans;
    }
};

int main(){

return 0;
}