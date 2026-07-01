#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n=arr.size(), ans=arr[0];
        long prevNoDelete=arr[0], prevOneDelete=INT_MIN;
        for(int i=1;i<n;i++){
            long currNoDelete=max(prevNoDelete+arr[i],1L*arr[i]);
            long currOneDelete=max(prevOneDelete+arr[i],prevNoDelete);
            ans=max({1L*ans,currNoDelete,currOneDelete});
            prevNoDelete=currNoDelete;
            prevOneDelete=currOneDelete;
        }
        return ans;
    }
};

int main(){

return 0;
}