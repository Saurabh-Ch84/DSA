#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
    void precompute(vector<int> &arr){
        arr.resize(11);
        arr[0]=0;
        for(int i=1;i<=10;i++)
            arr[i]=(arr[i-1]<<1)|1;
    }
public:
    int smallestNumber1(int n) {
        vector<int> arr;
        precompute(arr);
        int lb=*(lower_bound(arr.begin(),arr.end(),n));
        return lb;
    }

    int smallestNumber2(int n){
        int bits=log2(n)+1;
        return (1<<bits)-1;
    }
};

int main(){

return 0;
}