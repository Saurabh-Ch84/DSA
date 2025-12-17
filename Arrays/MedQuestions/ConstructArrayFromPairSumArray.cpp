#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        // code here
        int N=arr.size();
        int n=(1+sqrt(8*N+1))/2;
        
        vector<int> res(n);
        
        long long sum_01=arr[0];
        long long sum_02=arr[1];
        long long sum_12=arr[n-1];
        
        res[0]=(sum_01+sum_02-sum_12)/2;
        
        for(int i=1;i<n;i++){
            res[i]=arr[i-1]-res[0];
        }
        
        return res;
    }
};

int main(){

return 0;
}