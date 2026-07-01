#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int prev=0, n=arr.size(), maxi=0;
        for(int i=0;i<n;i++){
            int diff=arr[i]-prev;
            if(diff>1) arr[i]=prev+1;
            maxi=max(maxi,arr[i]);
            prev=arr[i];
        }
        return maxi;
    }
};

int main(){

return 0;
}