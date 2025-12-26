#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using vi = vector<int> ;
class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(),arr.end());
        vi result;
        for(vi &query: queries){
            int a=query[0],b=query[1];
            int lb=lower_bound(arr.begin(),arr.end(),a)-arr.begin();
            int ub=upper_bound(arr.begin(),arr.end(),b)-arr.begin();
            int count=ub-lb;
            result.push_back(count);
        }
        return result;
    }
};

int main(){

return 0;
}