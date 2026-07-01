#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int maxi=0;
        for(int &l: left){
            int t=l;
            maxi=max(maxi,t);
        }
        for(int &r: right){
            int t=n-r;
            maxi=max(maxi,t);
        }
        return maxi;
    }
};

int main(){

return 0;
}