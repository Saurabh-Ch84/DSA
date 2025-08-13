#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size(),m=mat[0].size();
        int low=0,high=n*m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int i=mid/m,j=mid%m;
            int ele=mat[i][j];
            if(ele==x) return true;
            else if(ele>x) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};

int main(){

return 0;
}