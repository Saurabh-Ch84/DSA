#include<iostream>
#include<vector>
using namespace std;

// Brute-Force
class Solution1 {
    int recursion(int i,int n,int ans,vector<int> &arr){
        if(i>=n){
            return ans;
        }
        int take = recursion(i+1,n,ans^arr[i],arr);
        int notTake = recursion(i+1,n,ans,arr);
        return take+notTake;
    }
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        return recursion(0,n,0,arr);
    }
};

// Optimised Solution
class Solution2 {
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int totalOR=0;
        for(int i=0;i<n;i++)
            totalOR=totalOR | arr[i];
        return totalOR<<(n-1);
    }
};

int main(){

return 0;
}