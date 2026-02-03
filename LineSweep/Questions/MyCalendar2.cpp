#include<iostream>
#include<vector>
#include<map>
using namespace std;

class MyCalendarTwo {
    map<int,int> events;
public:
    MyCalendarTwo() {
        events.clear();
    }
    
    bool book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;
        int count=0;
        for(auto &event: events){
            count+=event.second;
            if(count>2){
                // remove waste entry
                events[startTime]--;
                events[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

int main(){

return 0;
}