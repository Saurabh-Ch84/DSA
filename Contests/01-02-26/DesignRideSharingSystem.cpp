#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class RideSharingSystem {
    unordered_set<int> cancelledRider;
    queue<int> riderQueue, driverQueue;
public:
    RideSharingSystem(){}
    
    void addRider(int riderId) {
        if(cancelledRider.count(riderId))
            cancelledRider.erase(riderId);
        riderQueue.push(riderId);
    }
    
    void addDriver(int driverId) {
        driverQueue.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(driverQueue.empty()) return {-1,-1};
        while(!riderQueue.empty() && cancelledRider.count(riderQueue.front()))
            riderQueue.pop();
        if(riderQueue.empty()) return {-1,-1};
        int driver=driverQueue.front(); driverQueue.pop();
        int rider=riderQueue.front(); riderQueue.pop(); 
        return {driver,rider};
    }
    
    void cancelRider(int riderId) {
        cancelledRider.insert(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */

int main(){

return 0;
}