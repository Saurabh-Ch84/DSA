#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> preXMap;
        preXMap[0]=1;
        long count=0,prefixXOR=0;
        for(int &num:arr){
            prefixXOR=prefixXOR^num;
            int rmXOR=prefixXOR^k;
            count+=preXMap[rmXOR];
            preXMap[prefixXOR]+=1;
        }
        return count;
    }
};

int main(){

return 0;
}