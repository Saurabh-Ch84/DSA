#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// User function template for C++
class Solution {
    int numOfOnes(vector<int> &arr,int n){
        int lb=lower_bound(arr.begin(),arr.end(),1)-arr.begin();
        return n-lb;
    }
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size(),m=arr[0].size(),rowOnesCount=0,rowIndx=-1;
        for(int i=0;i<n;i++){
            int ones=numOfOnes(arr[i],m);
            if(ones>rowOnesCount){
                rowOnesCount=ones;
                rowIndx=i;
            }
        }
        return rowIndx;
    }
};

int main(){

return 0;
}