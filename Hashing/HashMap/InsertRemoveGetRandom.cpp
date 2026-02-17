#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class RandomizedSet {
    unordered_map<int,int> hashMap;
    vector<int> randVector;
public:
    RandomizedSet(){}
    
    bool insert(int val) {
        if(hashMap.count(val)) return false;
        randVector.push_back(val);
        int idx=randVector.size()-1;
        hashMap[val]=idx;
        return true;
    }
    
    bool remove(int val) {
        if(!hashMap.count(val)) return false;
        int idx=hashMap[val];
        int last=randVector.back();
        randVector[idx]=last;
        hashMap[last]=idx;
        randVector.pop_back();
        hashMap.erase(val);
        return true;
    }
    
    int getRandom(){
        int randIdx=rand()%randVector.size();
        return randVector[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){

return 0;
}