#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_set<int> hashSet;
        for(int &num: arr){
            if(!hashSet.count(num*num))
                hashSet.insert(num*num);
        }
        
        for(auto itrI=hashSet.begin();itrI!=hashSet.end();itrI++){
            int a2=*itrI;
            for(auto itrJ=itrI;itrJ!=hashSet.end();itrJ++){
                int b2=*itrJ;
                if(hashSet.count(a2+b2)) return true;
            }
        }
        return false;
    }
};

int main(){

return 0;
}