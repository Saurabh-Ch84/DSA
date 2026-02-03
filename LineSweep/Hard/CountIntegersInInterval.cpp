#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

using pii=pair<int,int>;
class CountIntervals {
    set<pii> events;
public:
    CountIntervals() {
        events.clear();
    }
    
    void add(int left, int right) {
        events.insert({left,right+1});
    }
    
    int count() {
        int sum=0, prev=0;
        for(auto &event: events){
            int curr=max(event.first,prev);
            if(event.second>curr)
                sum+=event.second-curr;
            prev=max(prev,event.second);
        }
        return sum;
    }
};

class CountIntervals {
    map<int,int> events;
public:
    CountIntervals() {
        events.clear();
    }
    
    void add(int left, int right) {
        events[left]++;
        events[right+1]--;
    }
    
    int count() {
        int sum=0, prev=0, overlap=0;
        for(auto &event: events){
            overlap+=event.second;
            if(event.second>=1 && prev==0)
                prev=event.first;
            else if(overlap==0 && prev){
                sum+=event.first-prev;
                prev=0;
            }
        }
        return sum;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

int main(){

return 0;
}