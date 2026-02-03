#include<iostream>
#include<vector>
#include<climits>
#include<numeric>
using namespace std;

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
           int n = arr.size();
           int mini = INT_MAX, minsum = 0;
           int maxi = INT_MIN, maxsum = 0;
           int total =0;
           for(int i:arr){
                total+=i;
                minsum+=i;
                maxsum+=i;
                mini = min(mini, minsum);
                maxi = max(maxi, maxsum);
                if(minsum>0){
                    minsum=0;
                }
                if(maxsum<0){
                    maxsum=0;
                }
           }
          if(maxi<0) return maxi;
          return max(maxi, total-mini);
    }
};

using vi=vector<int>;
using pii=pair<int,int>;
class Solution {
    pii kadaneCircular(vi &arr){
        int sum1=0,maxi=INT_MIN;
        int sum2=0,mini=INT_MAX;
        for(int &val: arr){
            sum1+=val;
            sum2+=val;
            maxi=max(maxi,sum1);
            mini=min(mini,sum2);
            if(sum1<0) sum1=0;
            if(sum2>0) sum2=0;
        }
        return {maxi,mini};
    }
  public:
    int maxCircularSum(vector<int> &arr) {
        int total=accumulate(arr.begin(),arr.end(),0);
        pii p=kadaneCircular(arr);
        int sum=p.first, circularSum=total-p.second;
        if(sum<0) return sum;
        return max(sum,circularSum);
    }
};

int main(){

return 0;
}