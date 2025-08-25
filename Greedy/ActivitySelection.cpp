#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool comp(const vector<int> &a,const vector<int> &b){
        return a[1]<b[1];
    }
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n=start.size();
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)
            arr.push_back({start[i],finish[i]});
            
        sort(arr.begin(),arr.end(),comp);
        
        int count=1;
        int lastFinish=arr[0][1];
        for(int i=1;i<n;i++){
            int currStart=arr[i][0];
            int currFinish=arr[i][1];
            if(currStart>lastFinish){
                count++;
                lastFinish=currFinish;
            }
        }
        return count;
    }
};

int main(){

return 0;
}