#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using vi=vector<int>;
using vvi=vector<vi>;

class Solution {
public:
    bool carPooling(vvi &trips, int capacity) {
        vvi events;
        for(vi &trip: trips){
            events.push_back({trip[1],trip[0]});
            events.push_back({trip[2],-trip[0]});
        }
        sort(events.begin(),events.end());
        for(vi &event: events){
            capacity-=event[1];
            if(capacity<0) return false;
        }
        return true;
    }
};

int main(){

return 0;
}