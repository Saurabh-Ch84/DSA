#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        auto lb_itr=lower_bound(arr.begin(),arr.end(),target);
        if(lb_itr==arr.end() || *lb_itr!=target)
            return 0;
        auto ub_itr=upper_bound(arr.begin(),arr.end(),target);
        int freq=ub_itr-lb_itr;
        return freq;
    }
};


int main(){

return 0;
}