#include<iostream>
#include<vector>
using namespace std;
using vi = vector<int> ;
using vvi = vector<vi> ;

// You're travelling on a long straight road with many stoplights. You've travelled this road many times 
// before and you're very observant, so you're already aware of the location (in metres) and frequency
// (in seconds) of each stoplight, and you've stored these values in the array roadMap.

// As an example of how the data is stored, [15, 9] would represent a stoplight that's 15 metres away
// from your starting point, and its frequency is 9 seconds. In other words, the light will be green for 9 seconds,
// then red for another 9 seconds, then green again for another 9 seconds, etc.

// PROBLEM: Given the roadMap array, your task is to find how long it'll take for you reach the end of the road,
//          assuming you travel at exactly 1 metre per second.

// Notes:
//          You start at a position of 0, at time 0.
//          The timer stops the moment you're able to pass through the final stoplight in the list.
//          At time 0, all the stoplights have just turned green.
//          There's no one else on the road / no obstacles other than the stoplights to obstruct your path.
//          You travel at a constant rate(1 metre per second), so no time is spent accelerating or stopping;
//          the moment the light turns green, you start moving.
// Example:
//          For[[24, 7], [31,15], [50,41]], the output should be 82.
//          You start at position 0, so it takes 24 seconds to reach the first stoplight(which is 24 metres away).
//          This first stoplight has a frequency of 7, which means it's green at 0 seconds, it turns red at 7 seconds,
//          back to green at 14 seconds, then red again st 21 seconds, then it won't turn green again until 28 seconds.
//          Since you arrive at 24 seconds, you'll have to wait 4 seconds for the light to turn green again.
//
//          After the first light turns green, you travel another 7 metres to the seconds stoplight at position 31.
//          By this time, 35 seconds have passed, so the light is already green, and you don't have to stop
//          (this light has a frequency of 15, so it would have started green at 0, turned red at 15, then back
//          to green at 30, until 45, so at 35 seconds it's green).
//
//          You then travel another 19 metres to the final stoplight, which you arrive at after a total of 54 seconds.
//          Since this light has a frequency of 41, it would have turned red at 41 seconds, and will stay red
//          until 82 seconds have passed. After 82 seconds, you're able to make it through the last light,
//          so this is the final answer.
//
//          For [[23,23], [37,30]], the output should be 60.
//          You arrive at the first stoplight at the exact moment it turns red 😡. This means you'll have to wait
//          until another 23 seconds pass, so the time will be 46 by the time you can go.
//
//          After travelling another 14 metres, the time is now 60, which means the second stoplight will have
//          just turned green the instant you arrive at it (it was green until 30 seconds, then back to green right
//          at 60). So you can pass through this final stoplight after 60 seconds.

int timeToReach(vvi trafficLights) {
    int time = 0;
    int position = 0;
    
    for (auto& light : trafficLights) {
        int dest = light[0];
        int freq = light[1];
        // 1. Travel to the light
        int travelTime = dest - position;
        time += travelTime;
        position = dest;
        // 2. Check Cycle
        // Cycle Index k: Even = Green, Odd = Red
        int k = time / freq; 
        bool isRed = (k % 2 != 0); 
        if (isRed) {
            // If Red, we wait until the start of the NEXT interval (k+1)
            int nextGreenTime = (k + 1) * freq;
            time = nextGreenTime;
        }
    }
    return time;
}

int main(){
    vvi trafficLights1= {{24, 7}, {31,15}, {50,41}};
    vvi trafficLights2= {{23, 23}, {37,30}};
    cout<<timeToReach(trafficLights1)<<endl;
    cout<<timeToReach(trafficLights2)<<endl;
return 0;
}