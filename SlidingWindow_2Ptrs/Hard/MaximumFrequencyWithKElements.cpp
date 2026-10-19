#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size(), left=0, right=0, sum=0, maxF=0;
        while(right<n){
            sum+=arr[right];
            while((right-left+1)*(arr[right])-sum>k && left<=right){
                sum-=arr[left];
                left++;
            }
            maxF=max(maxF,right-left+1);
            right++;
        }
        return maxF;
    }
};

int main(){
    
return 0;
}