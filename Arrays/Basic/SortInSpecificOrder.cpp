#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    struct Comp{
        bool operator()(const int &a,const int &b){
            bool isOddA= a&1;
            bool isOddB= b&1;
            if(isOddA && isOddB) return a>b;
            else if(isOddA && !isOddB) return true;
            else if(!isOddA && isOddB) return false;
            else return a<b;
        }
    };
  public:
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end(),Comp());
    }
};

int main(){

return 0;
}