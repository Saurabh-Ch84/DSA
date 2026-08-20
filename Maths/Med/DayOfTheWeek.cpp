#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isLeapYear(int year){
        return (year%400==0 || (year%4==0 && year%100!=0));
    }
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<int> monthDays={0,31,28,31,30,31,30,31,31,30,31,30,31};
        vector<string> days={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        int oddDays=(30)%7+isLeapYear(1971);
        for(int m=2;m<=12;m++)
            oddDays=(oddDays+monthDays[m])%7;
        for(int y=1972;y<year;y++)
            oddDays=(oddDays+(isLeapYear(y)? 2:1))%7;
        for(int m=1;m<month;m++){
            oddDays=(oddDays+monthDays[m]);
            if(m==2 && isLeapYear(year))
                oddDays=(oddDays+1)%7;
        }
        oddDays=(oddDays+day)%7;
        int ptr=5;
        return days[(ptr+oddDays)%7];
    }
};

int main(){


return 0;
}