#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize) return false;
        
        int numGroups=0;
        map<int,int> hashMap;
        for(int &num: hand) 
            hashMap[num]++;
    
        for(auto &p: hashMap){
            int val=p.first,freq=p.second;
            while(freq){
                int group=0;
                while(group<groupSize){
                    if(hashMap[val+group]==0) 
                        return false;
                    hashMap[val+group]--;
                    group++;
                }
                numGroups++;
                freq--;
            }
        }
        return numGroups==(n/groupSize);
    }
};

int main(){

return 0;
}