#include<iostream>
#include<vector>
#include<set>
using namespace std;

class SeatManager {
    set<int> set_;
public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
            set_.insert(i);
    }
    
    int reserve(){
        auto itr=set_.begin();
        int firstUnreservedSeat=*itr;
        set_.erase(itr);
        return firstUnreservedSeat;
    }
    
    void unreserve(int seatNumber) {
        set_.insert(seatNumber);
    }
};

int main(){

return 0;
}