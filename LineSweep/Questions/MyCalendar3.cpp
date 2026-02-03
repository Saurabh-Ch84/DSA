#include<iostream>
#include<vector>
#include<map>
using namespace std;

class MyCalendarThree {
    map<int,int> events;
public:
    MyCalendarThree() {
        events.clear();
    }
    
    int book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;
        int maxi=0, count=0;
        for(auto &event: events){
            count+=event.second;
            maxi=max(maxi,count);
        }
        return maxi;
    }
};

int main(){

return 0;
}