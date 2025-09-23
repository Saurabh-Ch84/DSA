#include<iostream>
#include<math.h>
using namespace std;

// find unit digit
int unitnumber(int x, int y)
{
    // Get last digit of x
    x = x % 10;
      
    // Last cyclic modular value
    if(y!=0)
        y = y % 4 + 4;

    // here we simply return the 
    // unit digit or the power 
    // of a number
    return (((int)(pow(x, y))) % 10);
}

int main()
{
    int x = 133, y = 5;
    
    // get unit digit number here we pass 
    // the unit  digit of x and the last 
    // cyclicity number that is y%4
    cout << unitnumber(x, y);
 
    return 0;
}