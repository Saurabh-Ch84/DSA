#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
  public:
    vint optimalArray(vint &arr) {
        // code here
        int n=arr.size();
        vint res={0}, prefixSum(n,0);
        prefixSum[0]=arr[0];
        for(int i=1;i<n;i++)
            prefixSum[i]=prefixSum[i-1]+arr[i];
        
        for(int i=1;i<n;i++){
            int sz=i+1, median=-1;
            if(sz%2) median=arr[sz/2];
            else median=(arr[sz/2-1]+arr[sz/2]+1)/2;
            int leftOps=(sz/2)*median-prefixSum[sz/2-1];
            int rightOps=prefixSum[i]-prefixSum[sz/2-1]-(i+1-sz/2)*median;
            res.push_back(leftOps+rightOps);
        }
        return res;
    }
};

int main(){

return 0;
}