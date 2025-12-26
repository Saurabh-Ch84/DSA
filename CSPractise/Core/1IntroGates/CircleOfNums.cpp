#include<iostream>
using namespace std;

// Consider integer numbers from 0 to n - 1 written down along the circle in such a way that the distance
// between any two neighboring numbers is equal (note that 0 and n - 1 are neighboring, too).

// PROBLEM: Given n and firstNumber, find the number which is written in the radially opposite position to firstNumber.

// Example:
//         For n = 10 and firstNumber = 2, the output should be
//         circleOfNumbers(n, firstNumber) = 7.

int circleOfNums(int n,int firstNum){
    return (firstNum+n/2)%n;
}

// Given an integer n, return the largest number that contains exactly n digits.

// Example: For n = 2, the output should be: largestNumber(n) = 99.

int largestNumber(int n){
    int num=0;
    while(n){
        num=num*10+9;
        n--;
    }
    return num;
}

// Some phone usage rate may be described as follows:
// first minute of a call costs min1 cents,
// each minute from the 2nd up to 10th(inclusive) costs min2_10 cents
// each minute after 10th costs min11 cents.

// PROBLEM: You have s cents on your account before the call. What is the duration
//          of the longest call (in minutes rounded down to the nearest integer) you can have?

// Example: For min1 = 3, min2_10 = 1, min11 = 2, and s = 20, the output should be
//          phoneCall(min1, min2_10, min11, s) = 14.

// Here's why:
// the first minute costs 3 cents, which leaves you with 20 - 3 = 17 cents;
// the total cost of minutes 2 through 10 is 1 * 9 = 9, so you can talk 9 more minutes and still have 17 - 9 = 8 cents;
// each next minute costs 2 cents, which means that you can talk 8 / 2 = 4 more minutes.
// Thus, the longest call you can make is 1 + 9 + 4 = 14 minutes long.

int phoneCall(int min1,int min2_10, int min11,int s){
    int duration=0;
    if(s>=min1){
        duration+=1;
        s-=min1;
    }
    else return duration;
    if(s>=min2_10){
        int remMins=min(s/min2_10,9);
        duration+=remMins;
        s-=min2_10*remMins;
    }
    else return duration;
    if(s>=min11){
        int remMins=s/min11;
        duration+=remMins;
    }
    return duration;
}

int main(){
    cout<<circleOfNums(10,2)<<endl;
    cout<<largestNumber(2)<<endl;

    cout<<phoneCall(3,1,2,20)<<endl;
return 0;
}