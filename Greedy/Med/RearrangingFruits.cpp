#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> hashMap;
        int n=basket1.size(),minEle=INT_MAX;

        for(int i=0;i<n;i++){
            hashMap[basket1[i]]++;
            hashMap[basket2[i]]--;
            minEle=min({minEle,basket1[i],basket2[i]});
        }

        vector<int> arr;
        for(auto &p:hashMap){
            int fruit=p.first,balance=p.second;
            if(balance==0) continue;
            balance=abs(balance);
            if(balance%2==1) return -1;
            for(int i=0;i<balance/2;i++){
                arr.push_back(fruit);
            }
        }

        if(arr.empty()) return 0;
        long long ans=0;
        sort(arr.begin(),arr.end());
        int m=arr.size();
        for(int i=0;i<m/2;i++){
            ans+=min(arr[i],2*minEle);
        }
        return ans;
    }
};

int main(){

return 0;
}