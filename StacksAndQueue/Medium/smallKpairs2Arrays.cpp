#include<iostream>
#include<bits/stdc++.h>
using namespace std;

using vi=vector<int>;
class Solution {
    struct Comp{
      bool operator()(const vi &a,const vi &b) const{
          long long A=(long long)a[0]+a[1];
          long long B=(long long)b[0]+b[1];
          return A>B;
      }
    };
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        int n=arr1.size(),m=arr2.size();
        
        priority_queue<vi,vector<vi>,Comp> pq;
        set<pair<int,int>> hashSet;
        vector<vi> res;
        
        pq.push({arr1[0],arr2[0],1,1});
        hashSet.insert({0,0});
        
        while(k && !pq.empty()){
            vi p=pq.top();
            pq.pop();
            int leftVal=p[0],rightVal=p[1];
            int left=p[2],right=p[3];
            res.push_back({leftVal,rightVal});
            if(left<n && !hashSet.count({left+1,right})){
                pq.push({arr1[left],rightVal,left+1,right});
                hashSet.insert({left+1,right});
            }
            if(right<m && !hashSet.count({left,right+1})) {
                pq.push({leftVal,arr2[right],left,right+1});
                hashSet.insert({left,right+1});
            }
            k--;
        }
        return res;
    }
};


int main(){

return 0;
}