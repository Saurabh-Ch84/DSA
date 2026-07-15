#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int maxPositiveSegmentSum(vint &a,int n){
        int sum=0, maxi=0;
        for(int i=0;i<n;i++){
            if(!a[i]){
                sum=0;
                continue;
            }
            sum++;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
  public:
    int largestArea(int n, int m, int k, vvint &arr) {
        // code here
        vint row(n,1), col(m,1);
        for(int i=0;i<k;i++){
            int r=arr[i][0], c=arr[i][1];
            row[r-1]=0, col[c-1]=0;
        }
        return maxPositiveSegmentSum(row,n)*maxPositiveSegmentSum(col,m);
    }
};

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int getMaxFreeLength(vint &a,int n){
        int prev=-1, maxi=0;
        for(int &curr: a){
            int gap=curr-prev-1;
            maxi=max(maxi,gap);
            prev=curr;
        }
        return maxi;
    }
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        // code here
        vint row={n}, col={m};
        for(vint &coord: arr){
            int r=coord[0]-1, c=coord[1]-1;
            row.push_back(r);
            col.push_back(c);
        }
        sort(row.begin(),row.end());
        sort(col.begin(),col.end());
        return getMaxFreeLength(row,n)*getMaxFreeLength(col,m);
    }
};

int main(){

return 0;
}
