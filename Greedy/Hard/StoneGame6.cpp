#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector<vector<int>> arr(n);
        for(int i=0;i<n;i++)
            arr[i]={aliceValues[i]+bobValues[i],i};
        sort(arr.rbegin(),arr.rend());
        int alice=0, bob=0;
        for(int i=0;i<n;i++){
            int idx=arr[i][1];
            if(i%2==0) alice=alice+aliceValues[idx];
            else bob=bob+bobValues[idx];
        }
        if(alice==bob) return 0;
        return (alice>bob? 1: -1);
    }
}; 

int main(){

return 0;
}