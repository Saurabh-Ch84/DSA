#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

class EventManager {
    unordered_map<int,int> hashMap;
    set<pair<int,int>> hashSet;
public:
    EventManager(vector<vector<int>>& events) {
        for(vector<int> &event: events){
            int eID=event[0], priority=event[1];
            hashMap[eID]=priority;
            hashSet.insert({priority,-eID});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int oldPriority=hashMap[eventId];
        hashSet.erase({oldPriority,-eventId});
        hashMap[eventId]=newPriority;
        hashSet.insert({newPriority,-eventId});
    }
    
    int pollHighest() {
        if(hashSet.empty()) return -1;
        pair<int,int> event=*hashSet.rbegin();
        hashSet.erase(event);
        hashMap.erase(-event.second);
        return -event.second;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */

int main(){

return 0;
}