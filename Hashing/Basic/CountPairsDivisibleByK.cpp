#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        int n=arr.size(), count=0;
        vector<int> modulo(k,0);
        for(int i=0;i<n;i++){
            int x=arr[i]%k;
            int y=(k-x)%k;
            count+=modulo[y];
            modulo[x]++;
        }
        return count;
    }
};

int main(){

return 0;
}