#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isLeapYear(int year){
        return (year%400==0 || (year%4==0 && year%100!=0));
    }
    int daysInYear(int year){
        return 365+isLeapYear(year);
    }
    vector<int> parse(string date){
        vector<int> dateData;
        stringstream ss(date);
        string token;
        while(getline(ss,token,'-'))
            dateData.push_back(stoi(token));
        return dateData;
    }
    int totalDays(int year,int month,int day){
        vector<int> monthDays={0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(isLeapYear(year)) 
            monthDays[2]=29;
        int days=0;
        for(int y=1970;y<year;y++)
            days=days+daysInYear(y);
        for(int m=1;m<month;m++)
            days=days+monthDays[m];
        days=days+day;
        return days;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        vector<int> d1=parse(date1);
        vector<int> d2=parse(date2);
        int t1=totalDays(d1[0],d1[1],d1[2]), t2=totalDays(d2[0],d2[1],d2[2]);
        return abs(t1-t2);
    }
};

int main(){

return 0;
}