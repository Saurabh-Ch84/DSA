#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    vector<int> getNextSmallerIdx(vector<int> &arr,int n){
        vector<int> nseIdx(n,n);
        stack<int> tempStack;
        for(int i=n-1;i>-1;i--){
            while(!tempStack.empty() && arr[i]<=arr[tempStack.top()]) 
                tempStack.pop();
            if(!tempStack.empty()) nseIdx[i]=tempStack.top();
            tempStack.push(i);
        }
        return nseIdx;
    }

    vector<int> getPrevSmallerEqualIdx(vector<int> &arr,int n){
        vector<int> pseIdx(n,-1);
        stack<int> tempStack;
        for(int i=0;i<n;i++){
            while(!tempStack.empty() && arr[i]<arr[tempStack.top()]) 
                tempStack.pop();
            if(!tempStack.empty()) pseIdx[i]=tempStack.top();
            tempStack.push(i);
        }
        return pseIdx;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nextSIdx,prevSEqIdx;
        nextSIdx=getNextSmallerIdx(arr,n);
        prevSEqIdx=getPrevSmallerEqualIdx(arr,n);
        long long totalSum=0;
        int mod=(int)(1e9+7);
        for(int i=0;i<n;i++){
            int left=i-prevSEqIdx[i];
            int right=nextSIdx[i]-i;
            totalSum+=(right*left*1LL*arr[i])%mod;
            totalSum%=mod;
        }
        return (int)totalSum;
    }
};

int main(){

return 0;
}