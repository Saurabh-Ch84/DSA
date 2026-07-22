#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<bool> possibleMod(k,0);
        for(int &num: arr){
            vector<bool> temp(k,0);
            temp[(num%k)]=1;
            for(int i=0;i<k;i++){
                if(possibleMod[i]){
                    temp[i]=1;
                    temp[(num+i)%k]=1;
                }
            }
            possibleMod=temp;
            if(possibleMod[0]) return true;
        }
        return false;
    }
};

int main(){

return 0;
}