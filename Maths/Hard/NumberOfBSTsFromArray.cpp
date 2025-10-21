#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int memoization(vector<int> &catalanDP,int n){
        if(n<=1) return catalanDP[n]=1;
        if(catalanDP[n]!=-1) return catalanDP[n];
        int result=0;
        for(int i=0;i<n;i++){
            result+=memoization(catalanDP,i)*memoization(catalanDP,n-i-1);
        }
        return catalanDP[n]=result;
    }
  public:
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> catalanDP(n+1,-1);
        memoization(catalanDP,n);
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
	        int rootVal=arr[i];
	        int leftNodeCount=0,rightNodeCount=0;
	        for (int j = 0; j < n; j++) {
	            if(i==j) continue;
	            if(arr[j]<rootVal) leftNodeCount++;
	            else if(arr[j]>rootVal) rightNodeCount++;
            }
            int leftWays=catalanDP[leftNodeCount];
            int rightWays=catalanDP[rightNodeCount];
    
            result.push_back(leftWays*rightWays);
        }
        
        return result;
    }
};

int main(){

return 0;
}