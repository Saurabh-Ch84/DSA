#include<iostream>
using namespace std;

// n children have got m pieces of candy. They want to eat as much candy as they can,
// but each child must eat exactly the same amount of candy as any other child.
// Determine how many pieces of candy will be eaten by all the children together.
// Individual pieces of candy cannot be split.

// Example:
//         For n = 3 and m = 10, the output should be
//         candies(n, m) = 9. Each child will eat 3 pieces.So the answer is 9.

int candies(int n, int m){
    int perChildCandy=m/n;
    return perChildCandy*n;
}

// One night you go for a ride on your motorcycle. At 00:00 you start your engine, and the built-in timer
// automatically begins counting the length of your ride, in minutes. Off you go to explore the neighborhood.
// When you finally decide to head back, you realize there's a chance the bridges on your route home are up,
// leaving you stranded! Unfortunately, you don't have your watch on you and don't know what time it is.
// All you know thanks to the bike's timer is that n minutes have passed since 00:00.

// PROBLEM: Using the bike's timer, calculate the current time. Return an answer as the sum of digits
//          that the digital timer in the format hh:mm would show.

// Example: For n = 240, the output should be
//          lateRide(n) = 4.
//          Since 240 minutes have passed, the current time is 04:00. The digits sum up to 0 + 4 + 0 + 0 = 4,
//          which is the answer.

//          For n = 808, the output should be
//          lateRide(n) = 14.
//          808 minutes mean that it's 13:28 now, so the answer should be 1 + 3 + 2 + 8 = 14

int digitSum(int num){
    int sum=0;
    while(num){
        int d=num%10;
        sum+=d;
        num=num/10;
    }
    return sum;
}

int lateRide(int n){
    int hours=n/60;
    int mins=n%60;
    int ans=digitSum(hours)+digitSum(mins);
    return ans;
}

int main(){
    cout<<candies(3,10)<<endl;
    cout<<candies(4,10)<<endl;
    cout<<candies(5,11)<<endl;

    cout<<lateRide(240)<<endl;
    cout<<lateRide(808)<<endl;
return 0;
}