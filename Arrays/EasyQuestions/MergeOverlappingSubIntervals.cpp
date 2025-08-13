#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    bool overlap(const vector<int> &curr,const vector<int> &prev){
        return curr[0]<=prev[1];
    }
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        res.push_back(arr[0]);
        int n=arr.size();
        int ptr=1;
        while(ptr<n){
            vector<int> &curr=arr[ptr++];
            vector<int> &prev=res.back();
            if(overlap(curr,prev))
                prev[1]=max(prev[1],curr[1]);
            else res.push_back(curr);
        }
        return res;
    }
};

int main(){

return 0;
}