#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        int n=arr.size();
        vint helpingArray;
        for(int i=0;i<n;i++){
            auto itr=lower_bound(helpingArray.begin(),helpingArray.end(),arr[i]);
            if(itr==helpingArray.end()) helpingArray.push_back(arr[i]);
            else *itr=arr[i];
        }
        int lengthOfLIS=helpingArray.size();
        return n-lengthOfLIS;
    }
};

int main(){

return 0;
}