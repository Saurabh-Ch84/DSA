#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> prefixSumDays={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int getDays(string date){
        int monthDays=prefixSumDays[stoi(date.substr(0,2))-1], day=stoi(date.substr(3,2));
        return monthDays+day;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int leftBound=max(getDays(arriveAlice),getDays(arriveBob));
        int rightBound=min(getDays(leaveAlice),getDays(leaveBob));
        return max(0,rightBound-leftBound+1);
    }
};

int main(){

return 0;
}