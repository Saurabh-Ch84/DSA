#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Date{
        public:
    int year,month,day;
    Date(int y,int m,int d):year(y),month(m),day(d){}

    static Date dateParser(string date){
        stringstream ssD(date);
        string token;
        int arr[3]={0,0,0};
        int ptr=0;
        while(getline(ssD,token,'-'))
            arr[ptr++]=stoi(token);
        return Date(arr[0],arr[1],arr[2]);
    }
};

class Solution {
    bool isLeapYear(int year){
        if(year%400==0) return true;
        return (year%4==0 && year%100!=0);
    }

    int daysFrom1971(Date &d,const vector<int> &months){
        int days=0;
        for(int year=1971;year<d.year;year++){
            days+=365;
            if(isLeapYear(year)) days+=1;
        }
        for(int month=1;month<d.month;month++){
            days+=months[month-1];
            if(month==2 && isLeapYear(d.year)) days+=1;
        }
        days+=d.day;
        return days;
    }
    
public:
    int daysBetweenDates(string date1, string date2){
        const vector<int> months={31,28,31,30,31,30,31,31,30,31,30,31};
        Date d1=Date::dateParser(date1);
        Date d2=Date::dateParser(date2);
        return abs(daysFrom1971(d1,months)-daysFrom1971(d2,months));
    }
};

int main(){
    Solution s;
    cout<<s.daysBetweenDates("2002-12-18","2025-09-05")<<endl;
return 0;
}