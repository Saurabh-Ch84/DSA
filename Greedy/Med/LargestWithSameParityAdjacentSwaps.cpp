#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> lexicographicallyLargest(vector<int> &arr) {
        // code here
        int i=0, n=arr.size();
        vector<int> res;
        while(i<n){
            vector<int> temp;
            int j=i;
            while(j<n && (arr[i]+arr[j])%2==0){
                temp.push_back(arr[j]);
                i=j;
                j++;
            }
            sort(temp.rbegin(),temp.rend());
            res.insert(res.end(),temp.begin(),temp.end());
            i=j;
        }
        return res; 
    }
};

int main(){

return 0;
}