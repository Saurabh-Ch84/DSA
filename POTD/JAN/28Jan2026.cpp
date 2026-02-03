#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

using vi = vector<int> ;
class Solution {
    int recursion(int i,int k,int n,vi &arr,unordered_map<string,int> &memo){
        if(i>=n) return (k==0);
        string key=to_string(i)+"_"+to_string(k);
        if(memo.count(key)) return memo[key];
        int notTake=recursion(i+1,k,n,arr,memo);
        int take=recursion(i+1,k-arr[i],n,arr,memo);
        return memo[key]=notTake+take;
    }
  public:
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int pSum=0, nSum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0) pSum+=arr[i];
            else nSum+=arr[i];
        }
        if(k>pSum || k<nSum) return 0;
        unordered_map<string,int> memo;
        return recursion(0,k,n,arr,memo);
    }
};

using vi = vector<int> ;
using vll = vector<long long> ;
class Solution {
    void getSubSetSums(vll &sum,vi &arr){
        sum.push_back(0);
        for(int &num: arr){
            int n=sum.size();
            for(int i=0;i<n;i++){
                sum.push_back(sum[i]+num);
            }
        }
    }
  public:
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n=arr.size(),mid=n/2;
        vi left,right;
        for(int i=0;i<mid;i++)
            left.push_back(arr[i]);
        for(int i=mid;i<n;i++)
            right.push_back(arr[i]);
            
        vll leftSums,rightSums;
        getSubSetSums(leftSums,left);
        getSubSetSums(rightSums,right);
        
        sort(rightSums.begin(),rightSums.end());
        
        int count=0;
        for(long long &lSum: leftSums){
            long long rSum=k-lSum;
            auto range=equal_range(rightSums.begin(),rightSums.end(),rSum);
            count+=range.second-range.first;
        }
        return count;
    }
};

int main(){

return 0;
}