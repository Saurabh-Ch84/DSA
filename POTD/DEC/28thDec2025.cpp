#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

// LEETCODE
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int row=0, col=m-1, neg=0;
        while(row<n && col>=0){
            if(grid[row][col]<0){
                neg++;
                col--;
            }
            else{
                row++;
                if(row<n) neg+=(m-col-1);
            }
        }
        if(col<0) neg+=(n-1-row)*m;
        return neg;
    }
};

// GFG
class Solution {
    int timeToMakeDonuts(int x,int n){
        return ((n*(n+1))/2)*x;
    }
    int numberOfDonuts(int mid, int r){
        double  m=(double)mid;
        double ans=sqrt((2*m)/r+0.25)-(0.5);
        return (int)ans;
    }
    bool check(vector<int> &ranks, int mid, int n, int m){
        int total=0;
        for(int i=0;i<m;i++){
            int donuts=numberOfDonuts(mid,ranks[i]);
            total+=donuts;
            if(total>=n) return true;
        }
        return false;
    }
  public:
    int minTime(vector<int>& ranks, int n) {
        // code here
        int m=ranks.size(), mini=INT_MAX;
        for(int i=0;i<m;i++)
            mini=min(mini,ranks[i]);
    
        int high=timeToMakeDonuts(mini,n), low=0;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool response=check(ranks,mid,n,m);
            if(response){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};

int main(){

return 0;
}