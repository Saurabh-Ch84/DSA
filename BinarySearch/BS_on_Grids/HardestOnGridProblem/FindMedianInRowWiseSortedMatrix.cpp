#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// User function template for C++

class Solution {
    bool check(vector<vector<int>>& mat,int halfLen,int mid){
        int target=mid;
        int ubSumTarget=0;
        for(vector<int> &arr:mat){
            int ub=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
            ubSumTarget+=ub;
            if(ubSumTarget>halfLen) return true;
        }
        return false;
    }
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        int halfLen=(n*m)/2;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool response=check(mat,halfLen,mid);
            if(response) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};


int main(){

return 0;
}