#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxValue(int n) {
        // code here
        int maxVal=0, consecutive1sCount=0;
        for(int i=30;i>=0;i--){
            bool bit=(n>>i) & 1;
            if(!bit) consecutive1sCount=0;
            else{
                consecutive1sCount++;
                if(consecutive1sCount==3) consecutive1sCount=0;
                else maxVal=maxVal|(1<<i);
            }
        }
        return maxVal;
    }
};

int main(){

return 0;
}