#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution{
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int prefix=1,suffix=1,maxi=INT_MIN,n=arr.size();
        for(int i=0;i<n;i++){
            prefix=prefix*arr[i];
            suffix=suffix*arr[n-i-1];
            maxi=max({prefix,suffix,maxi});
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
        }
        return maxi;
    }
};

int main(){

return 0;
}