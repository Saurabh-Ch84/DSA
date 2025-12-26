#include<iostream>
#include<vector>
using namespace std;

// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size(), m=arr[0].size(), maxRowIdx=-1;
        int row=0, col=m-1;
        while(row<n && col>=0){
            int val=arr[row][col];
            if(val){
                maxRowIdx=row;
                col--;
            }
            else row++;
        }
        return maxRowIdx;
    }
};

int main(){

return 0;
}