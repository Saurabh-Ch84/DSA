#include<iostream>
using namespace std;

// You are given a two-digit integer n. Return the sum of its digits.
// Example: For n = 29, the output should be: addTwoDigits(n) = 11.

int addTwoDigits(int n){
    int sum=0;
    while(n){
        int d=n%10;
        sum+=d;
        n=n/10;
    }
    return sum;
}

// Given a divisor and a bound, find the largest integer N such that:
// N is divisible by divisor.
// N is less than or equal to bound.
// N is greater than 0.
// It is guaranteed that such a number exists.

// Example:
//         For divisor = 3 and bound = 10, the output should be
//         maxMultiple(divisor, bound) = 9.
//         The largest integer divisible by 3 and not larger than 10 is 9.

int maxMultiple(int divisor,int bound){
    if(!divisor) return -1;
    int num=(bound/divisor)*divisor;
    return num;
}

// Your friend advised you to see a new performance in the most popular theater in the city.
// He knows a lot about art and his advice is usually good, but not this time: the performance
// turned out to be awfully dull. It's so bad you want to sneak out, which is quite simple,
// especially since the exit is located right behind your row to the left.
// All you need to do is climb over your seat and make your way to the exit.
// The main problem is your shyness: you're afraid that you'll end up
// blocking the view(even if only for a couple of seconds) of all the people who sit behind you
// and in your column or the columns to your left.To gain some courage, you decide to calculate
// the number of such people and see if you can possibly make it to the exit without disturbing too many people.

// PROBEM: Given the total number of rows and columns in the theater (nRows and nCols, respectively),
// and the row and column you're sitting in, return the number of people who sit strictly behind you
// and in your column or to the left, assuming all seats are occupied.

// Example:
//         For nCols = 16, nRows = 11, col = 5, and row = 3, the output should be
//         seatsInTheater(nCols, nRows, col, row) = 96.

int seatsInTheater(int nCols,int nRows,int col,int row){
    return (nCols-col+1)*(nRows-row);
}

int main(){
    cout<<addTwoDigits(12)<<endl;
    cout<<addTwoDigits(91)<<endl;
    cout<<addTwoDigits(38)<<endl;
    cout<<addTwoDigits(29)<<endl;

    cout<<maxMultiple(3,10)<<endl;
    cout<<seatsInTheater(16,11,5,3)<<endl;
return 0;
}