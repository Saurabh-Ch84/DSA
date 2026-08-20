#include<bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
    unordered_map<int,vector<int>> hashMap;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++)
            hashMap[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        vector<int> &range=hashMap[value];
        int freq=upper_bound(range.begin(),range.end(),right)-lower_bound(range.begin(),range.end(),left);
        return freq;
    }
};

int main(){

return 0;
}