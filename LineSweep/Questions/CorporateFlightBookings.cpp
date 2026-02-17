#include<iostream>
#include<vector>
using namespace std;

using vi=vector<int>;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vi result(n,0);
        for(vi &booking: bookings){
            int first=booking[0], last=booking[1];
            int seats=booking[2];
            result[first-1]+=seats;
            if(last<n) result[last]-=seats;
        }
        for(int i=1;i<n;i++)
            result[i]+=result[i-1];
        return result;
    }
};

int main(){

return 0;
}