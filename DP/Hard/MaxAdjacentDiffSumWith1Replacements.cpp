#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int swapWith1=0, keepTheNum=0;
        for(int i=1;i<n;i++){
            int newSwapWith1=max(swapWith1+abs(1-1),keepTheNum+abs(arr[i-1]-1));
            int newKeepTheNum=max(swapWith1+abs(1-arr[i]),keepTheNum+abs(arr[i-1]-arr[i]));
            swapWith1=newSwapWith1;
            keepTheNum=newKeepTheNum;
        }
        return max(keepTheNum,swapWith1);
    }
};

int main(){

return 0;
}