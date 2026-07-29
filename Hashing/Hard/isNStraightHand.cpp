#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;

        sort(hand.begin(),hand.end());
        unordered_map<int,int> hashMap;
        for(int i=0;i<n;i++)
            hashMap[hand[i]]++;
            
        for(int i=0;i<n;i++){
            int curr=hand[i], prev=hand[i]-1;
            if(!hashMap.count(curr)) continue;
            int sz=0;
            while(sz<groupSize && hashMap.count(curr)){
                hashMap[curr]--;
                if(!hashMap[curr]) hashMap.erase(curr);
                curr++; sz++;
            }
            if(sz!=groupSize) return false;
        }
        return hashMap.empty();
    }
};

class Solution2 {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize) return false;
        
        int numberOfGroups=0;
        map<int,int> hashMap;
        for(int &num: hand) hashMap[num]++;
    
        for(auto &p: hashMap){
            int val=p.first,freq=p.second;
            while(freq){
                int sz=0;
                while(sz<groupSize){
                    if(hashMap[val+sz]==0) 
                        return false;
                    hashMap[val+sz]--;
                    sz++;
                }
                numberOfGroups++;
                freq--;
            }
        }
        return numberOfGroups==(n/groupSize);
    }
};

int main(){

return 0;
}