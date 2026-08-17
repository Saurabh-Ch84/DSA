#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        if(!x) return 1;
        if(s>x) return 0;
        vector<long long> newArr={s};
        int n=arr.size(), i=0;
        long long totalSum=s; 
        while(i<n && totalSum+arr[i]<=x){
            long long currSum=totalSum+arr[i];
            newArr.push_back(currSum);
            totalSum+=currSum;
            i++;
        }
        int m=newArr.size(), target=x;
        for(int i=m-1;i>=0;i--){
            if(newArr[i]==target) return 1;
            if(newArr[i]>target) continue;
            else target-=newArr[i];
        }
        return 0;
    }
};

int main(){

return 0;
}