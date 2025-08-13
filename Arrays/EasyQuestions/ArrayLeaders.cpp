#include<iostream>
#include<vector>
using namespace std;

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> res;
        int n=arr.size(),rightMax=arr[n-1];
        res.push_back(rightMax);
        for(int i=n-2;i>-1;i--){
            if(arr[i]>=rightMax) res.push_back(arr[i]);
            rightMax=max(rightMax,arr[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){

return 0;
}