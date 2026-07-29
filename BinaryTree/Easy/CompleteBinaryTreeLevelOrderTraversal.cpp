#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        // complete binary tree level order generation
        // property: 0 or 2 children for each node and the children are filled from left to right.
        vvint levelArray;
        int i=0, n=arr.size(), level=0; 
        while(i<n){
            int sz=(1<<level);
            vint currLevel;
            // prevent overflow of j by checking j<n in the loop condition
            for(int j=i;j<i+sz && j<n;j++)
                currLevel.push_back(arr[j]);    
            sort(currLevel.begin(),currLevel.end());
            levelArray.push_back(currLevel);
            i=i+sz;
            level++;
        }
        return levelArray;
    }
};


int main(){

return 0;
}