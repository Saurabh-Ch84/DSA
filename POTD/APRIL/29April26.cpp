#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n=arr.size(), count=0;
        for(int &num: arr){
            if(num) count++;
        }
        if(!count) return -1;
        int ones=0;
        for(int i=0;i<count-1;i++){
            if(arr[i]) ones++;
        }
        int right=count-1, left=0, mini=n;
        while(right<n){
            if(arr[right]) ones++;
            if(right-left+1>count){
                if(arr[left]) ones--;
                left++;
            }
            int swaps=count-ones;
            mini=min(mini,swaps);
            right++;
        }
        return (mini==n? -1: mini);
    }
};

int main(){

return 0;
}