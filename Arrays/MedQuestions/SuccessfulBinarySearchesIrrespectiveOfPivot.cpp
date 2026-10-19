#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        // code here
        int n=arr.size(), inf=1e8;
        vector<int> suffixMin(n,inf);
        suffixMin[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            suffixMin[i]=min(suffixMin[i+1],arr[i]);
        }
        int count=0, prefixMax=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=prefixMax && arr[i]<=suffixMin[i]) count++;
            prefixMax=max(prefixMax,arr[i]);
        }
        return count;
    }
};

int main(){

return 0;
}