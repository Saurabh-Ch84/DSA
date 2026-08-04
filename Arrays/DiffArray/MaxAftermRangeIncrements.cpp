#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
  public:
    int findMax(int n,vint &a,vint &b,vint &k) {
        // code here
        vint diffArr(n+1,0);
        int m=a.size(), maxi=0;
        for(int i=0;i<m;i++){
            int l=a[i], r=b[i], v=k[i];
            diffArr[l]+=v;
            diffArr[r+1]-=v;
        }
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=diffArr[i];
            maxi=max(maxi,currSum);
        }
        return maxi;
    }
};

int main(){

return 0;
}