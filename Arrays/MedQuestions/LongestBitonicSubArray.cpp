#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n=arr.size(), maxi=0;
        vint increasing(n,0), decreasing(n,0);
        for(int i=1;i<n;i++)
            if(arr[i]>=arr[i-1]) increasing[i]=1+increasing[i-1];
        for(int i=n-2;i>=0;i--)
            if(arr[i]>=arr[i+1]) decreasing[i]=1+decreasing[i+1];
        for(int i=0;i<n;i++)
            maxi=max(maxi,increasing[i]+decreasing[i]+1);
        return maxi;
    }
};

int main(){

return 0;
}