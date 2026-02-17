#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool check(int mid,int d){
        int num=mid, sum=0;
        while(num){
            int d=num%10;
            sum+=d;
            num=num/10;
        }
        return (mid-sum)>=d;
    }
  public:
    int getCount(int n, int d) {
        // code here
        int low=1, high=n;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool resp=check(mid,d);
            if(resp){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return (ans? n-ans+1: 0);
    }
};

int main(){

return 0;
}