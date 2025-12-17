#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int evenTotal=0,oddTotal=0,n=arr.size();
        for(int i=0;i<n;i++){
            if(i&1) oddTotal+=arr[i];
            else evenTotal+=arr[i];
        }
        
        int count=0;
        int prefixEven=0,prefixOdd=0;
        for(int i=0;i<n;i++){
            int num=arr[i];
            if(i&1) oddTotal-=num;
            else evenTotal-=num;
            if(prefixEven+oddTotal==prefixOdd+evenTotal)
                count++;
            if(i&1) prefixOdd+=num;
            else prefixEven+=num;
        }
        return count;
    }
};

int main(){

return 0;
}