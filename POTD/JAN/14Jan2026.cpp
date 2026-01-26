#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool isInRange(int policeI,int thiefI,int k){
        return (thiefI>=policeI-k && thiefI<=policeI+k);
    }
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int thiefIndex=0, policeIndex=0, n=arr.size(), count=0;
        while(thiefIndex<n && policeIndex<n){
            while(arr[thiefIndex]=='P'){
                thiefIndex++;
                if(thiefIndex==n) return count;
            }
            while(arr[policeIndex]=='T'){
                policeIndex++;
                if(policeIndex==n) return count;
            }
            if(isInRange(policeIndex,thiefIndex,k)){
                count++;
                policeIndex++;
                thiefIndex++;
            }else{
                if(thiefIndex<policeIndex) thiefIndex++;
                else policeIndex++;
            }
        }
        return count;
    }
};

int main(){

return 0;
}