#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        // code here
        long long maxiProduct=1;
        int n=arr.size(), left=0, right=n-1;
        sort(arr.begin(),arr.end());
        if(k%2==1){
            if(arr[right]<=0){
                while(k){
                    maxiProduct=maxiProduct*arr[right];
                    right--;
                    k--;
                }
                return maxiProduct;
            }
            else{
                maxiProduct=maxiProduct*arr[right];
                right--;
                k--;
            }
        }
        while(k>0){
            long long leftPair=(long long)arr[left]*arr[left+1];
            long long rightPair=(long long)arr[right]*arr[right-1]; 
            maxiProduct=maxiProduct*max(leftPair,rightPair);
            if(leftPair>rightPair) left+=2;
            else right-=2;
            k-=2;
        }
        return maxiProduct;
    }
};

int main(){

return 0;
}