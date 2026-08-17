#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        int mini=arr[0], negatives=0, maxNegative=-1e9;
        long long nonZeroProduct=1;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                maxNegative=max(maxNegative,arr[i]);
                negatives++;
            }
            if(arr[i]) nonZeroProduct=nonZeroProduct*arr[i];
            mini=min(mini,arr[i]);
        }
        
        if(!negatives) return mini; // if no negative numbers, return the minimum number
        else if(negatives%2==1) return nonZeroProduct; // if odd number of negative numbers, return the product of all non-zero numbers
        else return nonZeroProduct/maxNegative; // if even number of negative numbers, 
        // return the product of all non-zero numbers divided by the maximum negative number.
    }
};

int main(){

return 0;
}