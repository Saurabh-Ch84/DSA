#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

// Optimized
class UndergroundSystem {
    using psi=pair<string,int>;
    using pdi=pair<double,int>;
    unordered_map<int,vector<psi>> idBasedCheckInEntry;
    map<pair<string,string>,pdi> stationBasedTimeEntry;
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        psi latestCheckIn={stationName,t};
        idBasedCheckInEntry[id].push_back(latestCheckIn);
    }
    
    void checkOut(int id, string stationName, int t) {
        psi lastCheckIn=idBasedCheckInEntry[id].back();
        string &prevStation=lastCheckIn.first;
        int t_=lastCheckIn.second;
        int time=t-t_;
        auto &lastEntry=stationBasedTimeEntry[{prevStation,stationName}];
        lastEntry.first+time,
        lastEntry.second+1;
        idBasedCheckInEntry[id].pop_back();
    }
    
    double getAverageTime(string startStation, string endStation) {
        pdi entry=stationBasedTimeEntry[{startStation,endStation}];
        double total=entry.first;
        int count=entry.second;
        return total/count;
    }
};

// Better
class UndergroundSystem {
    using entry=pair<string,int>;
    unordered_map<int,vector<entry>> idBasedCheckInEntry;
    map<pair<string,string>,vector<int>> stationBasedTimeEntry;
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        entry latestCheckIn={stationName,t};
        idBasedCheckInEntry[id].push_back(latestCheckIn);
    }
    
    void checkOut(int id, string stationName, int t) {
        entry lastCheckIn=idBasedCheckInEntry[id].back();
        string &prevStation=lastCheckIn.first;
        int t_=lastCheckIn.second;
        int time=t-t_;
        stationBasedTimeEntry[{prevStation,stationName}].push_back(time);
        idBasedCheckInEntry[id].pop_back();
    }
    
    double getAverageTime(string startStation, string endStation) {
        double total=0.0;
        vector<int> &times=stationBasedTimeEntry[{startStation,endStation}];
        for(int &time: times)
            total+=time;
        return total/times.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main(){

return 0;
}