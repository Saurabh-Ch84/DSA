#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int> ;
class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vi prefixY(n+1,0);
        for(int i=n-1;i>=0;i--)
            prefixY[i]=(customers[i]=='Y'? 1:0)+prefixY[i+1];
        
        int mini=n, minIdx=-1, countN=0;
        for(int i=0;i<=n;i++){
            int penality;
            if(i==n) penality=countN;
            else penality=prefixY[i]+countN;
            if(penality<mini){
                minIdx=i;
                mini=min(mini,penality);
            }
            if(i<n && customers[i]=='N') 
                countN++;
        }
        return minIdx;
    }
};

int main(){

return 0;
}