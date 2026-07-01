#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.rbegin(),arr.rend());
        int sum=0, n=arr.size();
        for(int i=0;i<n-1;){
            if(arr[i]-arr[i+1]<k){
                sum=sum+arr[i]+arr[i+1];
                i+=2;
            }
            else i+=1;
        }
        return sum;
    }
};

int main(){

return 0;
}