#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using vvi = vector<vector<int>> ;
class Solution {
    bool isOverlapping(const vector<int> &a,const vector<int> &b){
        return (a[0]<=b[0] && a[1]>=b[0]);
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vvi ans;
        int n=intervals.size();
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(isOverlapping(ans.back(),intervals[i])){
                ans.back()[0]=min(ans.back()[0],intervals[i][0]);
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};

int main(){

return 0;
}