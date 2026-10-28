#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
    /*
                Problem: Design Underground System
    An underground railway system is tracking customer travel times between different stations to calculate 
    average travel times between any two stations.

    Implement the UndergroundSystem class:
        1. UndergroundSystem() Initializes the underground system object.
        2. void checkIn(int id, string stationName, int t)
            A customer with ID id checks in at station stationName at time t.
            A customer can only be checked into one station at a time.
        3. void checkOut(int id, string stationName, int t)
            A customer with ID id checks out from station stationName at time t.
        4. double getAverageTime(string startStation, string endStation)
            Returns the average time it takes to travel directly from startStation to endStation.
            The average time is computed from all previous direct trips between startStation and endStation.
        At least one customer will have completed a trip from startStation to endStation before getAverageTime is called.
    */
   unordered_map<int,pair<string,int>> passengerCheckInMap;
   unordered_map<string,unordered_map<string,pair<long long,int>>> averageMap;
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        passengerCheckInMap[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string stationName0=passengerCheckInMap[id].first;
        int t0=passengerCheckInMap[id].second, timeInterval=t-t0;
        averageMap[stationName0][stationName].first+=timeInterval;
        averageMap[stationName0][stationName].second++;
        passengerCheckInMap.erase(id); // optimization.
    }
    
    double getAverageTime(string startStation, string endStation) {
        return 1.0*averageMap[startStation][endStation].first/averageMap[startStation][endStation].second;
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
    UndergroundSystem* sys = new UndergroundSystem();
    sys->checkIn(45, "Leyton", 3);
    sys->checkIn(32, "Paradise", 8);
    sys->checkIn(27, "Leyton", 10);

    sys->checkOut(45, "Waterloo", 15);  // ID 45 traveled Leyton -> Waterloo in (15 - 3) = 12
    sys->checkOut(27, "Waterloo", 20);  // ID 27 traveled Leyton -> Waterloo in (20 - 10) = 10
    sys->checkOut(32, "Cambridge", 22); // ID 32 traveled Paradise -> Cambridge in (22 - 8) = 14

    cout<<sys->getAverageTime("Paradise", "Cambridge")<<endl; // Returns 14.0 (1 trip: 14)
    cout<<sys->getAverageTime("Leyton", "Waterloo")<<endl;    // Returns 11.0 (2 trips: 12 + 10 = 22 / 2)

    sys->checkIn(10, "Leyton", 24);
    cout<<sys->getAverageTime("Leyton", "Waterloo")<<endl;    // Still returns 11.0 (ID 10 hasn't checked out yet)

    sys->checkOut(10, "Waterloo", 38);  // ID 10 traveled Leyton -> Waterloo in (38 - 24) = 14
    cout<<sys->getAverageTime("Leyton", "Waterloo")<<endl;    // Returns 12.0 (3 trips: 12 + 10 + 14 = 36 / 3)
}