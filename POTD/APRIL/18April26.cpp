#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int reverse(int n){
        int n_=0;
        while(n){
            int d=n%10;
            n=n/10;
            n_=n_*10+d;
        }
        return n_;
    }
public:
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};

class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int one=0, zero=0, ans=0;
        for(int &num: arr){
            if(!num) zero++;
            else{
                zero--;
                one++;
            }
            ans=max(ans,zero);
            zero=max(zero,0);
        }
        return ans+one;
    }
};

int main(){

return 0;
}