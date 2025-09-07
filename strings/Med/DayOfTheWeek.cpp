#include <iostream>
#include <vector>
using namespace std;

/*
    Reference Jan 1 1971 Friday
*/

class Solution {
    bool isLeapYear(int year){
        if(year%400==0) return true;
        return (year%4==0 && year%100!=0);
    }
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<int> monthDays = {31,28,31,30,31,30,31,31,30,31,30,31};
        vector<string> dayofweek = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int sum = 4;
        for (int i = 1971; i < year; ++i) {
            sum+=365;
            if(isLeapYear(i)) sum+=1;
        }
        for (int i = 1; i < month; ++i) {
            sum += monthDays[i-1];
            if(isLeapYear(year) && i==2) sum+=1;
        }
        sum += day;
        return dayofweek[sum % 7];
    }
};

int main() {
    Solution s;
    int day = 5, month = 9, year = 2025;
    cout << "Day of the week: " << s.dayOfTheWeek(day, month, year) << endl;
    return 0;
}
