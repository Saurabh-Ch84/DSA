#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> freqMap,needMap;
        
        for(int &ele: arr)
            freqMap[ele]++;
        
        for(int &ele: arr){
            if(freqMap[ele]==0) continue;
            if(needMap[ele]>0){
                needMap[ele]--;
                needMap[ele+1]++;
                freqMap[ele]--;
            }
            else{
                bool canStart=true;
                for(int i=0;i<k;i++){
                    if(freqMap[ele+i]<=0){
                        canStart=false;
                        break;
                    }
                }
                if(!canStart) return false;
                for(int i=0;i<k;i++) freqMap[ele+i]--;
                needMap[ele+k]++;
            }        
        }
        return true;
    }
};


int main(){

return 0;
}