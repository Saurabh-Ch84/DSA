#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        unordered_set<int> hashSet;
        for(int &e: arr) 
            hashSet.insert(e);
        int count=0;
        for(int &e: arr){
            if(!hashSet.count(e-1))
                count++;
        }
        return count;
    }
};


int main(){

return 0;
}