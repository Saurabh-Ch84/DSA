#include<iostream>
#include<vector>
#include<climits>

using namespace std;
using vi=vector<int>;

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int left=0, right=0;
        long long sum=0, maxi=0;
        while(right<n){
            sum+=arr[right];
            if(right-left+1==k){
                maxi=max(maxi,sum);
                sum-=arr[left];
                left++;
            }
            right++;
        }
        return (int)maxi;
    }
};

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int mini=INT_MAX, count=0;
        for(vi &arr : matrix){
            for(int &num: arr){
                if(num<0) count++;
                int absNum=abs(num);
                sum+=absNum;
                mini=min(mini,absNum);
            }
        }
        return ((count%2==1)? sum-2*mini: sum);
    }
};

int main(){

return 0;
}